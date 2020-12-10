#ifndef POPUPMODIF_H
#define POPUPMODIF_H

#include <QDialog>

namespace Ui {
class popupmodif;
}

class popupmodif : public QDialog
{
    Q_OBJECT

public:
    //float nsomme;
    //QString nobjet;

public:
    explicit popupmodif(QWidget *parent = nullptr);
    ~popupmodif();

private slots:
    void on_pushButton_ok_clicked();

public:
    Ui::popupmodif *xi;
};


#endif // POPUPMODIF_H
