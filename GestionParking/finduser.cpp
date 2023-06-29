#include "finduser.h"
#include "ui_finduser.h"

#include "mainwindow.h"
finduser::finduser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::finduser)
{
    ui->setupUi(this);
    model = NULL;

}

finduser::~finduser()
{
    delete ui;
    delete model;
}
void finduser::on_btnFind_clicked()
{
    QString packageName = ui->txtTourstfName->text();
    qDebug() << "Package Name : "<< packageName;
    QSqlDatabase database = QSqlDatabase::database("DB1");

    if(model == NULL)
        model = new QSqlQueryModel();

    model->setQuery("select * from User where Nom like '%" + packageName + "%'", database);
    ui->tableView->setModel(model);
    qDebug() << " after btnFind_clicked";
}



void finduser::on_tableView_activated(const QModelIndex &index)
{

}


void finduser::on_Retour_clicked()
{
    this->close();
    MainWindow *menu = new MainWindow();
    menu->show();


}

