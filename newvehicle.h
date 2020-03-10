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
    void on_pushButton_2_pressed();

    void on_pushButton_pressed();

    void on_label_9_linkActivated(const QString &link);

private:
    Ui::newvehicle *ui;
};

#endif // NEWVEHICLE_H
