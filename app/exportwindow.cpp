/***********************************************************************

                             D A S M   8 0 8 0
                              NOVEMBER, 2021
                            COPYRIGHT (C) 2021

 FILE: exportwindow.cpp
 MODIFIED: November, 2021
 COMMENT:
 LICENSE: GNU General Public License v3.0

***********************************************************************/


#include "exportwindow.h"
#include "ui_exportwindow.h"


ExportWindow::ExportWindow(QWidget *parent): QDialog(parent), ui(new Ui::ExportWindow)
{
    ui->setupUi(this);
}

ExportWindow::~ExportWindow()
{
    delete ui;
}
