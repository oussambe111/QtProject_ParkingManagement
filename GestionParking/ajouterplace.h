#ifndef AJOUTERPLACE_H
#define AJOUTERPLACE_H
#include "databaseheader.h"
#include <QDialog>

namespace Ui {
class AjouterPlace;
}

class AjouterPlace : public QDialog
{
    Q_OBJECT

public:
    explicit AjouterPlace(QWidget *parent = nullptr);
    ~AjouterPlace();

private slots:
    void on_pushButton_clicked();

    void on_loadPakcage_clicked();



    void on_cmbChoosePackage_currentIndexChanged(int index);

    void on_Retour_clicked();

private:
    Ui::AjouterPlace *ui;

};

#endif // AJOUTERPLACE_H
