#ifndef LOGIN_H
#define LOGIN_H
#include "connexion.h"
#include <QMainWindow>
#include<QtSql>
#include<QDebug>
#include<QFileInfo>
#include"gestion_clients.h"
#include<QPropertyAnimation>
#include<QSound>
#include<QMediaPlayer>
#include<QSoundEffect>
#include<QUrl>




QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    //QSound *s = new QSound(":C:/Users/user/Desktop/1.wav");
     connexion c;
    ~Login();

private slots:
    void on_pushButton_log_clicked();

private:
    Ui::Login *ui;
    QSqlDatabase db;
    QPropertyAnimation *animation;

};
#endif // LOGIN_H
