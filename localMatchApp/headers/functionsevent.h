#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "classevent.h"

/*!
 * The class of functions is created to
 * be able to develop the functions
 * that will manage the database
 */
class FunctionsEvent
{
public:
    FunctionsEvent();

    /*! Declaration of the variable that saves the id of the event */
    int idEvent;
    /*! Declaration of the variable that saves the total of the events */
    int totalEvents;
    /*! Declaration of the variable that saves the name of the event */
    QString nameEvent;
    /*! Declaration of the variable that saves the description of the event */
    QString descriptionEvent;
    /*! Declaration of the variable that saves the initial date of the event */
    QString initialDateEvent;
    /*! Declaration of the variable that saves the final date of the event */
    QString finalDateEvent;
    /*! Declaration of the variable that saves the path of the image of the event */
    ///@TODO Change the name of the variable to imageEvent when the database is r
    QString pathImageEvent;

    /*!
     * The function to select all the
     * information of the events
     */
    ClassEvent selectEvent(int i_index);
};

#endif // FUNCTIONS_H
