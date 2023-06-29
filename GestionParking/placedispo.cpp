#include "placedispo.h"
#include "ui_placedispo.h"



placedispo::placedispo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::placedispo)
{
    ui->setupUi(this);
    model = NULL;

}

placedispo::~placedispo()
{
    delete ui;
}

void placedispo::on_btnFind_clicked()
{
    QSqlDatabase database = QSqlDatabase::database("DB1");
     QString num = ui->txtNum->text();

    if(model == NULL)
        model = new QSqlQueryModel();

    model->setQuery("select * from Place where numero like '%" + num + "%'", database);
    ui->tableView->setModel(model);
    qDebug() << " Button Rechercher Clicked";
}



//void placedispo::onSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
//{
//    Q_UNUSED(deselected);

//    if (selected.isEmpty()) {
//        // Aucune ligne sélectionnée
//        return;
//    }

//    // Obtenir l'indice de la ligne sélectionnée
//    QModelIndex index = selected.indexes().first();

//    // Supprimer la ligne correspondante du modèle
//    QSqlTableModel *tableModel = static_cast<QSqlTableModel*>(ui->tableView->model());
//    tableModel->removeRow(index.row());
//    tableModel->submitAll();
//}




