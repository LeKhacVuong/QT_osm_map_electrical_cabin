QT       += core gui qml network serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets quick location positioning quickwidgets sql

RC_ICONS = logo_cty.ico

LIBS += -lWs2_32

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cabinet_display.cpp \
    case_setting.cpp \
    electric_case_add.cpp \
    fake_mqtt.cpp \
    libs/MQTT-C/src/mqtt.c \
    libs/MQTT-C/src/mqtt_pal.c \
    libs/modbus/mb_master/sm_mb_master_impl.c \
    libs/mqtt/mqtt_client/sm_mqtt_client.c \
    libs/nanoModbus/nanomodbus.c \
    libs/utils/SerialPort.cpp \
    libs/utils/qt_utils.cpp \
    libs/utils/sm_logger.c \
    main.cpp \
    mainwindow.cpp \
    map_view.cpp

HEADERS += \
    cabinet_display.h \
    cabinet_olnine.h \
    case_data_define.h \
    case_setting.h \
    electric_case_add.h \
    fake_mqtt.h \
    libs/MQTT-C/inc/mqtt.h \
    libs/MQTT-C/inc/mqtt_pal.h \
    libs/MQTT-C/inc/posix_sockets.h \
    libs/modbus/mb_master/sm_mb_master_if.h \
    libs/modbus/mb_master/sm_mb_master_impl.h \
    libs/modbus/sm_modbus_define.h \
    libs/mqtt/mqtt_client/sm_mqtt_client.h \
    libs/nanoModbus/nanomodbus.h \
    libs/utils/SerialPort.h \
    libs/utils/elapsed_timer.h \
    libs/utils/qt_utils.h \
    libs/utils/sm_logger.h \
    mainwindow.h \
    map_view.h

FORMS += \
    cabinet_display.ui \
    case_setting.ui \
    electric_case_add.ui \
    fake_mqtt.ui \
    mainwindow.ui \
    map_view.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Maps.qrc \
    images.qrc

INCLUDEPATH += \
    libs \
    libs/utils \
    libs/MQTT-C \
    libs/MQTT-C/inc \
    libs/mqtt/mqtt_client \
    libs/nanoModbus \
    libs/modbus \
    libs/modbus/mb_master

DISTFILES += \
    libs/modbus/mb_master/CMakeLists.txt \
    logo_cty.ico
