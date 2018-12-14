#include "../headers/functions.h"


Functions::Functions(){
}

/*!
 * The function to select the information of the events
 * needed by the home user interface of the events
 */
Events Functions::SelectEvent(int i_index){
    ///@TODO In this function is necessary to invoque the database and
    /// change all the default values of sets
    /// With the value "i_index" received in the function you have to
    /// create a sql command with limit like this:
    /// SELECT * FROM events LIMIT i_index,1;
    Events event;
    event.setIdEvent(1);
    event.setNameEvent("New Year Party 2018");
    event.setDescriptionEvent("So perhaps, you've generated some fancy "
                                  "text, and you're content that you can now "
                                  "copy and paste your fancy text in the "
                                  "comments section of funny cat videos, but "
                                  "perhaps you're wondering how it's even "
                                  "possible to change the font of your text? "
                                  "Is it some sort of hack? Are you copying "
                                  "and pasting an actual font?");
    event.setInitialDateEvent("13/12/18 18:00");
    event.setFinalDateEvent("14/12/18 13:00");
    event.setPathImageEvent(":/images/eventExample.svg");
    event.setTotalEvents(1);
    return event;
}
