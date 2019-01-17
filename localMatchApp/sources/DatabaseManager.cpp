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
    nameEvent = "New Year Party 2019";
    typeEvent = "Music";
    descriptionEvent = "So perhaps, you've generated some fancy "
                       "text, and you're content that you can now "
                       "copy and paste your fancy text in the "
                       "comments section of funny cat videos, but "
                       "perhaps you're wondering how it's even "
                       "possible to change the font of your text? "
                       "Is it some sort of hack? Are you copying "
                       "and pasting an actual font?";
    initialDateEvent = "16/01/2019 19:00";
    finalDateEvent = "18/01/2019 13:00";
    provinceEvent = "Heredia";
    cantonEvent = "Heredia";
    districtEvent = "San Francisco";
    locationEvent = "Oxigeno Human Playground";
    imageEvent = ":/images/eventExample.svg";

    /*!
     * A variable of type object ClassEvent is created to be able
     * to call the functions of set and get of all variables
     */
    GeneralEvent event;

    event.setIdEvent(idEvent);
    event.setNameEvent(nameEvent);
    event.setTypeEvent ( typeEvent );
    event.setDescriptionEvent(descriptionEvent);
    event.setInitialDateEvent(initialDateEvent);
    event.setFinalDateEvent(finalDateEvent);
    event.setProvinceEvent ( provinceEvent );
    event.setCantonEvent ( cantonEvent );
    event.setDistrictEvent ( districtEvent );
    event.setLocationEvent ( locationEvent );
    event.setImageEvent(imageEvent);
    event.setTotalEvents(totalEvents);

    return event;
}
