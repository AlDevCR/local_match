#ifndef EVENTS_H
#define EVENTS_H

#include <QWidget>

/*!
 * The class of Event is created to
 * be able to develop the functions
 * to manage the variables of the event
 */
class ClassEvent
{
public:
    ClassEvent();

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
    ///@TODO Change the name of the variable to imageEvent when the database is ready
    QString pathImageEvent;

    /*!
     * The functions to set and get the id of the event
     * are declared so they can be used later
     */
    void setIdEvent(int i_valueIdEvent);
    int getIdEvent();

    /*!
     * The functions to set and get the total of events
     * are declared so they can be used later
     */
    void setTotalEvents(int i_valueTotalEvents);
    int getTotalEvents();

    /*!
     * The functions to set and get the name of the event
     * are declared so they can be used later
     */
    void setNameEvent(QString i_valueNameEvent);
    QString getNameEvent();

    /*!
     * The functions to set and get the description of the event
     * are declared so they can be used later
     */
    void setDescriptionEvent(QString i_valueDescriptionEvent);
    QString getDescriptionEvent();

    /*!
     * The functions to set and get the initial date of the event
     * are declared so they can be used later
     */
    void setInitialDateEvent(QString i_valueInitialDateEvent);
    QString getInitialDateEvent();

    /*!
     * The functions to set and get the final date of the event
     * are declared so they can be used later
     */
    void setFinalDateEvent(QString i_valueFinalDateEvent);
    QString getFinalDateEvent();

    /*!
     * The functions to set and get the path of the image of the event
     * are declared so they can be used later
     */
    void setPathImageEvent(QString i_valuePathImageEvent);
    QString getPathImageEvent();
};

#endif // EVENTS_H
