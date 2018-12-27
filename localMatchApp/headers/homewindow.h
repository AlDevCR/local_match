#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QDialog>
#include "GeneralEvent.h"
#include "DatabaseManager.h"
#include <memory>

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
    explicit HomeWindow(QWidget *i_parent = nullptr);
    ~HomeWindow();

    HomeWindow(const HomeWindow &homeWindow) = default;

    HomeWindow& operator = (const HomeWindow &homeWindow) = default;

/*!
 * The functions of button actions are declared so
 * they can be used later
 */
private slots:
    /*!
     * The function when the user click the button of previous event is declare
     */
    void onButtonPreviousClicked();

    /*!
     * The function when the user click the button of next event is declare
     */
    void onButtonNextClicked();

    /*!
     * The function when the user click the button of Subscribe is declare
     */
    void onPushButtonSubscribeClicked();
private:
    /*! It will be used to be able to use all the graphic
     * interface elements of Home Window */
    std::unique_ptr<Ui::HomeWindow> ui;

    /*! It will show the information of the event in the carousel */
    void showInformationCarousel(int i_index);

    /*! It will change the visibility of buttons of previous and
    * next in the carousel */
    void showButtonsCarousel(int i_index);

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

    /*! It saves the value of current index of carousel of events */
    int indexOfCarousel;

    /*! It saves the value that informs the user what is the current event */
    QString eventStatus;

    /*! It saves the value of the name of the user */
    QString userName;

    /*! This variable of type object FunctionsDatabase to use the functions of the database */
    DatabaseManager databaseManager;

    /*! This variable of type object ClassEvent to use the functions of get and set */
    GeneralEvent event;
};

#endif // HOMEWINDOW_H
