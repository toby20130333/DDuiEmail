#-------------------------------------------------
#
# Project created by QtCreator 2016-04-17T16:34:25
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt-email
TEMPLATE = app

include(./mail/qtmail.pri)
include(./pop3/pop3.pri)


win32:{
    RC_FILE += email.rc
}

SOURCES += main.cpp \
    frmmain.cpp \
    sendemailapi/emailaddress.cpp \
    sendemailapi/mimeattachment.cpp \
    sendemailapi/mimecontentformatter.cpp \
    sendemailapi/mimefile.cpp \
    sendemailapi/mimehtml.cpp \
    sendemailapi/mimeinlinefile.cpp \
    sendemailapi/mimemessage.cpp \
    sendemailapi/mimemultipart.cpp \
    sendemailapi/mimepart.cpp \
    sendemailapi/mimetext.cpp \
    sendemailapi/quotedprintable.cpp \
    sendemailapi/smtpclient.cpp \
    receive.cpp \
    base64.cpp \
    common.cpp \
    settings.cpp \
    bdsimplecrypt.cpp \
    emailview.cpp \
    drop_shadow_widget.cpp

HEADERS  += \
    frmmain.h \
    sendemailapi/emailaddress.h \
    sendemailapi/mimeattachment.h \
    sendemailapi/mimecontentformatter.h \
    sendemailapi/mimefile.h \
    sendemailapi/mimehtml.h \
    sendemailapi/mimeinlinefile.h \
    sendemailapi/mimemessage.h \
    sendemailapi/mimemultipart.h \
    sendemailapi/mimepart.h \
    sendemailapi/mimetext.h \
    sendemailapi/quotedprintable.h \
    sendemailapi/smtpclient.h \
    sendemailapi/smtpmime.h \
    receive.h \
    base64.h \
    common.h \
    settings.h \
    bdsimplecrypt.h \
    emailview.h \
    drop_shadow_widget.h

FORMS    += \
    frmmain.ui \
    receive.ui \
    emailview.ui

RESOURCES += \
    res.qrc
RESOURCES += \
    demorc.qrc
