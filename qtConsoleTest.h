#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_qtConsole.h"

class qtConsoleTest : public QMainWindow
{
    Q_OBJECT

public:
    qtConsoleTest(QWidget *parent = Q_NULLPTR);


    Ui::qtConsoleClass ui;
private:
    std::ostream *qout;

signals:
    void cmdProssed();

private slots:
	void printHello()
	{
        *qout << "hello from my own ostream object" << std::endl;
        ui.console->appendPlainText("\nhello appended");
	}

    void printAll()
    {
        ui.textEdit->setText(ui.console->tmpstr);
    }

    void echo(QString cmd)
    {
        *qout << cmd.toStdString();
        emit cmdProssed();
    }
};
