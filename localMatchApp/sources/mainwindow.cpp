#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "signup.h"
#include "QDesktopWidget"
#include <QMessageBox>
#include <QStyle>
#include "homewindow.h"

/*!
 * In this function is created what is necessary to
 * build the login screen of the system
 */
MainWindow::MainWindow ( QWidget *i_parent ) : QMainWindow ( i_parent ), ui ( std::make_unique<Ui::MainWindow>() )
{
  const int FIXEDWIDTHMAINWINDOW = 500;
  const int FIXEDHEIGHTMAINWINDOW = 450;
  ui->setupUi (this);
  ///@TODO Remove this image from a local directory and store them in the DB
  QPixmap pixLogo (":/images/logo.svg");
  QPixmap pixLogin ( ":/images/loginIcon.svg" );
  QPixmap pixSignup ( ":/images/signupIcon.svg" );
  ui->pictureLogo->setPixmap (pixLogo);
  ui->buttonLogin->setIcon ( pixLogin );
  ui->buttonSignUp->setIcon ( pixSignup );
  this->setFixedWidth (FIXEDWIDTHMAINWINDOW);
  this->setFixedHeight (FIXEDHEIGHTMAINWINDOW);
  this->setGeometry (QStyle::alignedRect (Qt::LeftToRight, Qt::AlignCenter, this->size (),
                                            qApp->desktop ()->availableGeometry ()));
  connect (ui->buttonSignUp, SIGNAL (clicked ()), this, SLOT (onButtonSignUpClicked ()));
  connect (ui->buttonLogin, SIGNAL (clicked ()), this, SLOT (onButtonLoginClicked ()));
}

/*!
 * In this function, the user interface of the login
 * system screen is destroyed
 */

MainWindow::~MainWindow(){}

/*!
 * In this function, if the user clicks the button of signup,
 * the registration window opens
 */

void MainWindow::onButtonSignUpClicked()
{
    /*!
     * It creates and object of type SignUpWindow and show the
     * window if the user click the button
     */
    SignUp signUpWindow;
    signUpWindow.setModal(true);
    signUpWindow.exec();
}

/*!
 * In this function, if the user clicks the button of login,
 * the home window opens
 */

void MainWindow::onButtonLoginClicked()
{
  /*!
   * A variable is created that stores what the function that validates the data entered by the
   * user, returns
   */
  statusLogin = login.entry ( ( ui->lineEditUser->text ( ) ).toStdString ( ),
                              ( ui->lineEditPassword->text ( ) ).toStdString ( ) );

  /*!
   * If the function returns a success message the main screen of the program opens
   */
  if ( statusLogin == Login::ConnectionMessage::goodEntry ) {
    this->hide ( );
    HomeWindow homeWindow;
    homeWindow.setModal ( true );
    homeWindow.exec ( );
    /*!
     * If the function returns an error message, a message box is show to the user
     */
  } else {
    if ( statusLogin == Login::ConnectionMessage::doesntExists ) {
      MessageLoginError = "User is incorrect";
    } else if ( statusLogin == Login::ConnectionMessage::wrongPassword ) {
      MessageLoginError = "Password is incorrect";
    }
    QMessageBox messageBoxIncorrect;
    messageBoxIncorrect.critical ( nullptr, "Error", MessageLoginError );
    messageBoxIncorrect.setFixedSize ( 500, 200 );
  }
}

