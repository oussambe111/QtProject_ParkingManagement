#include "ajouterplace.h"
#include "ui_ajouterplace.h"
#include "databaseheader.h"

#include "mainwindow.h"
AjouterPlace::AjouterPlace(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjouterPlace)
{
    ui->setupUi(this);
}

AjouterPlace::~AjouterPlace()
{
    delete ui;
}

void AjouterPlace::on_pushButton_clicked()
{
    QString num = ui->txtNum->text();
    QString etage = ui->txtEtage->text();
    QString TypeP = ui->txtType->text();
    QString packageName = ui->cmbChoosePackage->currentText();


    QSqlDatabase database = QSqlDatabase::database("DB1");
    QSqlQuery query(database);
    query.prepare("insert into Place (Numero, Etage, TypeP,PackageName) values('" + num + "','" + etage + "','" + TypeP + "','" + packageName + "')");
    query.exec();
    query.finish();
    query.clear();
//    query.prepare("INSERT INTO Places (ID ,Numero, Etage, TypeP, PackageName) VALUES (NULL,:numero, :etage, :typeP, :packageName)");
//    query.bindValue(":numero", num.toInt());
//    query.bindValue(":etage", etage);
//    query.bindValue(":typeP", TypeP);
//    query.bindValue(":packageName", packageName);
//    query.exec();
//    query.finish();


//    query.clear();
    qDebug() << "Last error : "<< query.lastError().text();

}


void AjouterPlace::on_loadPakcage_clicked()
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
}
void AjouterPlace::on_cmbChoosePackage_currentIndexChanged(int index)
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


void AjouterPlace::on_Retour_clicked()
{

    hide();
    MainWindow *menu = new MainWindow();
    menu->show();

}

