#ifndef AFFICHER_FACTURE_H
#define AFFICHER_FACTURE_H

#include <QDialog>

namespace Ui {
class afficher_facture;
}

class afficher_facture : public QDialog
{
    Q_OBJECT

public:
    explicit afficher_facture(QWidget *parent = nullptr,const QString& id="",const QString& id_client="");
    ~afficher_facture();
    QString getId() const;
    QString getId_client() const;

private slots:
    void on_downloadbutton_clicked();

private:
    Ui::afficher_facture *ui;
    QString  m_id;
    QString  m_idC;
};

#endif // AFFICHER_FACTURE_H

