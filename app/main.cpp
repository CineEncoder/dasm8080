/***********************************************************************

                             D A S M   8 0 8 0
                              NOVEMBER, 2021
                            COPYRIGHT (C) 2021

 FILE: main.cpp
 MODIFIED: November, 2021
 COMMENT:
 LICENSE: GNU General Public License v3.0

***********************************************************************/


#include "mainwindow.h"
#include <QApplication>
#include <QCoreApplication>
#include <QStyleFactory>


int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    QApplication app(argc, argv);
    QCoreApplication::setOrganizationName("Dasm8080");
    QCoreApplication::setApplicationName("Dasm8080");
    QCoreApplication::setAttribute(Qt::AA_UseStyleSheetPropagationInWidgetStyles, true);
    app.setStyle(QStyleFactory::create("Fusion"));

    MainWindow window;
    window.show();
    return app.exec();
}
