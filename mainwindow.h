#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


//Переведите кодировку в UTF-8


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_pushButton_main_entering_clicked();

    void on_pushButton_main_BDsettings_clicked();

    void on_pushButton_main_extering_clicked();

    void on_pushButton_main_view_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
