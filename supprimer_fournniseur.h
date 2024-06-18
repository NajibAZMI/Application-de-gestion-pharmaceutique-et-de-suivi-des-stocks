#ifndef SUPPRIMER_FOURNNISEUR_H
#define SUPPRIMER_FOURNNISEUR_H

#include <QDialog>

namespace Ui {
class supprimer_fournniseur;
}

class supprimer_fournniseur : public QDialog
{
    Q_OBJECT

public:
    explicit supprimer_fournniseur(QWidget *parent = nullptr,const QString& id = "");
    ~supprimer_fournniseur();

private:
    Ui::supprimer_fournniseur *ui;
};

#endif // SUPPRIMER_FOURNNISEUR_H
