#ifndef EVENTS_H
#define EVENTS_H

#include <QWidget>

/*!
 * The class of Event is created to
 * be able to develop the functions
 * to manage the variables of the event
 */
class Events
{
public:
    Events();

    int idEvent;
    int totalEvents;
    QString nameEvent;
    QString descriptionEvent;
    QString initialDateEvent;
    QString finalDateEvent;
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
