#include "client.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Client client("127.0.0.1", quint16(52417));
    client.show();
    return a.exec();
}
