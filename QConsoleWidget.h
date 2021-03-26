#pragma once
#include <qplaintextedit.h>
#include <QString>
#include <iostream>
class QConsoleWidget :
	public QPlainTextEdit, public std::basic_streambuf<char>
{
	Q_OBJECT

public:
	explicit QConsoleWidget(QWidget* parent = 0);
    QString tmpstr = "default";
    int getCmdNum();

private:
    QStringList cmds;
    QString GetTipMsg();
    bool IPythonStyleTip = true;

private slots:
    void TextLock();
    void GetCmd();

public slots:
    void PrintTip();

protected:
    virtual int_type __CLR_OR_THIS_CALL overflow(int_type v = std::char_traits<char>::eof());
    virtual std::streamsize xsputn(const char *p, std::streamsize n);

signals:
    void cmdInput(QString cmd);
};

