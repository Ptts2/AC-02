#ifndef NEWVEHICLE_H
#define NEWVEHICLE_H

#include <QDialog>

namespace Ui {
class newvehicle;
}

class newvehicle : public QDialog
{
    Q_OBJECT

public:
    explicit newvehicle(QWidget *parent = nullptr);
    ~newvehicle();

private slots:
    void on_CANCEL_pressed();

    void on_CREATE_pressed();

    void on_matricula_button_pressed();

private:
    Ui::newvehicle *ui;
    QWidget *parent;
};

#endif // NEWVEHICLE_H
