#ifndef AFFICHERFACTURE_H
#define AFFICHERFACTURE_H
#include <QDate>
#include "ui_afficherfacture.h"
#include <QDialog>

namespace Ui {
class afficherfacture;
}

class afficherfacture : public QDialog
{
    Q_OBJECT

public:
    explicit afficherfacture(QWidget *parent = nullptr,const QString& id="",const QString& id_client="",const QDate& currentDate = QDate());
    ~afficherfacture();
    QString getId() const;
    QString getId_client()const;
    QDate currentDate()const;



private:
    Ui::afficherfacture *ui;
    QString m_id;
    QString m_idC;
    QDate m_currentDate;

};

#endif // AFFICHERFACTURE_H
