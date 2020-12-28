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
    connection.cpp \
    departement1.cpp \
    employe1.cpp \
    gestion_clients.cpp \
    main.cpp \
    menu.cpp \
    ressource_humaine.cpp

HEADERS += \
    abonne.h \
    abonnement.h \
    connection.h \
    departement1.h \
    employe1.h \
    gestion_clients.h \
    menu.h \
    ressource_humaine.h

FORMS += \
    gestion_clients.ui \
    menu.ui \
    ressource_humaine.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
