#include "DatabaseManager.h"

DatabaseManager::DatabaseManager(){}

DatabaseManager::~DatabaseManager(){}

GeneralEvent DatabaseManager::selectEvent(Activity i_activityIndexed , const int numberOfEvents)
{

    idEvent = i_activityIndexed.getCode().toInt();
    totalEvents = numberOfEvents;
    nameEvent = i_activityIndexed.getActivityName();
    descriptionEvent = i_activityIndexed.getActivityDescription();
    initialDateEvent = i_activityIndexed.getInitialDate();
    finalDateEvent = i_activityIndexed.getFinalDate();
    imageEvent = i_activityIndexed.getImageActivity();

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
