#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QDialog>
#include "classevent.h"

/*!
 * The class of user interface type is created to
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
  Ui::HomeWindow *ui;
  /*! Declaration of the function that manage the events of the carousel */
  void manageCarousel(int i_index);
  /*! Declaration of the constant that save the value to check if the are no events */
  const int NOEVENTS = 0;
  /*! Declaration of the constant that save the value to check if the current event
   * in carousel is the first */
  const int FIRSTEVENT = 0;
  /*! Declaration of the constant that save the value to check if there is only one event */
  const int ONEEVENT = 1;
  /*! Declaration of the constant that save the value of width size of the logo image */
  const int WIDTHSIZELOGO = 150;
  /*! Declaration of the constant that save the value of height size of the logo image */
  const int HEIGHTSIZELOGO = 24;
  /*! Declaration of the variable that save the value of current index of carousel of events */
  int indexOfCarousel;
  /*! Declaration of the variable that save the value that informs the user what is the current event */
  QString eventStatus;
  ClassEvent event;

};

#endif // HOMEWINDOW_H
