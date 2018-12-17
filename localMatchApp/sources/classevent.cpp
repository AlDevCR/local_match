#include "../headers/classevent.h"

ClassEvent::ClassEvent(){
    idEvent = 0;
    totalEvents = 0;
    nameEvent = "";
    descriptionEvent = "";
    initialDateEvent = "";
    finalDateEvent = "";
    pathImageEvent = "";
}

/*!
 * The functions to set the id of the event
 * and get the id by the database
 */
void ClassEvent::setIdEvent(int i_valueIdEvent){
    idEvent = i_valueIdEvent;
}
int ClassEvent::getIdEvent(){
    return idEvent;
}

/*!
 * The functions to set the total of events
 * and get the total of events by the database
 */
void ClassEvent::setTotalEvents(int i_valueTotalEvents){
    totalEvents = i_valueTotalEvents;
}
int ClassEvent::getTotalEvents(){
    return totalEvents;
}

/*!
 * The functions to set the name of the event
 * and get the name by the database
 */
void ClassEvent::setNameEvent(QString i_valueNameEvent){
    nameEvent = i_valueNameEvent;
}
QString ClassEvent::getNameEvent(){
    return nameEvent;
}

/*!
 * The functions to set the description of the event
 * and get the description by the database
 */
void ClassEvent::setDescriptionEvent(QString i_valueDescriptionEvent){
    descriptionEvent = i_valueDescriptionEvent;
}
QString ClassEvent::getDescriptionEvent(){
    return descriptionEvent;
}

/*!
 * The functions to set the initial date of the event
 * and get the initial date by the database
 */
void ClassEvent::setInitialDateEvent(QString i_valueInitialDateEvent){
    initialDateEvent = i_valueInitialDateEvent;
}
QString ClassEvent::getInitialDateEvent(){
    return initialDateEvent;
}

/*!
 * The functions to set the final date of the event
 * and get the final date by the database
 */
void ClassEvent::setFinalDateEvent(QString i_valueFinalDateEvent){
    finalDateEvent = i_valueFinalDateEvent;
}
QString ClassEvent::getFinalDateEvent(){
    return finalDateEvent;
}

/*!
 * The functions to set the path of the image of the event
 * and get the path by the database
 */
void ClassEvent::setPathImageEvent(QString i_valuePathImageEvent){
    pathImageEvent = i_valuePathImageEvent;
}
QString ClassEvent::getPathImageEvent(){
    return pathImageEvent;
}
