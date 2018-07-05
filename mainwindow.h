#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void changeStatus(bool);
    ~MainWindow();

private slots:

    void on_pushButton_main_entering_clicked();

    void on_pushButton_main_BDsettings_clicked();





    void on_pushButton_main_extering_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
