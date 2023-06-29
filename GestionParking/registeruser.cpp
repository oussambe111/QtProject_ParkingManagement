#include "registeruser.h"
#include "ui_registeruser.h"
#include <QMessageBox>
registeruser::registeruser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registeruser)
{
    ui->setupUi(this);
}

registeruser::~registeruser()
{
    delete ui;
}

void registeruser::on_btnSave_clicked()
{
    QString nom = ui->txtNom->text();
    QString prenom = ui->txtPrenom->text();
    QString typev = ui->txtTypeV->text();
    QString matricule = ui->txtMatricule->text();
    QString numtel = ui->txtNumTel->text();
    QString address = ui->txtPermanentAddress->text();
    QString packageName = ui->cmbChoosePackage->currentText();

    QSqlDatabase database = QSqlDatabase::database("DB1");
    QSqlQuery query(database);

    query.prepare("insert into User (Nom, Prenom, TypeV, Matricule, NumTel, Adresse, Offre) "
                  "values('" + nom + "','" + prenom + "','" + typev + "', '" + matricule + "','" + numtel + "','" + address + "','" + packageName +"')");

    query.exec();
    query.finish();
    query.clear();
    qDebug() << "Enregistrement fait avec scuccés  "<< query.lastQuery();
    qDebug() << "Last error : "<< query.lastError().text();
      QMessageBox::information(this, "Enregistrement  réussie", "Votre Nouveau utilisateur a éte enregistrer avec succes  !");
    on_btnReset_clicked();
}
void registeruser::on_loadPakcage_clicked()
{
    QSqlDatabase database = QSqlDatabase::database("DB1");
    QSqlQuery query(database);

    query.prepare("select PackageName from Package");
    query.exec();
    while(query.next())
    {
        ui->cmbChoosePackage->addItem(query.value(0).toString());
        qDebug() << "Filling Combobox " << query.value(0).toString();
    }

    qDebug() << "Last error : "<< query.lastQuery();
    qDebug() << "Last error : "<< query.lastError().text();
}
void registeruser::on_cmbChoosePackage_currentIndexChanged(int index)
{
    QString packageName = ui->cmbChoosePackage->currentText();
    QSqlDatabase database = QSqlDatabase::database("DB1");
    QSqlQuery query(database);

    query.prepare("select PackageDescription from Package where PackageName ='" + packageName + "'");
    query.exec();
    query.next();
    ui->txtPackageDescription->setText(query.value(0).toString());
    query.finish();query.clear();
    qDebug() << "Last error : "<< query.lastQuery();
    qDebug() << "Last error : "<< query.lastError().text();
}

void registeruser::on_btnReset_clicked()
{
    ui->txtNom->clear();
    ui->txtPrenom->clear();
    ui->txtTypeV->clear();
    ui->txtMatricule->clear();
    ui->txtNumTel->clear();
    ui->txtPermanentAddress->clear();
    ui->txtPackageDescription->clear();
}
