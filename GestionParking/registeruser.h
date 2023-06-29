#ifndef REGISTERUSER_H
#define REGISTERUSER_H

#include "databaseheader.h"
#include <QDialog>

namespace Ui {
class registeruser;
}

class registeruser : public QDialog
{
    Q_OBJECT

public:
    explicit registeruser(QWidget *parent = nullptr);
    ~registeruser();

private slots:
    void on_btnSave_clicked();


    void on_loadPakcage_clicked();

    void on_cmbChoosePackage_currentIndexChanged(int index);

    void on_btnReset_clicked();

private:
    Ui::registeruser *ui;
    QSqlDatabase database;
};

#endif // REGISTERUSER_H
