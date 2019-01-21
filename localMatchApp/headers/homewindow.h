#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QDialog>
#include <memory>
#include "DatabaseManager.h"
#include "GeneralEvent.h"
#include "Login.h"

/*!
 * It is created to
 * be able to develop the main screen
 */

namespace Ui {
class HomeWindow;
}

class HomeWindow : public QDialog
{
    Q_OBJECT

public:
 /*! Type of the current user using the software */
 enum class TypeOfUser { personalUser, commercialUser, administratorUser };
 explicit HomeWindow(QWidget *i_parent ,Login& login);

 ~HomeWindow();

 HomeWindow ( const HomeWindow &homeWindow ) = default;

 HomeWindow &operator= ( const HomeWindow &homeWindow ) = default;

 /*!
  * The functions of button actions are declared so
  * they can be used later
  */
private slots:
 /*!
  * The function when the user click the button of previous event is declared
  */
 void onButtonPreviousClicked ( );

 /*!
  * The function when the user click the button of next event is declared
  */
 void onButtonNextClicked ( );

 /*!
  * The function when the user click the button of Subscribe is declared
  */
 void onButtonSubscribeClicked ( );

 /*!
  * The function when the user click the button of new image is declared
  */
 void onButtonNewImageClicked ( );

 /*!
  * The function when the user click the button of logout close the program is declared
  */
 void onButtonLogOutClicked ( );

 /*!
  * The function when the user click the button of new event is declared
  */
 void onButtonNewEventClicked ( );

 /*!
  * The function when the user click the button of modify event is declared
  */
 void onButtonModifyEventClicked ( );

 /*!
  * The function when the user click the button of delete event is declared
  */
 void onButtonDeleteEventClicked ( );

 /*!
  * The function when the user click the button of update event is declared
  */
 void onButtonUpdateEventClicked ( );

 /*!
  * The function when the user click the button of cancel is declared
  */
 void onButtonCancelClicked ( );

private:
    Login connectionToDatabase;
    /*! It will be used to be able to use all the graphic
    * interface elements of Home Window */
    std::unique_ptr<Ui::HomeWindow> ui;

 /*! It will show the information of the event in the carousel */
 void showInformationCarousel ( int i_index );

 /*! It will change the visibility of buttons of previous and
  * next in the carousel */
 void showButtonsCarousel ( int i_index );

 /*! It will assign the values of the event in variables */
 void assignValuesEvent ( GeneralEvent i_event );

 /*! It saves the value to check if the are no events */
 const int NOEVENTS = 0;

 /*! It saves the value to check if the current event
  * in carousel is the first */
 const int FIRSTEVENT = 0;

 /*! It saves the value to check if there is only one event */
 const int ONEEVENT = 1;

 /*! It saves the value of width size of the logo image */
 const int WIDTHSIZELOGO = 150;

 /*! It saves the value of height size of the logo image */
 const int HEIGHTSIZELOGO = 24;

 /*! It saves the value of width size of the event image */
 const int WIDTHSIZEIMAGEEVENT = 300;

 /*! It saves the value of height size of the event image */
 const int HEIGHTSIZEIMAGEEVENT = 230;

 /*! It saves the value of current index of carousel of events */
 int indexOfCarousel;

 /*! It saves the id of the event */
 int idEvent;

 /*! It saves the total of the events */
 int totalEvents;

 /*! It saves the value of the type of the user */
 int typeUser;

 /*! It saves the name of the event */
 QString nameEvent;

 /*! It saves the type of the event */
 QString typeEvent;

 /*! It saves the description of the event */
 QString descriptionEvent;

 /*! It saves the initial date of the event */
 QString initialDateEvent;

 /*! It saves the final date of the event */
 QString finalDateEvent;

 /*! It saves the province of the event */
 QString provinceEvent;

 /*! It saves the canton of the event */
 QString cantonEvent;

 /*! It saves the district of the event */
 QString districtEvent;

 /*! It saves the location of the event */
 QString locationEvent;

 /*! It saves the image of the event */
 QString imageEvent;

 /*! It saves the value that informs the user what is the current event */
 QString eventStatus;

 /*! It saves the value of the name of the user */
 QString userName;

 /*! It saves the path of the new image of event to show to the user before insert a new event */
 QString tempImageEvent;

 /*! It saves the list of type of events */
 QStringList listTypeEvents;

 /*! It saves the list of all provinces */
 QStringList listProvinces;

 /*! It saves the list of all cantons */
 QStringList listCantons;

 /*! It saves the list of all districts */
 QStringList listDistricts;

 /*! This variable of type object FunctionsDatabase to use the functions of the database */
 DatabaseManager databaseManager;

 /*! This variable of type object ClassEvent to use the functions of get and set */
 GeneralEvent event;

 /*! This variable of type enum Type User to save the current user */
 TypeOfUser typeOfUser;
};

#endif // HOMEWINDOW_H
