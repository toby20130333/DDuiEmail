QT     += network widgets

INCLUDEPATH +=$$PWD

SOURCES +=  \
    $$PWD/mainwindow.cpp \
    pop3/emailinfo.cpp \
    pop3/customviewitem.cpp \
    pop3/elidedlabel.cpp \
    pop3/listviewdelegate.cpp \
    pop3/elistview.cpp
HEADERS += $$PWD/mainwindow.h \
    pop3/emailinfo.h \
    pop3/customviewitem.h \
    pop3/elidedlabel.h \
    pop3/listviewdelegate.h \
    pop3/elistview.h
FORMS += $$PWD/mainwindow.ui \
    pop3/emailinfo.ui \
    pop3/customviewitem.ui
