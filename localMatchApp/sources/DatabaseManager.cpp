#include "DatabaseManager.h"

DatabaseManager::DatabaseManager(){}

DatabaseManager::~DatabaseManager(){}

GeneralEvent DatabaseManager::selectEvent(int i_index)
{
    ///@TODO In this function is necessary to invoque the database and
    /// change all the default values of sets
    /// With the value "i_index" received in the function you have to
    /// create a sql command with limit like this:
    /// SELECT * FROM events LIMIT i_index,1;
    idEvent = 1;
    totalEvents = 1;
    nameEvent = "New Year Party 2018";
    descriptionEvent = "So perhaps, you've generated some fancy "
                       "text, and you're content that you can now "
                       "copy and paste your fancy text in the "
                       "comments section of funny cat videos, but "
                       "perhaps you're wondering how it's even "
                       "possible to change the font of your text? "
                       "Is it some sort of hack? Are you copying "
                       "and pasting an actual font?";
    initialDateEvent = "13/12/18 18:00";
    finalDateEvent = "14/12/18 13:00";
    imageEvent = ":/images/eventExample.svg";

    /*!
     * A variable of type object ClassEvent is created to be able
     * to call the functions of set and get of all variables
     */
    GeneralEvent event;

    event.setIdEvent(idEvent);
    event.setNameEvent(nameEvent);
    event.setDescriptionEvent(descriptionEvent);
    event.setInitialDateEvent(initialDateEvent);
    event.setFinalDateEvent(finalDateEvent);
    event.setImageEvent(imageEvent);
    event.setTotalEvents(totalEvents);

    return event;
}
