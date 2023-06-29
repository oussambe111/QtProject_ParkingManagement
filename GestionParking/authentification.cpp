#include "authentification.h"
#include "ui_authentification.h"
#include "databaseheader.h"
#include "mainwindow.h"
#include <QMessageBox>

Authentification::Authentification(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Authentification)
{
    ui->setupUi(this);
}

Authentification::~Authentification()
{
    delete ui;
}
//void Authentification::on_Retour_clicked()
//{
//    hide();
//    MainWindow *mn = new MainWindow(this);
//    mn->show();
//}


void Authentification::on_Register_clicked()
{


QString user = ui->Email->text();
    QString password = ui->password->text();

    if (user.isEmpty() || password.isEmpty()) {
            QMessageBox::warning(this, "Authentification échouée", "Veuillez remplir tous les champs.");
            return;
    }

    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE", "DB1");
    database.setDatabaseName("C:/Users/O/Desktop/GestionParking/DB1.db");

    QSqlQuery query(database);
    if(!database.open())
    {
        qDebug() << "Error : Unable to open database";
    }
    else
    {
        qDebug() << "Database open successfully ..";
    }


    query.prepare("SELECT * FROM Login WHERE User = :username ");
    query.bindValue(":username", user);
//    query.bindValue(":password", password);
    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur de requête", "Erreur lors de l'exécution de la requête d'authentification.");
        return;
    }

    // Vérification du résultat de la requête
    if (query.next()) {
        // Authentification réussie
        QMessageBox::information(this, "Authentification réussie", "Vous êtes connecté !");
         this->close();
        MainWindow *mn = new MainWindow(this);
        mn->show();


    } else {
        // Authentification échouée
        QMessageBox::warning(this, "Authentification échouée", "Nom d'utilisateur ou mot de passe incorrect.");
        ui->Email->clear();
        ui->password->clear();
}

}


void Authentification::on_Quitter_clicked()
{
    this->close();
}

