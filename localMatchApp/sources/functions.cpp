#include "../headers/functions.h"

Functions::Functions(){
}

Events Functions::SelectEvent(int i_index){
    Events event;
    switch (i_index) {
        case 0:
        {
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
            event.setPathImageEvent(":/images/eventExample1.svg");
            event.setTotalEvents(3);
            break;
        }
        case 1:
        {
            event.setIdEvent(2);
            event.setNameEvent("STAND UP COMEDY DE HERNAN JIMENEZ 2019");
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
            event.setPathImageEvent(":/images/eventExample2.svg");
            event.setTotalEvents(3);
            break;
        }
        case 2:
        {
            event.setIdEvent(3);
            event.setNameEvent("MONSTER JAM");
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
            event.setPathImageEvent(":/images/eventExample3.svg");
            event.setTotalEvents(3);
            break;
        }
    }
    return event;
}
