#ifndef AUTHENTIFICATION_H
#define AUTHENTIFICATION_H

#include <QDialog>

namespace Ui {
class Authentification;
}

class Authentification : public QDialog
{
    Q_OBJECT

public:
    explicit Authentification(QWidget *parent = nullptr);
    ~Authentification();

private slots:
    void on_Register_clicked();
    void on_Retour_clicked();


    void on_Quitter_clicked();

private:
    Ui::Authentification *ui;

};

#endif // AUTHENTIFICATION_H
