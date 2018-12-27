#ifndef GENERALEVENT_H
#define GENERALEVENT_H

#include <QWidget>

/*!
 * It is created to
 * be able to develop the functions
 * to manage the variables of the event
 */
class GeneralEvent
{
public:
    GeneralEvent();

    ~GeneralEvent();

    GeneralEvent(const GeneralEvent &event) = default;

    GeneralEvent &operator= (const GeneralEvent &event) = default;

    /*!
     * It sets the id of the event
     */
    void setIdEvent(int i_valueIdEvent);

    /*!
     * It gets the id of the event by the database
     */
    int getIdEvent();

    /*!
     * It sets the total of events
     */
    void setTotalEvents(int i_valueTotalEvents);

    /*!
     * It gets the total of events by the database
     */
    int getTotalEvents();

    /*!
     * It sets the name of the event
     */
    void setNameEvent(QString i_valueNameEvent);

    /*!
     * It gets the name of the event by the database
     */
    QString getNameEvent();

    /*!
     * It sets the description of the event
     */
    void setDescriptionEvent(QString i_valueDescriptionEvent);

    /*!
     * It gets the description of the event by the database
     */
    QString getDescriptionEvent();

    /*!
     * It sets the initial date of the event
     */
    void setInitialDateEvent(QString i_valueInitialDateEvent);

    /*!
     * It gets the initial date of the event by the database
     */
    QString getInitialDateEvent();

    /*!
     * It sets the final date of the event
     */
    void setFinalDateEvent(QString i_valueFinalDateEvent);

    /*!
     * It gets the final date of the event by the database
     */
    QString getFinalDateEvent();

    /*!
     * It sets the image of the event
     */
    void setImageEvent(QString i_valuePathImageEvent);

    /*!
     * It gets the image of the event by the database
     */
    QString getImageEvent();

private:
    /*! It saves the id of the event */
    int idEvent;

    /*! It saves the total of the events */
    int totalEvents;

    /*! It saves the name of the event */
    QString nameEvent;

    /*! It saves the description of the event */
    QString descriptionEvent;

    /*! It saves the initial date of the event */
    QString initialDateEvent;

    /*! It saves the final date of the event */
    QString finalDateEvent;

    /*! It saves the path of the image of the event */
    ///@TODO Change the name of the variable to imageEvent when the database is ready
    QString imageEvent;
};

#endif // GENERALEVENT_H
