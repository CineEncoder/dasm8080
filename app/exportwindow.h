#ifndef EXPORTWINDOW_H
#define EXPORTWINDOW_H

#include <QDialog>

namespace Ui {
    class ExportWindow;
}

class ExportWindow : public QDialog
{
    Q_OBJECT

public:

    explicit ExportWindow(QWidget *parent = nullptr);

    ~ExportWindow();

private:

    Ui::ExportWindow *ui;
};

#endif // EXPORTWINDOW_H
