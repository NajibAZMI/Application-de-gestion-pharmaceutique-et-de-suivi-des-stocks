#ifndef FACTURE_H
#define FACTURE_H

#include <QDialog>

namespace Ui {
class facture;
}

class facture : public QDialog
{
    Q_OBJECT

public:
    explicit facture(QWidget *parent = nullptr);
    ~facture();

private:
    Ui::facture *ui;
};

#endif // FACTURE_H
