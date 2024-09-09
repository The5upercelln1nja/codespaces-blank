#ifndef REGISTRATIONLISTREADER_H
#define REGISTRATIONLISTREADER_H


#include <QXmlStreamReader>
#include <QDebug>
#include <QString>
#include <QFile>


class RegistrationListReader
{
public:
    RegistrationListReader();
    void ReadXMl();
};

#endif // REGISTRATIONLISTREADER_H
