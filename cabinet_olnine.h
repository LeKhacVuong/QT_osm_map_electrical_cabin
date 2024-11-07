#ifndef CABINET_OLNINE_H
#define CABINET_OLNINE_H

#include <QWidget>
#include <QLineEdit>
#include <QPainter>
#include <QVBoxLayout>
#include <QHBoxLayout>

class CustomWidget : public QWidget {
    Q_OBJECT

public:
    CustomWidget(QWidget* parent = nullptr)
        : QWidget(parent), circleColor(Qt::red) {
        // Tạo QLineEdit và thêm vào layout
        lineEdit = new QLineEdit(this);
        lineEdit->setFont(QFont("Arial", 16)); // Đặt cỡ chữ 16
        lineEdit->setFixedHeight(30); // Đặt chiều cao cố định để gọn hơn

        // Layout để chứa chấm tròn và QLineEdit
        QHBoxLayout* mainLayout = new QHBoxLayout(this);
        mainLayout->setContentsMargins(5, 5, 5, 5); // Giảm khoảng cách giữa các thành phần

        // Tạo một widget để vẽ chấm tròn
        circleWidget = new QWidget(this);
        circleWidget->setFixedSize(20, 20);
        circleWidget->setStyleSheet("background-color: red; border-radius: 10px;"); // Chấm tròn với màu đỏ

        mainLayout->addWidget(circleWidget);
        mainLayout->addWidget(lineEdit);

        setLayout(mainLayout);
        setFixedHeight(40); // Chiều cao tổng thể nhỏ hơn để vừa trong QListWidget
    }

    // Phương thức để thay đổi màu sắc của chấm tròn
    void setCircleColor(const QColor& color) {
        circleColor = color;
        QString style = QString("background-color: %1; border-radius: 10px;").arg(color.name());
        circleWidget->setStyleSheet(style);
    }

    // Phương thức để lấy văn bản từ QLineEdit
    QString getText() const {
        return lineEdit->text();
    }

    // Phương thức để đặt văn bản vào QLineEdit
    void setText(const QString& text) {
        lineEdit->setText(text);
    }

protected:
           // Không cần ghi đè paintEvent() nữa vì đã dùng QWidget riêng cho chấm tròn

private:
    QColor circleColor;
    QLineEdit* lineEdit;
    QWidget* circleWidget;
};


#endif // CABINET_OLNINE_H
