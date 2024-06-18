#ifndef AJOUTER_VENTE_BY_GERANT_H
#define AJOUTER_VENTE_BY_GERANT_H

#include <QDialog>

namespace Ui {
class Ajouter_vente_by_gerant;
}

class Ajouter_vente_by_gerant : public QDialog
{
    Q_OBJECT

public:
    explicit Ajouter_vente_by_gerant(QWidget *parent = nullptr,const QString& id = "");
    ~Ajouter_vente_by_gerant();
    QString getId() const;
    QString m_id;

private slots:
    void on_pushButton_Valider_Venteg_clicked();

    void on_pushButton_telechargerventes_clicked();

    void on_pushButton_Abandonner_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::Ajouter_vente_by_gerant *ui;
    void clearFields_memeClient();
    void clear_finVente();
};

#endif // AJOUTER_VENTE_BY_GERANT_H
