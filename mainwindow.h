#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <vector>
#include "vehiculo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void addVehicle(Vehiculo vehiculo);

private slots:

    void on_newvehicle_button_pressed();

    void on_exit_button_pressed();

private:
    Ui::MainWindow *ui;
    QLabel *label;
    int count;
    vector<Vehiculo> coches;
};
#endif // MAINWINDOW_H
