/***********************************************************************

                             D A S M   8 0 8 0
                              NOVEMBER, 2021
                            COPYRIGHT (C) 2021

 FILE: messagewindow.cpp
 MODIFIED: November, 2021
 COMMENT:
 LICENSE: GNU General Public License v3.0

***********************************************************************/

#include "messagewindow.h"
#include "ui_messagewindow.h"


MessageWindow::MessageWindow(QWidget *parent): QDialog(parent), ui(new Ui::MessageWindow)
{
    ui->setupUi(this);
}

MessageWindow::~MessageWindow()
{
    delete ui;
}

void MessageWindow::setMessage(const QString &message)
{
    ui->textBrowser->clear();
    ui->textBrowser->setAlignment(Qt::AlignCenter);
    ui->textBrowser->append(message);
    QTextCursor textCursor = ui->textBrowser->textCursor();
    textCursor.movePosition(QTextCursor::Start);
    ui->textBrowser->setTextCursor(textCursor);
}

void MessageWindow::on_buttonApply_clicked()
{
    this->close();
}
