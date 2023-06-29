
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile styleSheetFile("C:/Users/O/Desktop/GestionParking/Toolery.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet= QLatin1String(styleSheetFile.readAll());
    a.setStyleSheet(styleSheet);
    Authentification w;
    w.show();
    return a.exec();
}
