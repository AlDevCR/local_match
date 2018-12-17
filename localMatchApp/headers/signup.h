#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>

/*!
 * The class of user interface type is created to be
 * able to develop the signup window
 */

namespace Ui {
class SignUp;
}

class SignUp : public QDialog
{
    Q_OBJECT

 public:
  explicit SignUp (QWidget *i_parent = nullptr);
  ~SignUp ( );

  /*!
   * The functions of button actions are declared so
   * they can be used later
   */
 private slots:
    /*!
     * The function when the user click the button to save the information
     * in signup window is declare
     */
    void onNewUserButtonClicked ( );

private:
    Ui::SignUp *ui;
};

#endif // SIGNUP_H
