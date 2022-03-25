#include "client.h"
#include "ui_client.h"

Client::Client(const QString& ip_address, const quint16& port, QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::Client),
      ip_address(ip_address),
      port(port)
{
    ui->setupUi(this);
    tcp_socket       = new QTcpSocket(this);
    file             = nullptr;
    is_connection_ok = false;

    connect(ui->pushButtonOpenImage, &QPushButton::clicked,     this, &Client::ButtonOpenImage);
    connect(ui->pushButtonOpenAudio, &QPushButton::clicked,     this, &Client::ButtonOpenAudio);
    connect(ui->pushButtonOpenVideo, &QPushButton::clicked,     this, &Client::ButtonOpenVideo);
    connect(ui->pushButtonOpenOther, &QPushButton::clicked,     this, &Client::ButtonOpenOther);
    connect(ui->pushButtonSend,      &QPushButton::clicked,     this, &Client::ButtonSend);
    connect(ui->pushButtonConnect,   &QPushButton::clicked,     this, &Client::ButtonConnect);
    connect(tcp_socket,              &QTcpSocket::connected,    this, &Client::Connected);
    connect(tcp_socket,              &QTcpSocket::disconnected, this, &Client::Disconnected);
}

void Client::ButtonConnect()
{
    if(is_connection_ok) tcp_socket->disconnectFromHost();
    else tcp_socket->connectToHost(ip_address, port);
}

void Client::ButtonSend()
{
    if(is_connection_ok)
    {
        constexpr quint16 file_info_part_size = 64;
        QString str_message = ui->textEditMain->toPlainText();

        if(!str_message.isEmpty())
            ui->textBrowserMessages->append("Отправлено сообщение: " + str_message);

        if(tcp_socket)
        {
            if(tcp_socket->isOpen())
            {
                QDataStream socket_stream(tcp_socket);
                socket_stream.setVersion(QDataStream::Qt_5_14);

                if(!str_message.isEmpty()) // Если сообщение содержит текст
                {
                    QByteArray byteArray = str_message.toUtf8();
                    QByteArray arr_message_info; // Для записи информации о файле

                    arr_message_info.prepend(QString("message_type:message,file_name:null,file_size:%1;").arg(str_message.size()).toUtf8());
                    arr_message_info.resize(file_info_part_size); // Расширяем до (file_info_part_size = 64) байт для корректного считывания на стороне сервера
                    byteArray.prepend(arr_message_info);    // Записываем в начало буффера информацию о файле
                    socket_stream << byteArray;             // Отправляем сообщение с информацией на сервер
                }

                if(!file_info.absoluteFilePath().isEmpty()) // Если к сообщению прикреплён файл
                {
                    file = new QFile(file_info.absoluteFilePath());
                    if(file->open(QIODevice::ReadOnly))
                    {
                        QDataStream socket_stream(tcp_socket);
                        socket_stream.setVersion(QDataStream::Qt_5_14);

                        QString str_file_type;
                        switch (file_type)  // Определяем тип прикреплённого файла
                        {
                            case FileType::IMAGE: str_file_type = "image"; break;
                            case FileType::AUDIO: str_file_type = "audio"; break;
                            case FileType::VIDEO: str_file_type = "video"; break;
                            case FileType::OTHER: str_file_type = "other"; break;
                        }

                        QByteArray arr_data_info; // Для записи информации о файле
                        arr_data_info.prepend(QString("message_type:%1,file_name:%2,file_size:%3;").arg(str_file_type).arg(file_info.fileName()).arg(file->size()).toUtf8());

                        // Расширяем до (file_info_part_size = 64)...
                        arr_data_info.resize(file_info_part_size);

                        QByteArray arr_data_file;               // Для записи файла
                        arr_data_file = file->readAll();        // Заполняем буффер прикреплённым файлом
                        arr_data_file.prepend(arr_data_info);   // Записываем в начало буффера информацию о файле
                        socket_stream << arr_data_file;         // Отправляем файл с информацией на сервер
                        file->close();
                    }
                    delete file;
                    file = nullptr;
                }
            }
        }
        str_message.clear();
        file_info = QFileInfo();
        ui->textBrowserFileInfo->clear();
        ui->labelAttachmentFilePrewiev->clear();
        ui->textEditMain->clear();
    }
    else // !is_connection_ok
    {
        if(!ui->textEditMain->toPlainText().isEmpty())
            ui->textBrowserMessages->append("Ошибка отправки: Нет соединения с сервером.");
    }
}


void Client::ButtonOpenImage()
{
    file_info = QFileDialog::getOpenFileName(this, "Прикрепить файл изображения", "files", "Изображения (*.png *.jpg *.bmp *.tif *.tiff *.psd *.gif *.jpeg)");
    file = new QFile(file_info.absolutePath());
    ui->textBrowserFileInfo->append("Имя файла: " + file_info.baseName()+"."+file_info.suffix() + "\nРазмер: " + QString::number(file_info.size()) + " байт.");
    QPixmap pixmap = QPixmap::fromImage(QImage(file_info.absoluteFilePath()));
    const int& w = ui->labelAttachmentFilePrewiev->width();
    const int& h = ui->labelAttachmentFilePrewiev->height();
    ui->labelAttachmentFilePrewiev->setPixmap(pixmap.scaled(w,h,Qt::KeepAspectRatio));
    file_type = FileType::IMAGE;
}

void Client::ButtonOpenAudio()
{
    file_info = QFileDialog::getOpenFileName(this, "Прикрепить аудио файл", "files", "Аудио (*.mp3 *.wav *.aiff *.ape *.flac *.ogg)");
    file = new QFile(file_info.absolutePath());
    ui->textBrowserFileInfo->setText("Имя файла: " + file_info.baseName()+"."+file_info.suffix() + "\nРазмер: " + QString::number(file_info.size()) + " байт.");
    file_type = FileType::AUDIO;
}

void Client::ButtonOpenVideo()
{
    file_info = QFileDialog::getOpenFileName(this, "Прикрепить видео файл", "files", "Видео (*.avi *.mov *.wmv *.mkv *.mp4 *.mpeg *.flv *.f4v *.swf *.webm)");
    file = new QFile(file_info.absolutePath());
    ui->textBrowserFileInfo->setText("Имя файла: " + file_info.baseName()+"."+file_info.suffix() + "\nРазмер: " + QString::number(file_info.size()) + " байт.");
    file_type = FileType::VIDEO;
}

void Client::ButtonOpenOther()
{
    file_info = QFileDialog::getOpenFileName(this, "Прикрепить любой файл", "files", "Файл (*.*)");
    file = new QFile(file_info.absolutePath());
    ui->textBrowserFileInfo->setText("Имя файла: " + file_info.fileName() + "\nРазмер: " + QString::number(file_info.size()) + " байт.");
    file_type = FileType::OTHER;
}

void Client::Connected()
{
    is_connection_ok = true;
    ui->textBrowserConnectionStatus->setText("статус: онлайн");
    ui->pushButtonConnect->setText("отключиться от сервера");
}

void Client::Disconnected()
{
    is_connection_ok = false;
    tcp_socket->close();
    ui->textBrowserConnectionStatus->setText("статус: оффлайн");
    ui->pushButtonConnect->setText("подключиться к серверу");
}

Client::~Client()
{
    delete tcp_socket;
    delete file;
    delete ui;
}

