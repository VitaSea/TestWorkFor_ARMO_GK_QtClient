/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Client
{
public:
    QWidget *centralwidget;
    QTextEdit *textEditMain;
    QPushButton *pushButtonSend;
    QTextBrowser *textBrowserFileInfo;
    QTextBrowser *textBrowserConnectionStatus;
    QPushButton *pushButtonOpenImage;
    QLabel *labelAttachmentFilePrewiev;
    QPushButton *pushButtonOpenAudio;
    QPushButton *pushButtonOpenVideo;
    QPushButton *pushButtonOpenOther;
    QTextBrowser *textBrowserMessages;
    QPushButton *pushButtonConnect;
    QMenuBar *menubar;

    void setupUi(QMainWindow *Client)
    {
        if (Client->objectName().isEmpty())
            Client->setObjectName(QString::fromUtf8("Client"));
        Client->resize(636, 467);
        QFont font;
        font.setPointSize(12);
        Client->setFont(font);
        centralwidget = new QWidget(Client);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textEditMain = new QTextEdit(centralwidget);
        textEditMain->setObjectName(QString::fromUtf8("textEditMain"));
        textEditMain->setGeometry(QRect(310, 330, 321, 71));
        textEditMain->setLayoutDirection(Qt::LeftToRight);
        textEditMain->setAutoFillBackground(false);
        pushButtonSend = new QPushButton(centralwidget);
        pushButtonSend->setObjectName(QString::fromUtf8("pushButtonSend"));
        pushButtonSend->setGeometry(QRect(311, 410, 131, 33));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setUnderline(false);
        font1.setWeight(75);
        font1.setKerning(true);
        pushButtonSend->setFont(font1);
        textBrowserFileInfo = new QTextBrowser(centralwidget);
        textBrowserFileInfo->setObjectName(QString::fromUtf8("textBrowserFileInfo"));
        textBrowserFileInfo->setEnabled(true);
        textBrowserFileInfo->setGeometry(QRect(10, 160, 291, 61));
        textBrowserFileInfo->setFont(font);
        textBrowserConnectionStatus = new QTextBrowser(centralwidget);
        textBrowserConnectionStatus->setObjectName(QString::fromUtf8("textBrowserConnectionStatus"));
        textBrowserConnectionStatus->setEnabled(true);
        textBrowserConnectionStatus->setGeometry(QRect(450, 410, 181, 31));
        QFont font2;
        font2.setPointSize(8);
        font2.setBold(true);
        font2.setWeight(75);
        textBrowserConnectionStatus->setFont(font2);
        pushButtonOpenImage = new QPushButton(centralwidget);
        pushButtonOpenImage->setObjectName(QString::fromUtf8("pushButtonOpenImage"));
        pushButtonOpenImage->setGeometry(QRect(10, 0, 292, 33));
        pushButtonOpenImage->setFont(font1);
        labelAttachmentFilePrewiev = new QLabel(centralwidget);
        labelAttachmentFilePrewiev->setObjectName(QString::fromUtf8("labelAttachmentFilePrewiev"));
        labelAttachmentFilePrewiev->setGeometry(QRect(10, 230, 291, 211));
        QFont font3;
        font3.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font3.setPointSize(10);
        labelAttachmentFilePrewiev->setFont(font3);
        labelAttachmentFilePrewiev->setContextMenuPolicy(Qt::DefaultContextMenu);
        labelAttachmentFilePrewiev->setFrameShape(QFrame::Box);
        pushButtonOpenAudio = new QPushButton(centralwidget);
        pushButtonOpenAudio->setObjectName(QString::fromUtf8("pushButtonOpenAudio"));
        pushButtonOpenAudio->setGeometry(QRect(11, 40, 291, 33));
        pushButtonOpenAudio->setFont(font1);
        pushButtonOpenVideo = new QPushButton(centralwidget);
        pushButtonOpenVideo->setObjectName(QString::fromUtf8("pushButtonOpenVideo"));
        pushButtonOpenVideo->setGeometry(QRect(11, 80, 291, 33));
        pushButtonOpenVideo->setFont(font1);
        pushButtonOpenOther = new QPushButton(centralwidget);
        pushButtonOpenOther->setObjectName(QString::fromUtf8("pushButtonOpenOther"));
        pushButtonOpenOther->setGeometry(QRect(11, 120, 291, 33));
        pushButtonOpenOther->setFont(font1);
        textBrowserMessages = new QTextBrowser(centralwidget);
        textBrowserMessages->setObjectName(QString::fromUtf8("textBrowserMessages"));
        textBrowserMessages->setGeometry(QRect(310, 40, 321, 281));
        textBrowserMessages->setContextMenuPolicy(Qt::DefaultContextMenu);
        textBrowserMessages->setFrameShape(QFrame::Box);
        textBrowserMessages->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        textBrowserMessages->setOverwriteMode(false);
        pushButtonConnect = new QPushButton(centralwidget);
        pushButtonConnect->setObjectName(QString::fromUtf8("pushButtonConnect"));
        pushButtonConnect->setGeometry(QRect(330, 0, 292, 33));
        pushButtonConnect->setFont(font1);
        Client->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Client);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 636, 20));
        Client->setMenuBar(menubar);

        retranslateUi(Client);

        QMetaObject::connectSlotsByName(Client);
    } // setupUi

    void retranslateUi(QMainWindow *Client)
    {
        Client->setWindowTitle(QCoreApplication::translate("Client", "MyClient", nullptr));
        textEditMain->setHtml(QCoreApplication::translate("Client", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        pushButtonSend->setText(QCoreApplication::translate("Client", "\320\276\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214", nullptr));
        textBrowserConnectionStatus->setHtml(QCoreApplication::translate("Client", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:600; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:400;\">\321\201\321\202\320\260\321\202\321\203\321\201: \320\276\321\204\321\204\320\273\320\260\320\271\320\275</span></p></body></html>", nullptr));
        pushButtonOpenImage->setText(QCoreApplication::translate("Client", "\320\277\321\200\320\270\320\272\321\200\320\265\320\277\320\270\321\202\321\214 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265", nullptr));
        labelAttachmentFilePrewiev->setText(QString());
        pushButtonOpenAudio->setText(QCoreApplication::translate("Client", "\320\277\321\200\320\270\320\272\321\200\320\265\320\277\320\270\321\202\321\214 \320\260\321\203\320\264\320\270\320\276", nullptr));
        pushButtonOpenVideo->setText(QCoreApplication::translate("Client", "\320\277\321\200\320\270\320\272\321\200\320\265\320\277\320\270\321\202\321\214 \320\262\320\270\320\264\320\265\320\276", nullptr));
        pushButtonOpenOther->setText(QCoreApplication::translate("Client", "\320\277\321\200\320\270\320\272\321\200\320\265\320\277\320\270\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        pushButtonConnect->setText(QCoreApplication::translate("Client", "\320\277\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214\321\201\321\217 \320\272 \321\201\320\265\321\200\320\262\320\265\321\200\321\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Client: public Ui_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
