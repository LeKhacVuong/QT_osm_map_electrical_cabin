#ifndef ELECTRIC_CASE_ADD_H
#define ELECTRIC_CASE_ADD_H

#include <QDialog>

namespace Ui {
class electric_case_add;
}

class electric_case_add : public QDialog
{
    Q_OBJECT

public:
    explicit electric_case_add(QWidget *parent = nullptr);
    ~electric_case_add();

signals:
    void addCaseInfoSig(QString, float, float, QString);

private slots:
    void on_pushButton_confirm_clicked();

private:
    Ui::electric_case_add *ui;
};

#endif // ELECTRIC_CASE_ADD_H
