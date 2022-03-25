#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDataStream>
#include <QMessageBox>
#include <QFile>
#include <QFileInfo>
#include <QFileDialog>
#include <QIODevice>

QT_BEGIN_NAMESPACE
namespace Ui { class Client; }
QT_END_NAMESPACE

enum class FileType
{
    IMAGE,
    AUDIO,
    VIDEO,
    OTHER
};

class Client : public QMainWindow
{
    Q_OBJECT

public:

    Client(const QString& ip_address, const quint16& port, QWidget *parent = nullptr);
    ~Client();

private:

    Ui::Client *ui;
    QTcpSocket* tcp_socket;
    QFile* file;
    QFileInfo file_info;
    FileType file_type;
    QString ip_address;
    quint16 port;
    bool is_connection_ok;

private slots:

    void ButtonSend();
    void ButtonOpenImage();
    void ButtonOpenAudio();
    void ButtonOpenVideo();
    void ButtonOpenOther();
    void ButtonConnect();
    void Connected();
    void Disconnected();
};
#endif // CLIENT_H
