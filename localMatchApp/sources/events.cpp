#include "../headers/events.h"

Events::Events(){
    idEvent=0;
}

/*!
 * The functions to set the id of the event
 * and get the id by the database
 */
void Events::setIdEvent(int i_valueIdEvent){
    idEvent = i_valueIdEvent;
}
int Events::getIdEvent(){
    return idEvent;
}

/*!
 * The functions to set the total of events
 * and get the total of events by the database
 */
void Events::setTotalEvents(int i_valueTotalEvents){
    totalEvents = i_valueTotalEvents;
}
int Events::getTotalEvents(){
    return totalEvents;
}

/*!
 * The functions to set the name of the event
 * and get the name by the database
 */
void Events::setNameEvent(QString i_valueNameEvent){
    nameEvent = i_valueNameEvent;
}
QString Events::getNameEvent(){
    return nameEvent;
}

/*!
 * The functions to set the description of the event
 * and get the description by the database
 */
void Events::setDescriptionEvent(QString i_valueDescriptionEvent){
    descriptionEvent = i_valueDescriptionEvent;
}
QString Events::getDescriptionEvent(){
    return descriptionEvent;
}

/*!
 * The functions to set the initial date of the event
 * and get the initial date by the database
 */
void Events::setInitialDateEvent(QString i_valueInitialDateEvent){
    initialDateEvent = i_valueInitialDateEvent;
}
QString Events::getInitialDateEvent(){
    return initialDateEvent;
}

/*!
 * The functions to set the final date of the event
 * and get the final date by the database
 */
void Events::setFinalDateEvent(QString i_valueFinalDateEvent){
    finalDateEvent = i_valueFinalDateEvent;
}
QString Events::getFinalDateEvent(){
    return finalDateEvent;
}

/*!
 * The functions to set the path of the image of the event
 * and get the path by the database
 */
void Events::setPathImageEvent(QString i_valuePathImageEvent){
    pathImageEvent = i_valuePathImageEvent;
}
QString Events::getPathImageEvent(){
    return pathImageEvent;
}
