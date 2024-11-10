#ifndef CASE_DATA_DEFINE_H
#define CASE_DATA_DEFINE_H

#include <QListWidgetItem>

typedef struct{
    int8_t m_err;
    int32_t m_threadHold;
    int32_t m_phaseA;
    int32_t m_phaseB;
    int32_t m_phaseC;
    uint8_t m_state;
    uint8_t m_isAuto;
    QString m_startTime;
    QString m_stopTime;
    uint32_t m_syncTime;
}caseData_t;

typedef struct{
    QString m_name;
    struct{
        float m_lat;
        float m_lon;
    }m_location;
    QString m_color;
    QString m_description;
    bool m_isOnline;
    caseData_t m_data;
}caseInfo_t;

typedef struct{
    caseInfo_t* m_info = nullptr;
    QListWidgetItem* m_display = nullptr;
    int32_t m_index = -1;
}caseGet_t;

#endif // CASE_DATA_DEFINE_H
