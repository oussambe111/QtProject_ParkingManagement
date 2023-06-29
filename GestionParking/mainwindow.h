
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "addpackage.h"
#include "registeruser.h"
#include "findpackage.h"
#include "finduser.h"
#include "placedispo.h"
#include "ajouterplace.h"
#include "authentification.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_9_clicked();

   void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
    AddPackage *ptrAddPackge;
    registeruser *ptrRegisteruser;
    FindPackage *ptrFindPackage;
    finduser *ptrFindUser;
    placedispo *ptrPlaceDisponible ;
    AjouterPlace *ptrAjout;
    Authentification *ptrAuth;

    QSqlDatabase database;

};
#endif // MAINWINDOW_H
