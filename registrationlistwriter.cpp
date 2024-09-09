#include "registrationlistwriter.h"

RegistrationListWriter::RegistrationListWriter() {}
void RegistrationListWriter::writeRegistrationList() {
    //creation of the xml file and its root element
    QDomDocument RegistrationXmldoc;
    QDomElement rootelement = RegistrationXmldoc.createElement("registrationlist");
    RegistrationXmldoc.appendChild(rootelement);

    for (const Registration *reg : m_AttendeeList) {
        QDomElement regelement = RegistrationXmldoc.createElement("registration");
        QDomText regtextnode = RegistrationXmldoc.createTextNode(reg->registrationType());

        QDomElement attendeelement = RegistrationXmldoc.createElement("attendee");
        QDomText atttextnode = RegistrationXmldoc.createTextNode(reg->getAttendee().getName());



        QDomElement namelement = RegistrationXmldoc.createElement("name");
        QDomText nametextnode = RegistrationXmldoc.createTextNode(registrant->getName());

        QDomElement affiliationelement = RegistrationXmldoc.createElement("affiliation");
        QDomText affiliationTextnode = RegistrationXmldoc.createTextNode(registrant->getAffiliation());

        QDomElement emailElement = RegistrationXmldoc.createElement("email");
        QDomText emailTextnode = RegistrationXmldoc.createTextNode(registrant->getEmail());

        QDomElement bookingDateElement = RegistrationXmldoc.createElement("bookingdate");
        QDomText bookingdateTextnode = RegistrationXmldoc.createTextNode(reg->getBookingDate().toString());

        QDomElement feeElement = RegistrationXmldoc.createElement("fees");
        QDomText feeTextNode = RegistrationXmldoc.createTextNode(QString::number(reg->calculateFee()));

        //adding elements part of attendee
        regelement.appendChild(regtextnode);
        attendeelement.appendChild(atttextnode);
        namelement.appendChild(nametextnode);
        affiliationelement.appendChild(affiliationTextnode);
        emailElement.appendChild(emailTextnode);
        bookingDateElement.appendChild(bookingdateTextnode);
        feeElement.appendChild(feeTextNode);

        QString xmlfilename = QFileDialog::getSaveFileName(0, "Save RegistrationList", "", "XML Files (*.xml);;All Files(*)");
        if (xmlfilename.isEmpty()) {
            qDebug() << "No file name provided..";
            return;
        }

        QFile file(xmlfilename);
        if (!file.open(QIODevice::WriteOnly)) {
            qDebug() << "Error opening file for writing.";
            return;
        }

        QTextStream out(&file);
        out << RegistrationXmldoc.toString(); // Write the XML content
        file.close(); // Close the file
    }
}
