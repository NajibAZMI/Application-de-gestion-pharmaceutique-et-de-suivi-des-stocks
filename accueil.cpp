#include "accueil.h"
#include "ui_accueil.h"

Accueil::Accueil(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Accueil)
{
    ui->setupUi(this);
}

Accueil::~Accueil()
{
    delete ui;
}
