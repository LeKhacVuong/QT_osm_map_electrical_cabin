#ifndef CABINET_DISPLAY_H
#define CABINET_DISPLAY_H

#include <QDialog>

namespace Ui {
class cabinet_display;
}

class cabinet_display : public QDialog
{
    Q_OBJECT

public:
    explicit cabinet_display(QWidget *parent = nullptr);
    ~cabinet_display();

private:
    Ui::cabinet_display *ui;
};

#endif // CABINET_DISPLAY_H
