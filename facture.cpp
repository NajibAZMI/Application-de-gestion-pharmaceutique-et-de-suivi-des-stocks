#include "facture.h"
#include "ui_facture.h"

facture::facture(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::facture)
{
    ui->setupUi(this);
}

facture::~facture()
{
    delete ui;
}
