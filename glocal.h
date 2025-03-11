#ifndef GLOCAL_H
#define GLOCAL_H
#include <QMessageBox>
#include <QWidget>

namespace Ui {
class Glocal;
}

class Glocal : public QWidget
{
    Q_OBJECT

public:
    explicit Glocal(QWidget *parent = nullptr);
    ~Glocal();
private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_11_clicked();

private:
    Ui::Glocal *ui;
};

#endif // GLOCAL_H
