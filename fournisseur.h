#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H

#include <QDialog>

namespace Ui {
class fournisseur;
}

class fournisseur : public QDialog
{
    Q_OBJECT

public:
    explicit fournisseur(QWidget *parent = nullptr, const QString& id = "");
    ~fournisseur();
     QString getId() const;

private:
    Ui::fournisseur *ui;
     QString m_id;
};

#endif // FOURNISSEUR_H
