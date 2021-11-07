#ifndef IMPORTWINDOW_H
#define IMPORTWINDOW_H

#include <QDialog>
#include <QFileDialog>


namespace Ui {
    class ImportWindow;
}

class ImportWindow : public QDialog
{
    Q_OBJECT

public:

    explicit ImportWindow(QWidget *parent = nullptr);

    ~ImportWindow();

    void setParams(QString *filePath, bool *acceptFlag, int *offset);

private slots:

    void on_buttonSelectFile_clicked();

    void on_buttonApply_clicked();

private:

    Ui::ImportWindow *ui;

    QString selectedFilePath;

    QString *_filePath;

    bool *_acceptFlag;

    int *_offset;

    void showMessage(const QString message);

};

#endif // IMPORTWINDOW_H
