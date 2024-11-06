#ifndef CASE_SETTING_H
#define CASE_SETTING_H
#include "case_data_define.h"

#include <QDialog>

namespace Ui {
class case_setting;
}

class case_setting : public QDialog
{
    Q_OBJECT

public:
    explicit case_setting(QWidget *parent = nullptr);
    ~case_setting();

    void startSetting(caseInfo_t _caseInfo);

signals:
    void confirmSetting(QString _name, caseData_t _caseData);

private slots:
    void on_pushButton_confirm_clicked();

private:
    Ui::case_setting *ui;
    QString m_caseName;
    caseInfo_t m_caseSetting;
};

#endif // CASE_SETTING_H
