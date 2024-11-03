#ifndef QT_UTILS_H
#define QT_UTILS_H
#include <QRegularExpressionValidator>
#include <QLineEdit>

void setLineEditSnFomartOnly(QLineEdit* _lineEdit, uint32_t _maxLen);

void setLineEditNumberIntergerOnly(QLineEdit* _lineEdit, int32_t _min, int32_t _max);

void setLineEditNumberFloatOnly(QLineEdit* _lineEdit, double _min, double _max, int _decimals);

bool isFloatValueEqual(float a, float b, float epsilon = 1e-5);

void memcpyFromLineEdit(QLineEdit* _lineEdit, uint8_t* buffer, size_t bufferSize);

void showLineEditFromBuff(QLineEdit* _lineEdit, const uint8_t* buffer, size_t bufferSize);

QString getAddressFromLatLon(double latitude, double longitude);

#endif // QT_UTILS_H
