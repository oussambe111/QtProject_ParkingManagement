#ifndef PLACEDISPO_H
#define PLACEDISPO_H

#include <QDialog>
#include "databaseheader.h"
#include "qitemselectionmodel.h"

namespace Ui {
class placedispo;
}

class placedispo : public QDialog
{
    Q_OBJECT

public:
    explicit placedispo(QWidget *parent = nullptr);
    ~placedispo();

private slots:
    void on_btnFind_clicked();



private:
    Ui::placedispo *ui;
       QSqlDatabase database;
     QSqlQueryModel *model;

};

#endif // PLACEDISPO_H
