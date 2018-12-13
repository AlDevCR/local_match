#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QDialog>

/*!
 * The class of user interface type is created to
 * be able to develop the main screen
 */
namespace Ui {
class HomeWindow;
}

class HomeWindow : public QDialog {
  Q_OBJECT

 public:
  explicit HomeWindow ( QWidget *i_parent = nullptr );
  ~HomeWindow ( );

/*!
 * The functions of button actions are declared so
 * they can be used later
 */
private slots:
    void onButtonPreviousClicked();
    void onButtonNextClicked();

private:
  Ui::HomeWindow *ui;
  int index = 0;
  QString eventStatus;
};

#endif // HOMEWINDOW_H
