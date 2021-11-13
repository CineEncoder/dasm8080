/***********************************************************************

                             D A S M   8 0 8 0
                              NOVEMBER, 2021
                            COPYRIGHT (C) 2021

 FILE: importwindow.cpp
 MODIFIED: November, 2021
 COMMENT:
 LICENSE: GNU General Public License v3.0

***********************************************************************/

#include "importwindow.h"
#include "ui_importwindow.h"
#include "messagewindow.h"


ImportWindow::ImportWindow(QWidget *parent): QDialog(parent), ui(new Ui::ImportWindow)
{
    ui->setupUi(this);
}

ImportWindow::~ImportWindow()
{
    delete ui;
}

void ImportWindow::setParams(QString *filePath, bool *acceptFlag, int *offset)
{
    _acceptFlag = acceptFlag;
    _filePath = filePath;
    _offset = offset;
    selectedFilePath = "";
}

void ImportWindow::on_buttonSelectFile_clicked()
{
    selectedFilePath = "";
    QFileDialog openFilesWindow(nullptr);
    openFilesWindow.setWindowTitle("Open File");
    openFilesWindow.setMinimumWidth(600);
    openFilesWindow.setWindowFlags(Qt::Dialog | Qt::SubWindow);
#if defined (Q_OS_UNIX)
    openFilesWindow->setOptions(QFileDialog::DontUseNativeDialog);
#endif
    openFilesWindow.setOptions(QFileDialog::DontResolveSymlinks);
    openFilesWindow.setAcceptMode(QFileDialog::AcceptOpen);
    openFilesWindow.setFileMode(QFileDialog::ExistingFile);
    openFilesWindow.setDirectory(QDir::homePath());
    openFilesWindow.setNameFilter(tr("Bin Files: *.rom, *.bin (*.rom *.bin);;All files (*.*)"));
    if (openFilesWindow.exec() != QFileDialog::Accepted) {
        return;
    }
    selectedFilePath = openFilesWindow.selectedFiles().at(0);
    ui->lineEdit->setText(selectedFilePath);
}

void ImportWindow::on_buttonApply_clicked()
{
    if (selectedFilePath != "") {
        *_acceptFlag = true;
        *_filePath = selectedFilePath;
        *_offset = ui->spinBox->value();
    }
    this->close();
}

void ImportWindow::showMessage(const QString message)
{
    MessageWindow msgWindow(this);
    msgWindow.setMessage(message);
    msgWindow.setModal(true);
    msgWindow.exec();
}
