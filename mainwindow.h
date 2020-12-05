#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_tableWidget_cellActivated(int row, int column);


    void on_pushButton_clicked();





    void on_view_activated(const QModelIndex &index);

    void on_modifier_clicked();

    void on_supprimer_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_tri_clicked();

    void on_tri_2_clicked();

    void on_modifier_2_clicked();

    void on_pushButton2_clicked();

    void on_supprimer_2_clicked();

    void on_pushButton_5_clicked();

    void on_tabWidget_tabBarClicked(int index);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
