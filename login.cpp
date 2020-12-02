#include "login.h"
#include "ui_login.h"
#include "connexion.h"
#include <QPixmap>

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{

    ui->setupUi(this);
    c.createconnect();
    bool test=c.createconnect();
    if(test)
        ui->label_log->setText("connected...");
    QPixmap pic("C:/Users/user/Desktop/login.png");
     ui->label_pic->setPixmap(pic.scaled(180,180,Qt::KeepAspectRatio));


     animation =new QPropertyAnimation(ui->pushButton_log,"geometry");
     animation->setDuration(4000);
     animation->setStartValue(ui->pushButton_log->geometry());
     animation->setEndValue(QRect(200,200,100,50));


     QEasingCurve curve;
     curve.setType(QEasingCurve::OutElastic);
     animation->setEasingCurve(curve);
     animation->start();


     animation =new QPropertyAnimation(ui->label,"geometry");
     animation->setDuration(2000);
     animation->setStartValue(ui->label->geometry());
     animation->setEndValue(QRect(200,40,200,40));
     animation->start();


}

Login::~Login()
{
    delete ui;
}



void Login::on_pushButton_log_clicked()
{


    QSqlQuery query(db);
    QString select = "SELECT username from loginQt where username=? and password=?";
    qDebug() << select;
   query.prepare(select);
   query.addBindValue(ui->lineEdit_user->text());
   query.addBindValue(ui->lineEdit_password->text());
   query.exec();

   if(query.exec())
   {
       int count=0;
       while(query.next())
       {
           count++;
       }
       if(count==1)
       {
           ui->label_l->setText("username and password are correct");
           QPixmap pic("C:/Users/user/Desktop/log1.png");
            ui->label_pic->setPixmap(pic.scaled(150,200,Qt::KeepAspectRatio));

           // QThread::msleep(1000) ;

              //s->play();
             this->hide();
             gestion_clients g;
             g.setModal(true);
             g.exec();

               /* QSoundEffect effect;
                 effect.setSource(QUrl::fromLocalFile("1.wav"));
                 effect.setLoopCount(QSoundEffect::Infinite);
                 effect.setVolume(50);
                 effect.play();*/

       }

      else if(count<1)
       {
           ui->label_l->setText("username and password are incorrect");
           QPixmap pic("C:/Users/user/Desktop/fail.png");
             ui->label_pic->setPixmap(pic.scaled(140,140,Qt::KeepAspectRatio));

       }
        //c.closeconnect();
   }
}








