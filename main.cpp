#include "qtConsoleTest.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qtConsoleTest w;
    w.show();
    return a.exec();
}
