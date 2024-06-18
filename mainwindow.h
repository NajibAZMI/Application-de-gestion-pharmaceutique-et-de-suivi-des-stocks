#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QMessageBox>
#include "employee.h"
#include "accueil_gerant.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

     void on_QuitterPushButton_clicked();





     void on_LoginPushButton_1_clicked();

 private:
    Ui::MainWindow *ui;
    QSqlDatabase db;

};

#endif // MAINWINDOW_H
