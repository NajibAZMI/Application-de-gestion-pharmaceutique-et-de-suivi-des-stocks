#include "fournisseur.h"
#include "ui_fournisseur.h"

fournisseur::fournisseur(QWidget *parent, const QString& id)
    : QDialog(parent)
    , ui(new Ui::fournisseur),m_id(id)
{
    ui->setupUi(this);
}

fournisseur::~fournisseur()
{
    delete ui;
}
QString fournisseur::getId() const
{
    return m_id;
}
