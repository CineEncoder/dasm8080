#ifndef MESSAGEWINDOW_H
#define MESSAGEWINDOW_H

#include <QDialog>


namespace Ui {
    class MessageWindow;
}

class MessageWindow : public QDialog
{
    Q_OBJECT

public:

    explicit MessageWindow(QWidget *parent = nullptr);

    ~MessageWindow();

    void setMessage(const QString &message);

private slots:
    void on_buttonApply_clicked();

private:

    Ui::MessageWindow *ui;
};

#endif // MESSAGEWINDOW_H
