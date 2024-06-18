#include "supprimer_fournniseur.h"
#include "ui_supprimer_fournniseur.h"

supprimer_fournniseur::supprimer_fournniseur(QWidget *parent,const QString& id)
    : QDialog(parent)
    , ui(new Ui::supprimer_fournniseur),m_id(id)
{
    ui->setupUi(this);
}

supprimer_fournniseur::~supprimer_fournniseur()
{
    delete ui;
}
QString supprimer_fournniseur::getId() const
{
    return m_id;
}
