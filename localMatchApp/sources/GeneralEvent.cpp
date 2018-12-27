#include "GeneralEvent.h"

GeneralEvent::GeneralEvent()
{
    idEvent = 0;
    totalEvents = 0;
    nameEvent = "";
    descriptionEvent = "";
    initialDateEvent = "";
    finalDateEvent = "";
    imageEvent = "";
}

GeneralEvent::~GeneralEvent(){}

void GeneralEvent::setIdEvent(int i_valueIdEvent)
{
    idEvent = i_valueIdEvent;
}
int GeneralEvent::getIdEvent()
{
    return idEvent;
}

void GeneralEvent::setTotalEvents(int i_valueTotalEvents)
{
    totalEvents = i_valueTotalEvents;
}
int GeneralEvent::getTotalEvents()
{
    return totalEvents;
}

void GeneralEvent::setNameEvent(QString i_valueNameEvent)
{
    nameEvent = i_valueNameEvent;
}
QString GeneralEvent::getNameEvent()
{
    return nameEvent;
}

void GeneralEvent::setDescriptionEvent(QString i_valueDescriptionEvent)
{
    descriptionEvent = i_valueDescriptionEvent;
}
QString GeneralEvent::getDescriptionEvent()
{
    return descriptionEvent;
}

void GeneralEvent::setInitialDateEvent(QString i_valueInitialDateEvent)
{
    initialDateEvent = i_valueInitialDateEvent;
}
QString GeneralEvent::getInitialDateEvent()
{
    return initialDateEvent;
}

void GeneralEvent::setFinalDateEvent(QString i_valueFinalDateEvent)
{
    finalDateEvent = i_valueFinalDateEvent;
}
QString GeneralEvent::getFinalDateEvent()
{
    return finalDateEvent;
}

void GeneralEvent::setImageEvent(QString i_valueImageEvent)
{
    imageEvent = i_valueImageEvent;
}
QString GeneralEvent::getImageEvent()
{
    return imageEvent;
}
