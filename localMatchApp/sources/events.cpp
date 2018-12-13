#include "../headers/events.h"

Events::Events(){
}

/*!
 * The functions to set and get the id of the event
 * are declared so they can be used later
 */
void Events::setIdEvent(int i_valueIdEvent){
    idEvent = i_valueIdEvent;
}
int Events::getIdEvent(){
    return idEvent;
}

void Events::setTotalEvents(int i_valueTotalEvents){
    totalEvents = i_valueTotalEvents;
}
int Events::getTotalEvents(){
    return totalEvents;
}

void Events::setNameEvent(QString i_valueNameEvent){
    nameEvent = i_valueNameEvent;
}
QString Events::getNameEvent(){
    return nameEvent;
}

void Events::setDescriptionEvent(QString i_valueDescriptionEvent){
    descriptionEvent = i_valueDescriptionEvent;
}
QString Events::getDescriptionEvent(){
    return descriptionEvent;
}

void Events::setInitialDateEvent(QString i_valueInitialDateEvent){
    initialDateEvent = i_valueInitialDateEvent;
}
QString Events::getInitialDateEvent(){
    return initialDateEvent;
}

void Events::setFinalDateEvent(QString i_valueFinalDateEvent){
    finalDateEvent = i_valueFinalDateEvent;
}
QString Events::getFinalDateEvent(){
    return finalDateEvent;
}

void Events::setPathImageEvent(QString i_valuePathImageEvent){
    pathImageEvent = i_valuePathImageEvent;
}
QString Events::getPathImageEvent(){
    return pathImageEvent;
}
