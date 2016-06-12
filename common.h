#ifndef COMMON
#define COMMON

#include <QString>
#include <QDateTime>

class Data
{

public:
    static QString admin;
    static QString code;
};


typedef struct EMailDetails{
    QString subject;
    QDateTime    datetime;
    QString fromer;
    QString toer;
    QString sender;
    QString htmlTxt;
    bool       hasAttament;
    QString attaname;
}EMAILDETAILS;

#endif // COMMON

