#ifndef MODIFIER_STOCK_MED_H
#define MODIFIER_STOCK_MED_H

#include <QDialog>
#include <QtSql>
#include <QMessageBox>
#include"gerer_stock.h"

namespace Ui {
class modifier_stock_med;
}

class modifier_stock_med : public QDialog
{
    Q_OBJECT

public:
    explicit modifier_stock_med(QWidget *parent = nullptr, const QString &medicineId = "", const QString &id = "");
    ~modifier_stock_med();
    QString getId() const;

private slots:
    void on_saveButton_clicked();

    void on_Button_precedent_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::modifier_stock_med *ui;
    QString medicineId;
    QString m_id;
    void loadMedicineData();
};

#endif // MODIFIER_STOCK_MED_H
