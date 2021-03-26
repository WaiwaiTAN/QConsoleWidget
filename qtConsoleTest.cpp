#include "qtConsoleTest.h"

qtConsoleTest::qtConsoleTest(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    qout = new std::ostream(ui.console);
    connect(ui.console, &QConsoleWidget::cmdInput, this, &qtConsoleTest::echo);
    connect(this, &qtConsoleTest::cmdProssed, ui.console, &QConsoleWidget::PrintTip);
}
