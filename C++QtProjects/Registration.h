//Registration App is a project built from various sub header files Please ensure you have Cmake on your code workspace
//Header File for Registration App and its children

//Person.h
#ifndef PERSON_H
#define PERSON_H
#include <QString>//Project uses Qt 6.7 Core 
class Person
{    //by default in C++, all attributes are private
    QString m_Name, m_Affiliation, m_Email;
public:
    Person();
     Person(QString n, QString a, QString e);
    QString setName(QString nam){m_Name=nam;}
    QString getName() const { return m_Name; }
    QString setAffiliation(QString aff){m_Affiliation=aff;}
    QString getAffiliation() const { return m_Affiliation; }
    QString setEmail(QString em){m_Email=em;}
    QString getEmail() const { return m_Email; }
    QString toString();

};//Project built using Qt6.7 in collaboration with Microsoft CoPilot AI

#endif // PERSON_H
//Registration.h uses person.h A person uses Registration to register
#ifndef REGISTRATION_H
#define REGISTRATION_H
#include "person.h"
#include <QDate>
#include <QObject>


class Registration:public QObject//contains information for student or guest to register for

{
    Q_OBJECT
    Person m_Attendee;
    QDate m_BookingDate;
    double m_Fee;

public:
    Registration();
    virtual QString registrationType()const {return "Standard Registration";}//Metaobject pointer to registration
    double const STANDARD_FEE=1370.5;//The standard fee for this conference is R 1370.50 , this will be a static variable
    Registration(Person a);
    Registration(QString name, QString affiliation, QString email, QDate date, QString registrationType);
    double setFee(double fe){m_Fee=fe;}//setter for fee
    Person getAttendee() const {return m_Attendee;}
    QDate getBookingDate() const { return m_BookingDate;}//This getter method has been modified to allow user selected date from Qcalendar to be used
    virtual double calculateFee() const;//Calculates the fee a guest or student has to pay
    virtual QString toString();

};

#endif // REGISTRATION_H
//Guest and student are children of registtraion