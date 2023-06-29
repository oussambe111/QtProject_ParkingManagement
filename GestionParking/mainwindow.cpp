
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QFile>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ptrAddPackge = new AddPackage();
    ptrRegisteruser = new registeruser();
    ptrFindPackage = new FindPackage();
    ptrFindUser = new finduser();
    ptrPlaceDisponible = new placedispo();
    ptrAjout =new AjouterPlace();

    database = QSqlDatabase::addDatabase("QSQLITE", "DB1");
    database.setDatabaseName("C:/Users/O/Desktop/GestionParking/DB1.db");

    if(!database.open()){
        qDebug() << "Erreur : Base de données non ouvertes ";
    }
    else{
        qDebug() << "Database ouvert avec succes ";
    }
//    QFile styleSheetFile("C:/Users/O/Desktop/GestionParking/Toolery.qss");
//    styleSheetFile.open(QFile::ReadOnly);
//    QString styleSheet= QLatin1String(styleSheetFile.readAll());
//    parent->setStyleSheet(styleSheet);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete ptrAddPackge;
    delete ptrRegisteruser;
    delete ptrFindUser;
    delete ptrFindPackage;
    delete ptrPlaceDisponible;
    delete ptrAjout;
    database.close();
    QSqlDatabase::removeDatabase(database.connectionName());
    qDebug() << " ~MainWindow()";
}


void MainWindow::on_pushButton_clicked()
{
    ptrAddPackge->show();
}


void MainWindow::on_pushButton_2_clicked()
{
    ptrRegisteruser->show();
}


void MainWindow::on_pushButton_3_clicked()
{
    ptrFindPackage->show();
}


void MainWindow::on_pushButton_4_clicked()
{
    ptrFindUser->show();
}

void MainWindow::on_pushButton_9_clicked()
{
    this->close();
}




void MainWindow::on_pushButton_5_clicked()
{
    ptrPlaceDisponible->show();
}


void MainWindow::on_pushButton_6_clicked()
{
    ptrAjout ->show();
}

