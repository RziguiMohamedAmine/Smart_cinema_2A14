QT       += core gui sql

QT       += printsupport

QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abonne.cpp \
    abonnement.cpp \
    categorie.cpp \
    connection.cpp \
    gestion_clients.cpp \
    gestion_des_finances.cpp \
    main.cpp \
    menu.cpp \
    popupmodif.cpp \
    transaction.cpp

HEADERS += \
    abonne.h \
    abonnement.h \
    categorie.h \
    connection.h \
    gestion_clients.h \
    gestion_des_finances.h \
    menu.h \
    popupmodif.h \
    transaction.h

FORMS += \
    gestion_clients.ui \
    gestion_des_finances.ui \
    menu.ui \
    popupmodif.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
