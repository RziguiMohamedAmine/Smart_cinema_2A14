#ifndef DIALOG_H
#define DIALOG_H
#include <QDialog>
#include <QSerialPort>
#include "arduino.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT
private slots:
    void readserial();


public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;
    arduino aa;

};
#endif // DIALOG_H
