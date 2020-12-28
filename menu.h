#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include "connection.h"
QT_BEGIN_NAMESPACE
namespace Ui { class menu; }
QT_END_NAMESPACE

class menu : public QMainWindow
{
    Q_OBJECT

public:
    menu(QWidget *parent = nullptr);
    ~menu();

private slots:

    void on_pushButton_gestion_des_abonnes_clicked();

    void on_pushButton_gestion_employees_clicked();

private:
    Ui::menu *ui;
};
#endif // MENU_H
