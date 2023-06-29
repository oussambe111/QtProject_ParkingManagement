#ifndef FINDUSER_H
#define FINDUSER_H

#include <QDialog>

#include "databaseheader.h"

namespace Ui {
class finduser;
}

class finduser : public QDialog
{
    Q_OBJECT

public:
    explicit finduser(QWidget *parent = nullptr);
    ~finduser();

private slots:
    void on_btnFind_clicked();


    void on_tableView_activated(const QModelIndex &index);

    void on_Retour_clicked();

private:
    Ui::finduser *ui;
    QSqlQueryModel *model;
};

#endif // FINDUSER_H
