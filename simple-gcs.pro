QT += quick
QT += core
QT += network
QT += serialport

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
        src/Connection/ConnectionManager.h \
        src/Connection/VehicleConnection.h \
        src/Connection/UDPConnection.h \
        src/Connection/TCPConnection.h \
        src/Connection/SerialConnection.h \
        src/Mavlink/mavlinkhandler.h

SOURCES += \
        src/Mavlink/mavlinkhandler.cpp \
        src/main.cpp \
        src/Connection/VehicleConnection.cpp \
        src/Connection/ConnectionManager.cpp \
        src/Connection/UDPConnection.cpp \
        src/Connection/TCPConnection.cpp \
        src/Connection/SerialConnection.cpp
		
INCLUDEPATH += libs/mavlink

RESOURCES += \
        qml.qrc \

TRANSLATIONS += \
        simple-gcs_en_US.ts

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
