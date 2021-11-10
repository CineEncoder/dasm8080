/***********************************************************************

                             D A S M   8 0 8 0
                              NOVEMBER, 2021
                            COPYRIGHT (C) 2021

 FILE: mainwindow.cpp
 MODIFIED: November, 2021
 COMMENT:
 LICENSE: GNU General Public License v3.0

***********************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "importwindow.h"
#include "exportwindow.h"
#include "messagewindow.h"


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/***************************************
** Initialization
***************************************/

void MainWindow::showEvent(QShowEvent *event)   /*** Call set parameters ***/
{
    QMainWindow::showEvent(event);
    if (_windowActivated == false) {
        _windowActivated = true;

        sizeOfCmd = {
            {0x00, 1}, {0x01, 3}, {0x02, 1}, {0x03, 1}, {0x04, 1}, {0x05, 1}, {0x06, 2}, {0x07, 1},
            {0x08, 1}, {0x09, 1}, {0x0a, 1}, {0x0b, 1}, {0x0c, 1}, {0x0d, 1}, {0x0e, 2}, {0x0f, 1},
            {0x10, 1}, {0x11, 3}, {0x12, 1}, {0x13, 1}, {0x14, 1}, {0x15, 1}, {0x16, 2}, {0x17, 1},
            {0x18, 1}, {0x19, 1}, {0x1a, 1}, {0x1b, 1}, {0x1c, 1}, {0x1d, 1}, {0x1e, 2}, {0x1f, 1},
            {0x20, 1}, {0x21, 3}, {0x22, 3}, {0x23, 1}, {0x24, 1}, {0x25, 1}, {0x26, 2}, {0x27, 1},
            {0x28, 1}, {0x29, 1}, {0x2a, 3}, {0x2b, 1}, {0x2c, 1}, {0x2d, 1}, {0x2e, 2}, {0x2f, 1},
            {0x30, 1}, {0x31, 3}, {0x32, 3}, {0x33, 1}, {0x34, 1}, {0x35, 1}, {0x36, 2}, {0x37, 1},
            {0x38, 1}, {0x39, 1}, {0x3a, 3}, {0x3b, 1}, {0x3c, 1}, {0x3d, 1}, {0x3e, 2}, {0x3f, 1},
            {0x40, 1}, {0x41, 1}, {0x42, 1}, {0x43, 1}, {0x44, 1}, {0x45, 1}, {0x46, 1}, {0x47, 1},
            {0x48, 1}, {0x49, 1}, {0x4a, 1}, {0x4b, 1}, {0x4c, 1}, {0x4d, 1}, {0x4e, 1}, {0x4f, 1},
            {0x50, 1}, {0x51, 1}, {0x52, 1}, {0x53, 1}, {0x54, 1}, {0x55, 1}, {0x56, 1}, {0x57, 1},
            {0x58, 1}, {0x59, 1}, {0x5a, 1}, {0x5b, 1}, {0x5c, 1}, {0x5d, 1}, {0x5e, 1}, {0x5f, 1},
            {0x60, 1}, {0x61, 1}, {0x62, 1}, {0x63, 1}, {0x64, 1}, {0x65, 1}, {0x66, 1}, {0x67, 1},
            {0x68, 1}, {0x69, 1}, {0x6a, 1}, {0x6b, 1}, {0x6c, 1}, {0x6d, 1}, {0x6e, 1}, {0x6f, 1},
            {0x70, 1}, {0x71, 1}, {0x72, 1}, {0x73, 1}, {0x74, 1}, {0x75, 1}, {0x76, 1}, {0x77, 1},
            {0x78, 1}, {0x79, 1}, {0x7a, 1}, {0x7b, 1}, {0x7c, 1}, {0x7d, 1}, {0x7e, 1}, {0x7f, 1},
            {0x80, 1}, {0x81, 1}, {0x82, 1}, {0x83, 1}, {0x84, 1}, {0x85, 1}, {0x86, 1}, {0x87, 1},
            {0x88, 1}, {0x89, 1}, {0x8a, 1}, {0x8b, 1}, {0x8c, 1}, {0x8d, 1}, {0x8e, 1}, {0x8f, 1},
            {0x90, 1}, {0x91, 1}, {0x92, 1}, {0x93, 1}, {0x94, 1}, {0x95, 1}, {0x96, 1}, {0x97, 1},
            {0x98, 1}, {0x99, 1}, {0x9a, 1}, {0x9b, 1}, {0x9c, 1}, {0x9d, 1}, {0x9e, 1}, {0x9f, 1},
            {0xa0, 1}, {0xa1, 1}, {0xa2, 1}, {0xa3, 1}, {0xa4, 1}, {0xa5, 1}, {0xa6, 1}, {0xa7, 1},
            {0xa8, 1}, {0xa9, 1}, {0xaa, 1}, {0xab, 1}, {0xac, 1}, {0xad, 1}, {0xae, 1}, {0xaf, 1},
            {0xb0, 1}, {0xb1, 1}, {0xb2, 1}, {0xb3, 1}, {0xb4, 1}, {0xb5, 1}, {0xb6, 1}, {0xb7, 1},
            {0xb8, 1}, {0xb9, 1}, {0xba, 1}, {0xbb, 1}, {0xbc, 1}, {0xbd, 1}, {0xbe, 1}, {0xbf, 1},
            {0xc0, 1}, {0xc1, 1}, {0xc2, 3}, {0xc3, 3}, {0xc4, 3}, {0xc5, 1}, {0xc6, 2}, {0xc7, 1},
            {0xc8, 1}, {0xc9, 1}, {0xca, 3}, {0xcb, 1}, {0xcc, 3}, {0xcd, 3}, {0xce, 2}, {0xcf, 1},
            {0xd0, 1}, {0xd1, 1}, {0xd2, 3}, {0xd3, 2}, {0xd4, 3}, {0xd5, 1}, {0xd6, 2}, {0xd7, 1},
            {0xd8, 1}, {0xd9, 1}, {0xda, 3}, {0xdb, 2}, {0xdc, 3}, {0xdd, 1}, {0xde, 2}, {0xdf, 1},
            {0xe0, 1}, {0xe1, 1}, {0xe2, 3}, {0xe3, 1}, {0xe4, 3}, {0xe5, 1}, {0xe6, 2}, {0xe7, 1},
            {0xe8, 1}, {0xe9, 1}, {0xea, 3}, {0xeb, 1}, {0xec, 3}, {0xed, 1}, {0xee, 2}, {0xef, 1},
            {0xf0, 1}, {0xf1, 1}, {0xf2, 3}, {0xf3, 1}, {0xf4, 3}, {0xf5, 1}, {0xf6, 2}, {0xf7, 1},
            {0xf8, 1}, {0xf9, 1}, {0xfa, 3}, {0xfb, 1}, {0xfc, 3}, {0xfd, 1}, {0xfe, 2}, {0xff, 1}
        };

        hexToCmd = {
            {0x00, "NOP"},      {0x01, "LXI B,"},   {0x02, "STAX B"},   {0x03, "INX B"},    {0x04, "INR B"},    {0x05, "DCR B"},
            {0x06, "MVI B,"},   {0x07, "RLC"},	    {0x08, "NOP_0x08_UNDOC"},{0x09, "DAD B"},{0x0a, "LDAX B"},  {0x0b, "DCX B"},
            {0x0c, "INR C"},    {0x0d, "DCR C"},    {0x0e, "MVI C,"},   {0x0f, "RRC"},      {0x10, "NOP_0x10_UNDOC"},{0x11, "LXI D,"},
            {0x12, "STAX D"},   {0x13, "INX D"},    {0x14, "INR D"},    {0x15, "DCR D"},    {0x16, "MVI D,"},   {0x17, "RAL"},
            {0x18, "NOP_0x18_UNDOC"},{0x19, "DAD D"},{0x1a, "LDAX D"},  {0x1b, "DCX D"},    {0x1c, "INR E"},	{0x1d, "DCR E"},
            {0x1e, "MVI E,"},   {0x1f, "RAR"},      {0x20, "NOP_0x20_UNDOC"},{0x21, "LXI H,"},{0x22, "SHLD"},   {0x23, "INX H"},
            {0x24, "INR H"},    {0x25, "DCR H"},    {0x26, "MVI H,"},   {0x27, "DAA"},      {0x28, "NOP_0x28_UNDOC"},{0x29, "DAD H"},
            {0x2a, "LHLD"},     {0x2b, "DCX H"},    {0x2c, "INR L"},    {0x2d, "DCR L"},    {0x2e, "MVI L,"},   {0x2f, "CMA"},
            {0x30, "NOP_0x30_UNDOC"},{0x31, "LXI SP,"},{0x32, "STA"},   {0x33, "INX SP"},   {0x34, "INR M"},    {0x35, "DCR M"},
            {0x36, "MVI M,"},   {0x37, "STC"}, 	    {0x38, "NOP_0x38_UNDOC"},{0x39, "DAD SP"},{0x3a, "LDA"},    {0x3b, "DCX SP"},
            {0x3c, "INR A"},    {0x3d, "DCR A"},    {0x3e, "MVI A,"},   {0x3f, "CMC"},      {0x40, "MOV B, B"}, {0x41, "MOV B, C"},
            {0x42, "MOV B, D"}, {0x43, "MOV B, E"}, {0x44, "MOV B, H"}, {0x45, "MOV B, L"}, {0x46, "MOV B, M"}, {0x47, "MOV B, A"},
            {0x48, "MOV C, B"}, {0x49, "MOV C, C"}, {0x4a, "MOV C, D"}, {0x4b, "MOV C, E"}, {0x4c, "MOV C, H"}, {0x4d, "MOV C, L"},
            {0x4e, "MOV C, M"}, {0x4f, "MOV C, A"},	{0x50, "MOV D, B"}, {0x51, "MOV D, C"}, {0x52, "MOV D, D"}, {0x53, "MOV D, E"},
            {0x54, "MOV D, H"}, {0x55, "MOV D, L"}, {0x56, "MOV D, M"}, {0x57, "MOV D, A"},	{0x58, "MOV E, B"}, {0x59, "MOV E, C"},
            {0x5a, "MOV E, D"}, {0x5b, "MOV E, E"},	{0x5c, "MOV E, H"}, {0x5d, "MOV E, L"}, {0x5e, "MOV E, M"}, {0x5f, "MOV E, A"},
            {0x60, "MOV H, B"}, {0x61, "MOV H, C"}, {0x62, "MOV H, D"}, {0x63, "MOV H, E"}, {0x64, "MOV H, H"}, {0x65, "MOV H, L"},
            {0x66, "MOV H, M"}, {0x67, "MOV H, A"}, {0x68, "MOV L, B"}, {0x69, "MOV L, C"}, {0x6a, "MOV L, D"}, {0x6b, "MOV L, E"},
            {0x6c, "MOV L, H"}, {0x6d, "MOV L, L"}, {0x6e, "MOV L, M"}, {0x6f, "MOV L, A"}, {0x70, "MOV M, B"}, {0x71, "MOV M, C"},
            {0x72, "MOV M, D"}, {0x73, "MOV M, E"}, {0x74, "MOV M, H"}, {0x75, "MOV M, L"}, {0x76, "HLT"},      {0x77, "MOV M, A"},
            {0x78, "MOV A, B"}, {0x79, "MOV A, C"}, {0x7a, "MOV A, D"}, {0x7b, "MOV A, E"}, {0x7c, "MOV A, H"},	{0x7d, "MOV A, L"},
            {0x7e, "MOV A, M"}, {0x7f, "MOV A, A"}, {0x80, "ADD B"},    {0x81, "ADD C"},    {0x82, "ADD D"},    {0x83, "ADD E"},
            {0x84, "ADD H"},    {0x85, "ADD L"},    {0x86, "ADD M"},    {0x87, "ADD A"},    {0x88, "ADC B"},    {0x89, "ADC C"},
            {0x8a, "ADC D"},    {0x8b, "ADC E"},    {0x8c, "ADC H"},    {0x8d, "ADC L"},    {0x8e, "ADC M"},    {0x8f, "ADC A"},
            {0x90, "SUB B"},    {0x91, "SUB C"},    {0x92, "SUB D"},    {0x93, "SUB E"},    {0x94, "SUB H"},    {0x95, "SUB L"},
            {0x96, "SUB M"},    {0x97, "SUB A"},    {0x98, "SBB B"},	{0x99, "SBB C"},    {0x9a, "SBB D"},    {0x9b, "SBB E"},
            {0x9c, "SBB H"},    {0x9d, "SBB L"},    {0x9e, "SBB M"},    {0x9f, "SBB A"},    {0xa0, "ANA B"},    {0xa1, "ANA C"},
            {0xa2, "ANA D"},    {0xa3, "ANA E"},    {0xa4, "ANA H"},	{0xa5, "ANA L"},    {0xa6, "ANA M"},    {0xa7, "ANA A"},
            {0xa8, "XRA B"},	{0xa9, "XRA C"},    {0xaa, "XRA D"},    {0xab, "XRA E"},    {0xac, "XRA H"},	{0xad, "XRA L"},
            {0xae, "XRA M"},    {0xaf, "XRA A"},    {0xb0, "ORA B"},    {0xb1, "ORA C"},    {0xb2, "ORA D"},    {0xb3, "ORA E"},
            {0xb4, "ORA H"},	{0xb5, "ORA L"},    {0xb6, "ORA M"},    {0xb7, "ORA A"},    {0xb8, "CMP B"},	{0xb9, "CMP C"},
            {0xba, "CMP D"},    {0xbb, "CMP E"},    {0xbc, "CMP H"}, 	{0xbd, "CMP L"},    {0xbe, "CMP M"},    {0xbf, "CMP A"},
            {0xc0, "RNZ"},      {0xc1, "POP B"},	{0xc2, "JNZ"},		{0xc3, "JMP"},		{0xc4, "CNZ"},		{0xc5, "PUSH B"},
            {0xc6, "ADI"},		{0xc7, "RST 0"},	{0xc8, "RZ"},		{0xc9, "RET"},		{0xca, "JZ"},		{0xcb, "JMP_0xcb_UNDOC"},
            {0xcc, "CZ"},		{0xcd, "CALL"},		{0xce, "ACI"},		{0xcf, "RST 1"},	{0xd0, "RNC"},		{0xd1, "POP D"},
            {0xd2, "JNC"},		{0xd3, "OUT"},		{0xd4, "CNC"},		{0xd5, "PUSH D"},	{0xd6, "SUI"},		{0xd7, "RST 2"},
            {0xd8, "RC"},		{0xd9, "RET_0xd9_UNDOC"},{0xda, "JC"},	{0xdb, "IN"},		{0xdc, "CC"},		{0xdd, "CALL_0xdd_UNDOC"},
            {0xde, "SBI"},		{0xdf, "RST 3"},	{0xe0, "RPO"},		{0xe1, "POP H"},	{0xe2, "JPO"},		{0xe3, "XTHL"},
            {0xe4, "CPO"},		{0xe5, "PUSH H"},	{0xe6, "ANI"},		{0xe7, "RST 4"},	{0xe8, "RPE"},		{0xe9, "PCHL"},
            {0xea, "JPE"},		{0xeb, "XCHG"},		{0xec, "CPE"},		{0xed, "CALL_0xed_UNDOC"},{0xee, "XRI"},{0xef, "RST 5"},
            {0xf0, "RP"},		{0xf1, "POP PSW"},	{0xf2, "JP"},		{0xf3, "DI"},		{0xf4, "CP"},		{0xf5, "PUSH PSW"},
            {0xf6, "ORI"},		{0xf7, "RST 6"},	{0xf8, "RM"},		{0xf9, "SPHL"},		{0xfa, "JM"},		{0xfb, "EI"},
            {0xfc, "CM"},		{0xfd, "CALL_0xfd_UNDOC"},{0xfe, "CPI"},{0xff, "RST 7"}
        };

        ui->actionUndo->setEnabled(false);
        ui->actionRedo->setEnabled(false);
        connect(ui->actionImport, &QAction::triggered, this, &MainWindow::importFile);
        connect(ui->actionExport, &QAction::triggered, this, &MainWindow::exportFile);
        //connect(ui->actionSave_project_as, &QAction::triggered, this, &MainWindow::on_actionSaveProject_clicked);
        //connect(ui->actionLoad_project, &QAction::triggered, this, &MainWindow::on_actionLoadProject_clicked);
        connect(ui->actionRedo, &QAction::triggered, this, &MainWindow::on_actionRedo_clicked);
        connect(ui->actionUndo, &QAction::triggered, this, &MainWindow::on_actionUndo_clicked);
        connect(ui->tableWidget, &QTableWidget::customContextMenuRequested, this, &MainWindow::provideContextMenu);
        connect(ui->tableWidget, SIGNAL(itemEntered(QTableWidgetItem*)), this, SLOT(onItemEntered(QTableWidgetItem*)));
        connect(ui->tableWidget->verticalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(onSlideBarValueChanged(int)));

        ui->tableWidget->setMouseTracking(true);
        ui->tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
        ui->tableWidget->setToolTipDuration(100);
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->horizontalHeader()->setVisible(true);
        ui->tableWidget->setAlternatingRowColors(false);
        ui->tableWidget->verticalHeader()->setVisible(false);
        ui->tableWidget->verticalHeader()->setFixedWidth(0);
        ui->tableWidget->verticalHeader()->setMinimumSectionSize(18);
        ui->tableWidget->verticalHeader()->setDefaultSectionSize(18);
        ui->tableWidget->setColumnWidth(Columns::ADDR, 50);
        ui->tableWidget->setColumnWidth(Columns::HEX, 30);
        ui->tableWidget->setColumnWidth(Columns::TYPE, 40);
        ui->tableWidget->setColumnWidth(Columns::LABEL, 120);
        ui->tableWidget->setColumnWidth(Columns::COMMAND, 70);
        ui->tableWidget->setColumnWidth(Columns::DATA, 120);
        ui->tableWidget->setColumnWidth(Columns::CHAR, 60);
        for (int i = Columns::B7; i <= Columns::B0; i++) {
            ui->tableWidget->setColumnWidth(i, 18);
        }

        QHeaderView *header = ui->tableWidget_visual->verticalHeader();
        header->setSectionResizeMode(QHeaderView::Stretch);
        ui->tableWidget_visual->setRowCount(_VIS_ROW_COUNT);
        for (int row = 0; row < _VIS_ROW_COUNT; row++ ) {
            QTableWidgetItem *item = new QTableWidgetItem(QString(""));
            item->setFlags(item->flags() & ~Qt::ItemIsEditable);
            ui->tableWidget_visual->setItem(row, 0, item);
        }

        QFile file;
        QString list("");
        file.setFileName(":/resources/css/style_0.css");
        if (file.open(QFile::ReadOnly)) {
            list = QString::fromUtf8(file.readAll());
            file.close();
        }
        this->setStyleSheet(list);
        offset = 0x0100;
        undefRowsCount = 0;
        possibleRefsCount = 0;
        errors = 0;
        _inputFile = "untitled.bin";
        _inputFolder = QDir::homePath();
        convToCmd = new QAction(tr("Convert to commands"), this);
        convToData = new QAction(tr("Convert to data"), this);
        convSelToData = new QAction(tr("Convert selected to data"), this);
        resetToUndef = new QAction(tr("Reset to undefined"), this);
        addLabelAction = new QAction(tr("Add label"), this);
        removeLabelAction = new QAction(tr("Remove label"), this);
        connect(convToCmd, &QAction::triggered, this, &MainWindow::convertBlockToCommands);
        connect(convToData, &QAction::triggered, this, &MainWindow::convertRowsToData);
        connect(convSelToData, &QAction::triggered, this, &MainWindow::convertRowToData);
        connect(resetToUndef, &QAction::triggered, this, &MainWindow::convertBlockToUndef);
        connect(addLabelAction, &QAction::triggered, this, &MainWindow::addLabel);
        connect(removeLabelAction, &QAction::triggered, this, &MainWindow::removeLabel);

        itemMenu = new QMenu(this);
        itemMenu->addAction(convToCmd);
        itemMenu->addSeparator();
        itemMenu->addAction(convToData);
        itemMenu->addAction(convSelToData);
        itemMenu->addSeparator();
        itemMenu->addAction(resetToUndef);

        labelMenu = new QMenu(this);
        labelMenu->addAction(addLabelAction);
        labelMenu->addSeparator();
        labelMenu->addAction(removeLabelAction);
    }
}

/***************************************
** Main menu
***************************************/

void MainWindow::on_pushButton_Import_clicked()
{
    importFile();
}

void MainWindow::on_pushButton_Export_clicked()
{
    exportFile();
}

void MainWindow::on_actionSaveProject_clicked()
{
    /*QString filename = QString("C:/Users/User/Downloads/Vector-06C/untitled.dasm");
    QFile savedFile(filename);
    if (savedFile.open(QIODevice::WriteOnly)) {
        QDataStream out(&savedFile);
        QDataStream& operator<<(QDataStream &, const table &);
        QDataStream& operator>>(QDataStream &, const table &);
        out.setVersion(QDataStream::Qt_4_0);
        out << tableMap;
    }*/
}

void MainWindow::on_actionLoadProject_clicked()
{
    /*QString filename = QString("C:/Users/User/Downloads/Vector-06C/untitled.dasm");
    QFile loadedFile(filename);
    if (loadedFile.open(QIODevice::ReadOnly)) {
        tableMap.clear();
        QDataStream in(&loadedFile);
        in.setVersion(QDataStream::Qt_4_0);
        in >> tableMap;
    }*/
}

void MainWindow::on_actionUndo_clicked()
{
    if (ui->actionUndo->isEnabled()) {
        redoTableMap.clear();
        redoTableMap = tableMap;
        redoTableMap.detach();

        tableMap.clear();
        tableMap = undoTableMap;
        tableMap.detach();

        updateTableWidget();
        ui->actionUndo->setEnabled(false);
        ui->actionRedo->setEnabled(true);
    }
}

void MainWindow::on_actionRedo_clicked()
{
    if (ui->actionRedo->isEnabled()) {
        undoTableMap.clear();
        undoTableMap = tableMap;
        undoTableMap.detach();

        tableMap.clear();
        tableMap = redoTableMap;
        tableMap.detach();

        updateTableWidget();
        ui->actionUndo->setEnabled(true);
        ui->actionRedo->setEnabled(false);
    }
}

void MainWindow::on_pushButton_PrevRef_clicked()
{
    int rowCount = ui->tableWidget->rowCount();
    if (rowCount > 0) {
        int currRow = ui->tableWidget->currentRow();
        if (currRow != -1) {
            for (int ind = 1; ind <= currRow; ind++) {
                int row = currRow - ind;
                if (row != -1) {
                    QString hexType = ui->tableWidget->item(row, 3)->text();
                    if (hexType == "???") {
                        ui->tableWidget->selectRow(row);
                        break;
                    }
                }
            }
        }
        else {
            for (int row = 0; row < rowCount; row++) {
                QString hexType = ui->tableWidget->item(row, 3)->text();
                if (hexType == "???") {
                    ui->tableWidget->selectRow(row);
                    break;
                }
            }
        }
    }
}

void MainWindow::on_pushButton_NextRef_clicked()
{
    int rowCount = ui->tableWidget->rowCount();
    if (rowCount > 0) {
        int currRow = ui->tableWidget->currentRow();
        if (currRow != -1) {
            for (int row = currRow + 1; row < rowCount; row++) {
                QString hexType = ui->tableWidget->item(row, 3)->text();
                if (hexType == "???") {
                    ui->tableWidget->selectRow(row);
                    break;
                }
            }
        }
        else {
            for (int ind = 0; ind < rowCount; ind++) {
                int row = rowCount - 1 - ind;
                QString hexType = ui->tableWidget->item(row, 3)->text();
                if (hexType == "???") {
                    ui->tableWidget->selectRow(row);
                    break;
                }
            }
        }
    }
}

void MainWindow::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Z && (event->modifiers() & Qt::ControlModifier)) {
        on_actionUndo_clicked();
    } else if (event->key() == Qt::Key_Y && (event->modifiers() & Qt::ControlModifier)) {
        on_actionRedo_clicked();
    }
}

void MainWindow::importFile()  /*** Call dialog ***/
{
    bool acceptFlag = false;
    QString filePath("");
    ImportWindow import(this);
    import.setParams(&filePath, &acceptFlag, &offset);
    import.setModal(true);
    import.exec();
    if (acceptFlag) {
        readFile(filePath);
    }
}

void MainWindow::exportFile()
{
    QString outFilePath("");
    int rowCount = ui->tableWidget->rowCount();
    if (undefRowsCount == 0 && errors == 0 && rowCount > 0) {
        QFileDialog saveFileWindow(nullptr);
    #if defined (Q_OS_UNIX)
        saveFileWindow.setOptions(QFileDialog::DontUseNativeDialog);
    #endif
        saveFileWindow.setMinimumWidth(600);
        saveFileWindow.setOptions(QFileDialog::DontResolveSymlinks);
        saveFileWindow.setAcceptMode(QFileDialog::AcceptSave);
        saveFileWindow.setDirectory(_inputFolder);
        saveFileWindow.selectFile(QString("untitled.asm"));
        saveFileWindow.setWindowTitle("Save File");
        saveFileWindow.setNameFilter("Asm file (*.asm)");
        if (saveFileWindow.exec() != QFileDialog::AcceptSave) {
            return;
        }
        outFilePath = saveFileWindow.selectedFiles().at(0);
        QFile out_file(outFilePath);
        if (out_file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QString line("");
            int fileSize = tableMap.size();
            line += QString(";***********************************************************************\n"
                            ";                               ASM FILE\n"
                            ";	                     BIN TO ASM, VERSION 1.0\n"
                            ";  CPU: 8080\n"
                            ";  SOURCE: %1\n"
                            ";  START: %2, END: %3, SIZE: %4 Bytes\n"
                            ";***********************************************************************\n\n\n")
                            .arg(_inputFile, convertNumToHexString(offset, 4),
                                 convertNumToHexString(fileSize + offset - 1, 4), QString::number(fileSize));
            line += QString("\tORG %1\n").arg(convertNumToHexString(offset, 4));
            int row = 0;
            int rowCount = ui->tableWidget->rowCount();
            while (row < rowCount) {
                QString command = ui->tableWidget->item(row, Columns::COMMAND)->text();
                if (command != "") {
                    QString label = ui->tableWidget->item(row, Columns::LABEL)->text();
                    QString data = ui->tableWidget->item(row, Columns::DATA)->text();
                    QString label_block("");
                    QString data_block("");
                    if (label != "") {
                        label_block = label + QString("\n");
                    }
                    if (data != "") {
                        data_block = QString(" ") + data;
                    }
                    line += label_block + QString("\t") + command + data_block;
                    if (command == "DB") {
                        int next_row = row + 1;
                        int end_row = next_row + 7;
                        while (next_row < end_row) {
                            if (next_row < rowCount) {
                                QString next_command = ui->tableWidget->item(next_row, Columns::COMMAND)->text();
                                QString next_label = ui->tableWidget->item(next_row, Columns::LABEL)->text();
                                if (next_command == "DB" && next_label == "") {
                                    line += QString(", ") + convertNumToHexString(tableMap[next_row+offset].hex, 2);
                                    next_row++;
                                } else {
                                    break;
                                }
                            } else {
                                break;
                            }
                        }
                        row = next_row - 1;
                    }
                    line += QString("\n");


                    if (command == "RET" || command == "JMP" || command == "PCHL" || command.indexOf("RST") != -1) {
                        line += QString("\n;=================== Block ======================\n\n");
                    }
                }
                row++;
            }
            line += QString("\tEND\n");

            out_file.write(line.toUtf8());
            out_file.close();
            showMessage(tr("File saved!"));
        } else {
            showMessage(tr("Can`t save file!"));
        }
    }
    else if (rowCount == 0) {
        showMessage(tr("Import file first!"));
    }
    else {
        showMessage(tr("Recognition is not complete yet.\n\nUndefined rows: %1\nErrors: %2")
                    .arg(QString::number(undefRowsCount), QString::number(errors)));
    }
}

void MainWindow::readFile(const QString &filePath)    /*** Read file ***/
{
    equMap.clear();
    tableMap.clear();
    undefRowsCount = 0;
    possibleRefsCount = 0;
    errors = 0;

    std::wstring filePath_wstr = filePath.toStdWString();
    std::wstring::size_type separator = filePath_wstr.rfind('/');
    if (separator == std::wstring::npos) {
        showMessage(tr("Unexpected error while trying to perform file name detection."));
        return;
    }
    _inputFile = QString::fromStdWString(filePath_wstr.substr(separator + 1));
    _inputFolder = QString::fromStdWString(filePath_wstr.substr(0, separator));

    QFile in_file(filePath);
    if (in_file.exists() && in_file.size() <= 65536) {
        if (in_file.open(QIODevice::ReadOnly)) {
            QByteArray hex_bytes = in_file.readAll();
            int fsize = hex_bytes.size();
            for (int pos = 0; pos < fsize; pos++)	{
                tableMap[pos + offset].hex = static_cast<unsigned char>(hex_bytes.at(pos));
            }
            int addr = offset;
            recognizeBlock(addr);
            updateTableWidget();
        }

    } else {
        showMessage(tr("The file exceeds the allowed size or does not exist."));
    }
}

/***************************************
** Disassembler
***************************************/

void MainWindow::recognizeBlock(int addr)
{
    int tab_size = tableMap.size();
    while (addr < tab_size + offset) {
        int commandSize = convertHexToCmd(addr);
        QString cmd = tableMap[addr].command;
        followToRefs(addr, commandSize);
        if (cmd == "JMP" || cmd == "RET" || cmd == "PCHL" || cmd.indexOf("RST") != -1) {
            break;
        }
        addr += commandSize;
    }
}

void MainWindow::followToRefs(int addr, int commandSize)
{
    if (commandSize == 3) {
        int dest_addr = tableMap[addr].command_data;
        if (searchKey(dest_addr)) {
            QString cmd = tableMap[addr].command;
            if (findJumpCommands(cmd) || findCallCommands(cmd)) {
                if (tableMap[dest_addr].label == -1) {
                    tableMap[dest_addr].label = dest_addr;
                }
                if (tableMap[dest_addr].hex_type == "" || tableMap[dest_addr].hex_type == "???") {
                    recognizeBlock(dest_addr);
                }
            }
            else if (findDataCommands(cmd)) {
                if (tableMap[dest_addr].label == -1) {
                    tableMap[dest_addr].label = dest_addr;
                }
                if (tableMap[dest_addr].hex_type == "" || tableMap[dest_addr].hex_type == ". . .") {
                    convertHexToData(dest_addr);
                }
            }
            else if (findLxiCommands(cmd)) {
                if (tableMap[dest_addr].hex_type == "") {
                    tableMap[dest_addr].hex_type = "???";
                }
            }
        }
    }
}

bool MainWindow::searchKey(int &addr)
{
    IntStructIterator it_cmd = tableMap.find(addr);
    if (it_cmd != tableMap.end()) {
        return true;
    }
    return false;
}

int MainWindow::convertHexToCmd(int addr) {
    unsigned char currByte = tableMap[addr].hex;
    tableMap[addr].command = hexToCmd[currByte];
    tableMap[addr].hex_type = QString("cmd");
    int commandSize = sizeOfCmd[currByte];
    if (commandSize == 2) {
        tableMap[addr].command_data = (int)tableMap[addr + 1].hex;
        tableMap[addr + 1].hex_type = QString(". . .");
        tableMap[addr + 1].command = "";
        tableMap[addr + 1].command_data = -1;
    }
    else if (commandSize == 3) {
        tableMap[addr].command_data = 256 * (int)tableMap[addr + 2].hex + (int)tableMap[addr + 1].hex;
        tableMap[addr + 1].hex_type = QString(". . .");
        tableMap[addr + 1].command = "";
        tableMap[addr + 1].command_data = -1;
        tableMap[addr + 2].hex_type = QString(". . .");
        tableMap[addr + 2].command = "";
        tableMap[addr + 2].command_data = -1;
    }
    return commandSize;
}

void MainWindow::convertHexToData(int addr)
{
    if (tableMap[addr].hex_type == "") {
        tableMap[addr].hex_type = QString("data");
        tableMap[addr].command = QString("DB");
        tableMap[addr].command_data = (int)tableMap[addr].hex;
    }
}

void MainWindow::addLabel()
{
    int row = ui->tableWidget->currentRow();
    int addr = row + offset;
    tableMap[addr].label = addr;
    updateTableWidget();
}

void MainWindow::removeLabel()
{
    int row = ui->tableWidget->currentRow();
    int addr = row + offset;
    tableMap[addr].label = -1;
    updateTableWidget();
}

void MainWindow::clearLabels()
{
    QList<int> keys = tableMap.keys();
    for (auto &dest_addr: keys) {
        QString destHexType = tableMap[dest_addr].hex_type;
        if (destHexType == "???") {
            bool flag = checkForRefs(dest_addr);
            if (!flag) {
                tableMap[dest_addr].hex_type = "";
            }
        }
    }
}

void MainWindow::redefineLabels()
{
    /*int LABELS_COUNTER = 1;
    int SUBROUTINE_COUNTER = 1;
    int DATA_COUNTER = 1;
    std::printf("\nSet labels ...");
    bool label_flag = false;
    bool subroutine_flag = false;
    bool data_flag = false;
    QList<int> keys = tableMap.keys();
    for (auto &cur_addr: keys) {
        label_flag = false;
        subroutine_flag = false;
        data_flag = false;
        unsigned char currByte = tableMap[cur_addr].hex;
        int currSize = sizeOfCmd[currByte];
        QString curr_truCom = tableMap[cur_addr].hex_type;
        int curr_command_data = tableMap[cur_addr].command_data;
        QString lab_truCom = tableMap[curr_command_data].hex_type;
        if (curr_truCom == "cmd" && currSize == 3 && tableMap[cur_addr].command_data_label == "") {
            if (lab_truCom != "") {
                QString currLabel = "";
                QString cmd = tableMap[cur_addr].command;
                if (findCallCommands(cmd)) {
                    currLabel = "SUBROUTINE_" + QString::number(SUBROUTINE_COUNTER);
                    subroutine_flag = true;
                }
                else if (findDataCommands(cmd)) {
                    currLabel = "DATA_" + QString::number(DATA_COUNTER);
                    data_flag = true;
                }
                else {
                    currLabel = "LABEL_" + QString::number(LABELS_COUNTER);
                    label_flag = true;
                }

                tableMap[cur_addr].command_data_label = currLabel;

                IntStructIterator lab_iter = tableMap.find(curr_command_data);
                if (lab_iter != tableMap.end()) {
                    if (tableMap[curr_command_data].label == "") {
                        tableMap[curr_command_data].label = currLabel + ":";
                    }
                }
                IntStructIterator iter = tableMap.find(cur_addr);
                IntStructIterator next_iter = iter++;
                if (next_iter != tableMap.end()) {
                    for (IntStructIterator it = next_iter; it != tableMap.end(); it++) {
                        int next_addr = it.key();
                        unsigned char nextByte = tableMap[next_addr].hex;
                        int nextSize = sizeOfCmd[nextByte];
                        QString next_truCom = tableMap[next_addr].hex_type;
                        if (next_truCom == "cmd" && nextSize == 3 && tableMap[next_addr].command_data == curr_command_data) {
                            tableMap[next_addr].command_data_label = currLabel;
                        }
                    }
                }
            }
            else {
                tableMap[cur_addr].command_data_label = "";
                std::printf("\nError on 0x%04x\n", curr_command_data);
            }
        }

        if (label_flag) {
            LABELS_COUNTER++;
        }
        else if (data_flag) {
            DATA_COUNTER++;
        }
        else if (subroutine_flag) {
            SUBROUTINE_COUNTER++;
        }
    }*/
}

bool MainWindow::checkForRefs(int addr)
{
    QList<int> keys = tableMap.keys();
    for (auto &key: keys) {
        QString hexType = tableMap[key].hex_type;
        if (hexType == "cmd") {
            unsigned char currByte = tableMap[key].hex;
            int commandSize = sizeOfCmd[currByte];
            if (commandSize == 3 && tableMap[key].command_data == addr) {
                return true;
            }
        }
    }
    return false;
}

bool MainWindow::findJumpCommands(QString cmd)
{
    QList<QString> JUMP_CMD = {"JMP", "JZ", "JNZ", "JP", "JM", "JC", "JNC", "JPE", "JPO"};
    if (JUMP_CMD.indexOf(cmd) != -1) {
        return true;
    }
    return false;
}

bool MainWindow::findCallCommands(QString cmd)
{
    QList<QString> CALL_CMD = {"CALL", "CZ", "CNZ", "CP", "CM", "CC", "CNC", "CPE", "CPO"};
    if (CALL_CMD.indexOf(cmd) != -1) {
        return true;
    }
    return false;
}

bool MainWindow::findDataCommands(QString cmd)
{
    QList<QString> DATA_CMD = {"LDA", "STA", "LHLD", "SHLD"};
    if (DATA_CMD.indexOf(cmd) != -1) {
        return true;
    }
    return false;
}

bool MainWindow::findLxiCommands(QString cmd)
{
    if (cmd.indexOf("LXI") != -1) {
        return true;
    }
    return false;
}

void MainWindow::convertBlockToCommands()
{
    makeUndoStatus();
    int row = ui->tableWidget->currentRow();
    int addr = row + offset;
    tableMap[addr].label = addr;
    recognizeBlock(addr);
    updateTableWidget();
}

void MainWindow::convertRowsToData()
{
    makeUndoStatus();
    int row = ui->tableWidget->currentRow();
    int addr = row + offset;
    IntStructIterator it = tableMap.find(addr);
    while (it != tableMap.end()) {
        QString hexTypeText = ui->tableWidget->item(row, 3)->text();
        if (hexTypeText == "???") {
            tableMap[it.key()].hex_type = "";
            tableMap[it.key()].label = it.key();
        }
        convertHexToData(it.key());
        row ++;
        it ++;
        if (row > ui->tableWidget->rowCount() - 1) {
            break;
        }
        QString cmdText = ui->tableWidget->item(row, 4)->text();
        hexTypeText = ui->tableWidget->item(row, 3)->text();
        if (cmdText != "undef" || hexTypeText != "") {
            break;
        }
    }
    updateTableWidget();
}

void MainWindow::convertRowToData()
{
    makeUndoStatus();
    int row = ui->tableWidget->currentRow();
    int addr = row + offset;
    QString hexTypeText = ui->tableWidget->item(row, 3)->text();
    if (hexTypeText == "???") {
        tableMap[addr].hex_type = "";
        tableMap[addr].label = addr;
    }
    convertHexToData(addr);
    updateTableWidget();
}

void MainWindow::convertBlockToUndef()
{
    makeUndoStatus();
    int row = ui->tableWidget->currentRow();
    int addr = row + offset;
    IntStructIterator it = tableMap.find(addr);
    while (it != tableMap.end()) {
        QString label = ui->tableWidget->item(row, 3)->text();
        if (label != "") {
            tableMap[it.key()].hex_type = "???";
            ui->tableWidget->item(row, 3)->setText(QString(""));
            tableMap[it.key()].label = -1;
        } else {
            tableMap[it.key()].hex_type = "";
        }
        tableMap[it.key()].command = QString("");
        tableMap[it.key()].command_data = -1;
        row ++;
        it ++;
        if (row > ui->tableWidget->rowCount() - 1) {
            break;
        }
        label = ui->tableWidget->item(row, 3)->text();
        QString hexType = ui->tableWidget->item(row, 2)->text();
        QString commamd = ui->tableWidget->item(row, 4)->text();
        if (((hexType == "cmd" || hexType == "data") && label != "") || commamd == "undef") {
            break;
        }
    }
    clearLabels();
    updateTableWidget();
}

/***************************************
** Table view
***************************************/

void MainWindow::updateTableWidget()
{
    ui->tableWidget->setRowCount(equMap.size() + tableMap.size());
    int row = 0;
    /*QList<QString> keys = tableMap.keys();
    for (auto &key: tableMap) {

        row++;
    }*/

    QList<int> keys = tableMap.keys();
    for (auto &key: keys) {
        auto currByte = tableMap[key].hex;
        QString hexType = tableMap[key].hex_type;
        int label = tableMap[key].label;
        QString cmd = tableMap[key].command;
        QString qByte = QString::fromUtf8((const char*)&currByte, 1);

        QTableWidgetItem *addr_item = new QTableWidgetItem(convertNumToHexString(key, 4));
        QTableWidgetItem *hex_item = new QTableWidgetItem(convertNumToHexString(currByte, 2));
        QTableWidgetItem *type_item = new QTableWidgetItem(hexType);
        QTableWidgetItem *label_item;
        QTableWidgetItem *cmd_item;
        QTableWidgetItem *data_item;
        QTableWidgetItem *char_item = new QTableWidgetItem(qByte);

        if (label != -1) {
            label_item = new QTableWidgetItem(convertNumToHexString(label, 4) + QString(":"));
        }
        else {
            label_item = new QTableWidgetItem(QString(""));
        }

        if (cmd != "") {
            cmd_item = new QTableWidgetItem(tableMap[key].command);
            if (cmd == QString("DB") || sizeOfCmd[currByte] == 2) {
                cmd_item->setForeground(QColor(0xC5,0x86,0xC0));
                data_item = new QTableWidgetItem(convertNumToHexString(tableMap[key].command_data, 2));
                data_item->setForeground(QColor(0xB5,0xCE,0xA8));
            }
            else if (sizeOfCmd[currByte] == 3) {
                cmd_item->setForeground(QColor(0x1E,0x38,0xA1));
                data_item = new QTableWidgetItem(convertNumToHexString(tableMap[key].command_data, 4));
                data_item->setForeground(QColor(0xD4,0xD4,0xD4));
            }
            else {
                cmd_item->setForeground(QColor(0x9C,0xDC,0xFE));
                data_item = new QTableWidgetItem(QString(""));
                data_item->setForeground(QColor(0xB5,0xCE,0xA8));
            }
        }
        else {
            data_item = new QTableWidgetItem(QString(""));
            if (hexType == "") {
                cmd_item = new QTableWidgetItem(QString("undef"));
                cmd_item->setForeground(QColor(100,100,100));
                cmd_item->setBackground(QColor(100,100,100,60));
                label_item->setBackground(QColor(100,100,100,60));
                data_item->setBackground(QColor(100,100,100,60));
            }
            else if (hexType == "???") {
                cmd_item = new QTableWidgetItem(QString("undef"));
                cmd_item->setForeground(QColor(100,100,100));
                cmd_item->setBackground(QColor(100,0,0,200));
                label_item->setText(QString("???"));
                label_item->setBackground(QColor(100,0,0,200));
                data_item->setBackground(QColor(100,0,0,200));
            } else {
                cmd_item = new QTableWidgetItem(QString(""));
            }
        }

        QFont labelFont;
        labelFont.setBold(true);

        addr_item->setTextAlignment(Qt::AlignHCenter | Qt::AlignTop);
        addr_item->setFlags(addr_item->flags() & ~Qt::ItemIsEditable);
        addr_item->setFlags(addr_item->flags() & ~Qt::ItemIsSelectable);
        addr_item->setBackground(QColor(230,230,230,20));

        hex_item->setTextAlignment(Qt::AlignHCenter | Qt::AlignTop);
        hex_item->setFlags(hex_item->flags() & ~Qt::ItemIsEditable);
        hex_item->setFlags(hex_item->flags() & ~Qt::ItemIsSelectable);
        hex_item->setBackground(QColor(230,230,230,20));

        type_item->setTextAlignment(Qt::AlignHCenter | Qt::AlignTop);
        type_item->setFlags(type_item->flags() & ~Qt::ItemIsEditable);
        type_item->setFlags(type_item->flags() & ~Qt::ItemIsSelectable);
        type_item->setBackground(QColor(230,230,230,20));

        label_item->setTextAlignment(Qt::AlignLeft | Qt::AlignTop);
        label_item->setFlags(label_item->flags() & ~Qt::ItemIsEditable);
        //label_item->setFlags(label_item->flags() & ~Qt::ItemIsSelectable);
        label_item->setFont(labelFont);

        cmd_item->setTextAlignment(Qt::AlignLeft | Qt::AlignTop);
        cmd_item->setFlags(cmd_item->flags() & ~Qt::ItemIsEditable);
        //cmd_item->setFlags(cmd_item->flags() & ~Qt::ItemIsSelectable);

        data_item->setTextAlignment(Qt::AlignLeft | Qt::AlignTop);
        data_item->setFlags(data_item->flags() & ~Qt::ItemIsEditable);
        //data_item->setFlags(data_item->flags() & ~Qt::ItemIsSelectable);

        char_item->setTextAlignment(Qt::AlignHCenter | Qt::AlignTop);
        char_item->setFlags(char_item->flags() & ~Qt::ItemIsEditable);
        char_item->setFlags(char_item->flags() & ~Qt::ItemIsSelectable);

        ui->tableWidget->setItem(row, Columns::ADDR, addr_item);
        ui->tableWidget->setItem(row, Columns::HEX, hex_item);
        ui->tableWidget->setItem(row, Columns::TYPE, type_item);
        ui->tableWidget->setItem(row, Columns::LABEL, label_item);
        ui->tableWidget->setItem(row, Columns::COMMAND, cmd_item);
        ui->tableWidget->setItem(row, Columns::DATA, data_item);
        ui->tableWidget->setItem(row, Columns::CHAR, char_item);

        for (int bit = 0; bit < 8; bit++) {
            if (getBit(currByte, 7 - bit) == true) {
                ui->tableWidget->setItem(row, bit + Columns::B7, new QTableWidgetItem);
                ui->tableWidget->item(row, bit + Columns::B7)->setBackground(Qt::blue);
            } else {
                ui->tableWidget->setItem(row, bit + Columns::B7, new QTableWidgetItem);
                ui->tableWidget->item(row, bit + Columns::B7)->setBackground(Qt::transparent);
            }
            QTableWidgetItem *item = ui->tableWidget->item(row, bit + Columns::B7);
            item->setFlags(item->flags() & ~Qt::ItemIsEditable);
            item->setFlags(item->flags() & ~Qt::ItemIsSelectable);
        }

        row++;
    }
    setInfo();
}

void MainWindow::setInfo()
{
    possibleRefsCount = 0;
    undefRowsCount = 0;
    errors = 0;
    int row = 0;
    int dest_row = 0;
    int rowsCount  = ui->tableWidget->rowCount();
    QString err("");
    QList<int> keys = tableMap.keys();
    for (auto &key: keys) {
        dest_row = static_cast<int>(round(_VIS_ROW_COUNT*(static_cast<float>(row)/rowsCount)));
        if (dest_row >= _VIS_ROW_COUNT) dest_row = _VIS_ROW_COUNT - 1;

        QString hexType = tableMap[key].hex_type;
        QString command = tableMap[key].command;
        if (hexType == "???") {
            possibleRefsCount++;
            undefRowsCount++;
            ui->tableWidget_visual->item(dest_row, 0)->setBackground(QColor(100,0,0,200));
        }
        else if (hexType == "") {
            undefRowsCount++;
            ui->tableWidget_visual->item(dest_row, 0)->setBackground(QColor(100,0,0,200));
        }
        else {
            ui->tableWidget_visual->item(dest_row, 0)->setBackground(QColor(0,0,0,200)); // to default background
        }
        if (command.indexOf("UNDOC") != -1) {
            errors++;
            err += QString("  At: ") + convertNumToHexString(key, 4) + QString("\nbad command: %1")
                    .arg(command) + QString(" (this is probably data.)\n");
        }
        row++;
    }
    ui->textBrowser_log->setText(QString("Undefined rows: %1\nPossible reference: %2\nErrors: %3")
                                 .arg(QString::number(undefRowsCount), QString::number(possibleRefsCount),
                                      QString::number(errors)));
    if (err == "") err = "No";
    ui->textBrowser_errors->setText(err);
}

void MainWindow::onItemEntered(QTableWidgetItem *item)
{
    if (item) {
        int row = item->row();
        int column = item->column();
        int addr = row + offset;
        if (column == 2) {  // Show hex type
            QString fullHexType = "undefined";
            QString hexType = tableMap[addr].hex_type;
            if (hexType == "cmd") {
                fullHexType = "command";
            }
            else if (hexType == ". . .") {
                fullHexType = "command (next byte)";
            }
            else if (hexType == "???") {
                fullHexType = "undefined (with a possible reference)";
            }
            else if (hexType == "data") {
                fullHexType = "data";
            }
            QString line = convertNumToHexString(addr, 4) + QString(": ") + fullHexType;
            item->setToolTip(line);
        }
        else if (column == 3) { // Show refs
            QString line = "";
            QList<int> keys = tableMap.keys();
            for (auto &key: keys) {
                QString hexType = tableMap[key].hex_type;
                if (hexType == "cmd") {
                    unsigned char currByte = tableMap[key].hex;
                    int commandSize = sizeOfCmd[currByte];
                    if (commandSize == 3 && tableMap[key].command_data == addr) {
                        line += convertNumToHexString(key, 4) + QString(":  ") + tableMap[key].command
                                + QString("  ") + convertNumToHexString(addr, 4) + QString("\n");
                    }
                }
            }
            if (line == "") {
                line = "-";
            }
            item->setToolTip(QString("Refs:\n") + line);
        }
        else if (column == 4) { // Show conversion to mnemonics
            if (ui->tableWidget->item(row, 4)->text() == "undef") {
                QString line = "";
                IntStructIterator it = tableMap.find(addr);
                while (it != tableMap.end()) {
                    QString command_data = "";
                    unsigned char currByte = tableMap[it.key()].hex;
                    int commandSize = sizeOfCmd[currByte];
                    QString command = hexToCmd[currByte];
                    if (commandSize == 2) {
                        command_data = convertNumToHexString((int)tableMap[it.key() + 1].hex, 2);
                    }
                    else if (commandSize == 3) {
                        command_data = convertNumToHexString(256 * (int)tableMap[it.key() + 2].hex
                                + (int)tableMap[it.key() + 1].hex, 4);
                    }
                    line += convertNumToHexString(it.key(), 4) + QString(":  ") + command
                            + QString("  ") + command_data + QString("\n");

                    row += commandSize;
                    it += commandSize;
                    if (row > ui->tableWidget->rowCount() - 1) {
                        break;
                    }
                    QString currText = ui->tableWidget->item(row, 4)->text();
                    if (command == "JMP" || command == "RET" || command == "PCHL" || currText != "undef") {
                        break;
                    }
                }
                item->setToolTip(QString("Conversion to mnemonics:\n") + line);
            }
        }
        else if (column == 5) { // Show labels
            QString hexType = tableMap[addr].hex_type;
            if (hexType == "cmd") {
                unsigned char currByte = tableMap[addr].hex;
                int commandSize = sizeOfCmd[currByte];
                if (commandSize == 3) {
                    QString line = "-";
                    int dest_addr = tableMap[addr].command_data;
                    IntStructIterator it = tableMap.find(dest_addr);
                    if (it != tableMap.end()) {
                        int label = tableMap[dest_addr].label;
                        if (label != -1) {
                            QString dest_command_data = "";
                            unsigned char destByte = tableMap[dest_addr].hex;
                            int dest_commandSize = sizeOfCmd[destByte];
                            QString dest_command = tableMap[dest_addr].command;
                            if (dest_command == "DB" || dest_commandSize == 2) {
                                dest_command_data = convertNumToHexString(tableMap[dest_addr].command_data, 2);
                            }
                            else if (dest_commandSize ==3) {
                                dest_command_data = convertNumToHexString(tableMap[dest_addr].command_data, 4);
                            }
                            line = convertNumToHexString(dest_addr, 4) + QString(":  ") + tableMap[dest_addr].command
                                    + QString("  ") + dest_command_data;
                        }
                    }
                    item->setToolTip(QString("Label:\n") + line);
                }
            }
        }
    }
}

void MainWindow::provideContextMenu(const QPoint &position)     /*** Call table items menu  ***/
{
    QTableWidgetItem *item = ui->tableWidget->itemAt(position.x(), position.y());
    if (item != nullptr) {
        int row = item->row();
        int column = item->column();
        QString hexTypeText = ui->tableWidget->item(row, 2)->text();
        QString label = ui->tableWidget->item(row, 3)->text();
        if (column == 3) {
            if ((hexTypeText == "cmd" || hexTypeText == ". . ." || hexTypeText == "data") && label == "") {
                addLabelAction->setEnabled(true);
                removeLabelAction->setEnabled(false);
            }
            else if ((hexTypeText == "cmd" || hexTypeText == ". . ." || hexTypeText == "data") && label != "") {
                addLabelAction->setEnabled(false);
                int addr = row + offset;
                bool flag = checkForRefs(addr);
                if (flag) {
                    removeLabelAction->setEnabled(false);
                }
                else {
                    removeLabelAction->setEnabled(true);
                }
            }
            else {
                addLabelAction->setEnabled(false);
                removeLabelAction->setEnabled(false);
            }
            labelMenu->exec(ui->tableWidget->mapToGlobal(QPoint(position.x(), position.y() + 35)));
        }
        else if (column == 4) {
            QString command = ui->tableWidget->item(row, 4)->text();
            if (command == "undef") {
                convToCmd->setEnabled(true);
                convToData->setEnabled(true);
                convSelToData->setEnabled(true);
                resetToUndef->setEnabled(false);
            }
            else if (hexTypeText == "cmd" || hexTypeText == "data") {
                convToCmd->setEnabled(false);
                convToData->setEnabled(false);
                convSelToData->setEnabled(false);
                resetToUndef->setEnabled(true);
            }
            else {
                convToCmd->setEnabled(false);
                convToData->setEnabled(false);
                convSelToData->setEnabled(false);
                resetToUndef->setEnabled(false);
            }
            itemMenu->exec(ui->tableWidget->mapToGlobal(QPoint(position.x(), position.y() + 35)));
        }
    }
}

void MainWindow::onSlideBarValueChanged(int value)
{
    int max_value = ui->tableWidget->verticalScrollBar()->maximum();
    int dest_row = static_cast<int>(round(_VIS_ROW_COUNT*(static_cast<float>(value)/max_value)));
    if (dest_row >= _VIS_ROW_COUNT) dest_row = _VIS_ROW_COUNT - 1;
    ui->tableWidget_visual->setCurrentCell(dest_row, 0);
}

void MainWindow::makeUndoStatus()
{
    undoTableMap.clear();
    undoTableMap = tableMap;
    undoTableMap.detach();
    ui->actionUndo->setEnabled(true);
    ui->actionRedo->setEnabled(false);
}

void MainWindow::on_tableWidget_visual_cellClicked(int row, int column)
{
    cout << column << endl;
    int rowsCount  = ui->tableWidget->rowCount();
    if (rowsCount > 0) {
        int dest_row = static_cast<int>(round(rowsCount*(static_cast<float>(row)/_VIS_ROW_COUNT)));
        if (dest_row >= rowsCount) dest_row = rowsCount - 1;
        ui->tableWidget->selectRow(dest_row);
    }
}

bool MainWindow::getBit(unsigned char byte, int position) // position in range 0-7
{
    return (byte >> position) & 0x1;
}

template <typename Num>
QString MainWindow::convertNumToHexString(Num n, int width)
{
    return QString("0x") + QString::number(n, 16).rightJustified(width, '0');
}

/***************************************
** Show message
***************************************/

void MainWindow::showMessage(const QString message)
{
    MessageWindow msgWindow(this);
    msgWindow.setMessage(message);
    msgWindow.setModal(true);
    msgWindow.exec();
}
