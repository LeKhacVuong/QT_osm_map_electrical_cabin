#include "qt_utils.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QEventLoop>
#include "QSettings"

void setLineEditSnFomartOnly(QLineEdit* _lineEdit, uint32_t _maxLen){
    QRegularExpression regex("[A-Za-z0-9_@.-]+");
    QRegularExpressionValidator* validator = new QRegularExpressionValidator(regex, _lineEdit);
    _lineEdit->setMaxLength(_maxLen);
    _lineEdit->setValidator(validator);
}

void setLineEditNumberIntergerOnly(QLineEdit* _lineEdit, int32_t _min, int32_t _max) {
    QIntValidator* validator = new QIntValidator(_min, _max, _lineEdit);
    _lineEdit->setValidator(validator);
}

void setLineEditNumberFloatOnly(QLineEdit* _lineEdit, double _min, double _max, int _decimals) {
    QDoubleValidator* validator = new QDoubleValidator(_min, _max, _decimals, _lineEdit);
    validator->setNotation(QDoubleValidator::StandardNotation);
    _lineEdit->setValidator(validator);
}

bool isFloatValueEqual(float a, float b, float epsilon) {
    return fabs(a - b) < epsilon;
}

void memcpyFromLineEdit(QLineEdit* _lineEdit, uint8_t* buffer, size_t bufferSize) {
    memset(buffer, 0, bufferSize);
    QString text = _lineEdit->text();
    QByteArray byteArray = text.toUtf8();  // Chuyển thành chuỗi UTF-8
    const char* lineEditText = byteArray.constData();
    size_t textLength = byteArray.size() > bufferSize ? bufferSize :  byteArray.size();
    std::memcpy(buffer, lineEditText, textLength);
    buffer[textLength] = '\0';
}

void showLineEditFromBuff(QLineEdit* _lineEdit, const uint8_t* buffer, size_t bufferSize) {
    QString text = QString::fromUtf8(reinterpret_cast<const char*>(buffer), bufferSize);
    text = text.trimmed();
    text = text.remove(QChar::Null);
    _lineEdit->setText(text);
}


QString getAddressFromLatLon(double latitude, double longitude) {
    QNetworkAccessManager manager;

    // Tạo URL với tọa độ lat và lon
    QString url = QString("https://nominatim.openstreetmap.org/reverse?format=json&lat=%1&lon=%2&addressdetails=1")
                      .arg(latitude)
                      .arg(longitude);

    QNetworkRequest request;
    request.setUrl(QUrl(url));
    request.setHeader(QNetworkRequest::UserAgentHeader, "QtGeolocationApp");

    // Tạo một sự kiện loop để chờ phản hồi
    QEventLoop loop;

    // Gửi yêu cầu GET và chờ phản hồi
    QNetworkReply* reply = manager.get(request);
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);

    // Chờ cho đến khi phản hồi hoàn tất
    loop.exec();

    // Kiểm tra phản hồi
    QString address;
    if (reply->error() == QNetworkReply::NoError) {
        // Phân tích cú pháp JSON trả về
        QByteArray response = reply->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(response);
        QJsonObject jsonObj = jsonDoc.object();

        // Lấy tên địa chỉ từ phản hồi JSON
        if (jsonObj.contains("display_name")) {
            address = jsonObj["display_name"].toString();
            qDebug() << "Address:" << address;
        } else {
            qDebug() << "Address not found";
        }
    } else {
        qDebug() << "Error:" << reply->errorString();
    }

    reply->deleteLater();
    return address;
}

