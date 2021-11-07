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
    QFileDialog *openFilesWindow = new QFileDialog(nullptr);
    openFilesWindow->setFileMode(QFileDialog::ExistingFile);
#ifdef Q_OS_WIN
    openFilesWindow->setOptions(QFileDialog::DontResolveSymlinks);
#endif
    //openFilesWindow->setOptions(QFileDialog::DontUseNativeDialog | QFileDialog::DontResolveSymlinks);
    openFilesWindow->setOptions(QFileDialog::DontResolveSymlinks);
    openFilesWindow->setDirectory(QDir::homePath());
    openFilesWindow->setMinimumWidth(600);
    openFilesWindow->setWindowTitle("Open File");
    openFilesWindow->setNameFilter(tr("Bin Files: *.rom, *.bin (*.rom *.bin);;All files (*.*)"));
    openFilesWindow->setWindowFlags(Qt::Dialog | Qt::SubWindow);
    openFilesWindow->exec();
    int res = openFilesWindow->result();
    const QStringList filePaths = openFilesWindow->selectedFiles();
    delete openFilesWindow;
    if (res == 1) {
        selectedFilePath = filePaths.at(0);
        ui->lineEdit->setText(selectedFilePath);
    } else if (res != 1 && res != 0) {
        selectedFilePath = "";
        ui->lineEdit->setText(selectedFilePath);
        showMessage(tr("Incorrect file."));
    }
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
