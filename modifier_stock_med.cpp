#include "modifier_stock_med.h"
#include "ui_modifier_stock_med.h"

modifier_stock_med::modifier_stock_med(QWidget *parent, const QString &medicineId, const QString &id)
    : QDialog(parent)
    , ui(new Ui::modifier_stock_med)
    , medicineId(medicineId)
    , m_id(id)
{
    qDebug() << "Modifier Constructor Medicine ID:" << medicineId;
    ui->setupUi(this);

    QSqlQuery query;
    query.prepare("SELECT * FROM Medicament WHERE id_Med = :id");
    query.bindValue(":id", medicineId);

    if (query.exec() && query.next()) {
        loadMedicineData();
    } else {
        qDebug() << "No medicine found with ID:" << medicineId;
        QMessageBox::warning(this, "Medicine Not Found", "No medicine was found with the given ID.");
    }
}

modifier_stock_med::~modifier_stock_med()
{
    delete ui;
}

void modifier_stock_med::loadMedicineData()
{
    QSqlQuery query;
    query.prepare("SELECT * FROM Medicament WHERE id_Med = :id");
    query.bindValue(":id", medicineId);

    if (query.exec()) {
        if (query.next()) {
            qDebug() << "Loading medicine data for ID:" << medicineId;
            ui->codemedlineEdit->setText(query.value("id_Med").toString());
            ui->libellelineEdit->setText(query.value("nom_Med").toString());
            ui->dateEdit->setDate(query.value("Date_Med").toDate());
            ui->spinBoxquantite->setValue(query.value("Quantite").toInt());
            ui->prixmedlineEdit->setText(query.value("prix").toString());
            ui->tvamedlineEdit->setText(query.value("TVA").toString());
        } else {
            qDebug() << "No medicine found with ID:" << medicineId;
        }
    } else {
        qDebug() << "Error executing query:" << query.lastError().text();
    }
}

QString modifier_stock_med:: getId()const{
    return m_id;
}

void modifier_stock_med::on_saveButton_clicked()
{
    QString code = ui->codemedlineEdit->text();
    QString libelle = ui->libellelineEdit->text();
    QDate Date_exp = ui->dateEdit->date();
    int quantite = ui->spinBoxquantite->value();
    QString prix = ui->prixmedlineEdit->text();
    QString tva = ui->tvamedlineEdit->text();

    QSqlQuery query;
    query.prepare("UPDATE Medicament SET id_Med = :code, nom_Med = :libelle, Date_Med = :Date_exp, Quantite = :quantite, prix = :prix, TVA = :tva WHERE id_Med = :medicineId");
    query.bindValue(":code", code);
    query.bindValue(":libelle", libelle);
    query.bindValue(":Date_exp", Date_exp);
    query.bindValue(":quantite", quantite);
    query.bindValue(":prix", prix);
    query.bindValue(":tva", tva);
    query.bindValue(":medicineId", medicineId);
    if (query.exec()) {
        QMessageBox::information(this, "Success", "Medicament updated successfully.");

    } else {
        QMessageBox::critical(this, "Error", "Failed to update Medicament.");
    }
}

void modifier_stock_med::on_Button_precedent_clicked()
{
    this->hide();
    gerer_stock gerer_stock(nullptr, getId());
    gerer_stock.setModal(true);
    gerer_stock.exec();
}


void modifier_stock_med::on_pushButton_6_clicked()
{
    exit(1);
}

