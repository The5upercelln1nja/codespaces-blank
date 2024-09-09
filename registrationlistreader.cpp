#include "registrationlistreader.h"

RegistrationListReader::RegistrationListReader() {}

void RegistrationListReader::ReadXMl()
{

    QFile file("registration_data.xml");
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Error opening file for reading.";
        return;
    }

    QXmlStreamReader readregistrationlist;
    readregistrationlist.setDevice(&file);



    while (!readregistrationlist.atEnd()){

        readregistrationlist.readNext();

        if(readregistrationlist.isStartElement())
        {
            if(readregistrationlist.name().toString()=="registration"){
                qDebug()<<"registrationtype  \n";
                readregistrationlist.readElementText();
            }


        }else if(readregistrationlist.name().toString()=="name")
        {
            qDebug()<<"Name:  \n";
            readregistrationlist.readElementText();
        }else if(readregistrationlist.name().toString()=="affiliation")
        {
            qDebug()<<"Affiliation:  \n";
            readregistrationlist.readElementText();
        }else if(readregistrationlist.name().toString()=="email")
        {
            qDebug()<<"Email:  \n";
            readregistrationlist.readElementText();
        }else if(readregistrationlist.name().toString()=="bookingdate")
        {
            qDebug()<<"Booking Date:  \n";
            readregistrationlist.readElementText();
        }else if(readregistrationlist.name().toString()=="fees")
        {
            qDebug()<<"Fees:  \n";
            readregistrationlist.readElementText();
        }


    }



    if(readregistrationlist.hasError())
    {
        qDebug()<<"Error processing XML document , please check if xml file is open for reading :-("<<readregistrationlist.errorString();
    }
    file.close();
}
