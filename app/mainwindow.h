#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include <QScrollBar>
#include <QFileDialog>
#include <QDataStream>
#include <QKeyEvent>
#include <QMap>
#include <iostream>
#include <math.h>

typedef struct table {
    unsigned char hex = 0;
    QString hex_type = "";
    int label = -1;
    QString command = "";
    int command_data = -1;
} table;

typedef  QMap<int, table> IntStructMap;
typedef  QMap<unsigned char, unsigned char> UCharMap;
typedef  QMap<unsigned char, int> UCharIntMap;
typedef  QMap<unsigned char, QString> UCharStringMap;
typedef  QMap<QString, QString> StringStringMap;
typedef  QMap<int, unsigned char> IntUCharMap;

typedef  QPair<int, table> IntStructPair;
typedef  QPair<int, unsigned char> IntUCharPair;

typedef  QMap<int, table>::iterator IntStructIterator;
typedef  QMap<QString, QString>::iterator StringIterator;
typedef  QMap<int, unsigned char>::iterator IntUCharIterator;

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

    friend QDataStream& (operator<<)(QDataStream &out, table &str);

    friend QDataStream& (operator>>)(QDataStream &in, table &str);

private slots:

    void showEvent(QShowEvent *event);

    void on_pushButton_Import_clicked();

    void on_pushButton_Export_clicked();

    void on_pushButton_PrevRef_clicked();

    void on_pushButton_NextRef_clicked();

    void keyPressEvent(QKeyEvent* event);

    void onItemEntered(QTableWidgetItem *item);

    void onSlideBarValueChanged(int value);

    void on_tableWidget_visual_cellClicked(int row, int column);

private:

    Ui::MainWindow *ui;

    static const int _VIS_ROW_COUNT = 200;

    enum Columns {
      ADDR, HEX, TYPE, LABEL, COMMAND, DATA, CHAR,
      B7, B6, B5, B4, B3, B2, B1, B0
    };

    int offset;

    int undefRowsCount;

    int possibleRefsCount;

    int errors;

    QString _inputFile;

    QString _inputFolder;

    bool _windowActivated = false;

    IntStructMap tableMap;

    IntStructMap undoTableMap;

    IntStructMap redoTableMap;

    StringStringMap equMap;

    UCharIntMap sizeOfCmd;

    UCharStringMap hexToCmd;

    QAction *convToCmd;

    QAction *convToData;

    QAction *convSelToData;

    QAction *resetToUndef;

    QAction *addLabelAction;

    QAction *removeLabelAction;

    QMenu *itemMenu;

    QMenu *labelMenu;

    void on_actionUndo_clicked();

    void on_actionRedo_clicked();

    void on_actionSaveProject_clicked();

    void on_actionLoadProject_clicked();

    void importFile();

    void exportFile();

    void readFile(const QString &filePath);

    void recognizeBlock(int addr);

    void followToRefs(int addr, int commandSize);

    bool searchKey(int &addr);

    int convertHexToCmd(int addr);

    void convertHexToData(int addr);

    void addLabel();

    void removeLabel();

    void clearLabels();

    void redefineLabels();

    bool checkForRefs(int addr);

    bool findJumpCommands(QString cmd);

    bool findCallCommands(QString cmd);

    bool findDataCommands(QString cmd);

    bool findLxiCommands(QString cmd);

    void convertBlockToCommands();

    void convertRowsToData();

    void convertRowToData();

    void convertBlockToUndef();

    void updateTableWidget();

    void setInfo();

    void provideContextMenu(const QPoint &position);

    void makeUndoStatus();

    bool getBit(unsigned char byte, int position);

    template <typename Num>
    QString convertNumToHexString(Num n, int width);

    void showMessage(const QString message);

};

#endif // MAINWINDOW_H
