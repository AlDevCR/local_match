#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLineEdit>
#include <QMainWindow>
#include <memory>
#include "Login.h"

/*!
 * It is created to be able
 * to develop the login window
 */

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
  explicit MainWindow(QWidget *i_parent = nullptr);
  ~MainWindow();

  MainWindow ( const MainWindow &mainWindow ) = default;

  MainWindow &operator= ( const MainWindow &mainWindow ) = default;

  /*!
  * The functions of button actions are declared so
  * they can be used later
  */
private slots:
  /*!
  * The function when the user click the button to sign up is declared
  */
  void onButtonSignUpClicked ( );

  /*!
  * The function when the user click the button to log in is declared
  */
  void onButtonLoginClicked ( );

private:

  /*! This variable of type object Login to use the function that
  * validate the data entry by the user */
  Login login;

 /*! It will be used to be able to use all the graphic
  * interface elements of Main Window */
 std::unique_ptr< Ui::MainWindow > ui;

 /*! This variable of type object Connection Message to save the status of the function login */
 Login::ConnectionMessage statusLogin;

 /*! It saves the error message that will show to the user */
 QString MessageLoginError;
};

#endif // MAINWINDOW_H
