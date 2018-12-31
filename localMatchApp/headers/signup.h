#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include <memory>
#include "Login.h"

/*!
 * It is created to be
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

  SignUp ( const SignUp& signUp ) = default;

  SignUp& operator= ( const SignUp& signUp ) = default;

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
 /*! It will be used to be able to use all the graphic
  * interface elements of Sign Up Window */
 std::unique_ptr< Ui::SignUp > ui;

 /*! This variable of type object Login to use the function that
  * validate the data entry by the user */
 Login login;

 /*! This variable of type object Connection Message to save the status of the function signup */
 Login::ConnectionMessage statusSignUp;

 /*! It saves the error message that will show to the user */
 QString MessageSignUpError;
};

#endif // SIGNUP_H
