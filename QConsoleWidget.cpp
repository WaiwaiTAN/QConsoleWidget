#include "QConsoleWidget.h"
#include <QDebug>

QConsoleWidget::QConsoleWidget(QWidget *parent) : QPlainTextEdit(parent)
{
    connect(this, &QConsoleWidget::cursorPositionChanged, this, &QConsoleWidget::TextLock);
    connect(this, &QConsoleWidget::textChanged, this, &QConsoleWidget::GetCmd);
    PrintTip();
}

int QConsoleWidget::getCmdNum()
{
    return cmds.size();
}

QString QConsoleWidget::GetTipMsg()
{
    if (IPythonStyleTip)
        return "In[" + QString::number(cmds.size()+1) + "]: ";
    else
        return QString();
}

void QConsoleWidget::PrintTip()
{
    moveCursor(QTextCursor::End);
    insertPlainText(GetTipMsg());
}

QConsoleWidget::int_type QConsoleWidget::overflow(int_type v)
{
    if (v == '\n')
    {
        appendPlainText("");
    }
    return v;
}

std::streamsize QConsoleWidget::xsputn(const char *p, std::streamsize n)
{
        QString str(p);
        if(str.contains("\n"))
        {
            QStringList strSplitted = str.split("\n");

            moveCursor(QTextCursor::End);
            insertPlainText (strSplitted.at(0)); //Index 0 is still on the same old line

            for(int i = 1; i < strSplitted.size(); i++)
            {
                appendPlainText(strSplitted.at(i));
            }
        }else
        {
            moveCursor (QTextCursor::End);
            insertPlainText (str);
        }
        return n;
}

void QConsoleWidget::TextLock()
{
    setReadOnly(textCursor().position() < toPlainText().lastIndexOf(GetTipMsg()) + GetTipMsg().size());
}

void QConsoleWidget::GetCmd()
{
    if(toPlainText().back() == '\n')
    {
        if (toPlainText().contains(GetTipMsg()))
        {
            QStringList strSplitted = toPlainText().split(GetTipMsg());

            cmds << strSplitted.at(1);
            emit cmdInput(strSplitted.at(1));
        }
    }
}
