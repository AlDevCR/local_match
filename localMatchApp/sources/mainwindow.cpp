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
  ui->pictureLogo->setPixmap (pixLogo);
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
     * It creates and object of type HomeWindow and show the
     * window if the user click the button and hide the current window
     */
    this->hide();
    HomeWindow homeWindow;
    homeWindow.setModal(true);
    homeWindow.exec();
}

