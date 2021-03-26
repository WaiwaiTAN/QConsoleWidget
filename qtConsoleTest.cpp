#include "qtConsoleTest.h"

qtConsoleTest::qtConsoleTest(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.console->ensureCursorVisible();
    connect(ui.console, &QConsoleWidget::cmdInput, this, &qtConsoleTest::echo);
    connect(this, &qtConsoleTest::cmdProssed, ui.console, &QConsoleWidget::PrintTip);
}
