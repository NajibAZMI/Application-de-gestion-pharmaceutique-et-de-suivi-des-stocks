#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QSQLITE");
   // db.setDatabaseName("C:/Users/hamza/Desktop/SQLite installation Win11/Mydatabase/MYDATABASE.db");
    db.setDatabaseName("C:/Users/hamza/Desktop/SQLite installation Win11/Data_base_n/mydatabase.db");

    if (!db.open()) {
        QMessageBox::critical(this, "Erreur", "Impossible de se connecter à la base de données !");
        qDebug() << "Erreur lors de la connexion à la base de données :";
        qDebug() << db.lastError().text();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}






void MainWindow::on_QuitterPushButton_clicked()
{
    exit(1);
}





void MainWindow::on_LoginPushButton_1_clicked()
{

    QString username = ui->user->text();
    QString password = ui->password->text();
    QString id;
    QString etat;

    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE email = :username AND password = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    if (query.exec() && query.next())
    {
        id=query.value(0).toString();
        etat=query.value(7).toString();

        if(etat=="Employe"){

            this->hide();
            Employee employee(nullptr,id, username, password); // Pass username and password to the Employee constructor
            employee.setModal(true);
            employee.exec();
        }
        else if(etat=="gerant"){
            this->hide();
            accueil_gerant accueil_gerant(nullptr,id);
             accueil_gerant.setModal(true);
             accueil_gerant.exec();
        }
        else {
            QMessageBox::warning(this, "Erreur", "Vous n'êtes pas autorisé à accéder à cette interface !");
        }

    }else{
        QMessageBox::warning(this, "Erreur", "Nom d'utilisateur ou mot de passe incorrect !");
    }
}

