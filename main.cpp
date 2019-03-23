#include "libclient.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LibClient w;
    w.show();

    return a.exec();
}
