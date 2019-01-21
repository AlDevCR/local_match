#include "signup.h"
#include "ui_signup.h"
#include "QDesktopWidget"
#include <QMessageBox>
#include <QStyle>

/*!
 * In this function is created what is necessary to build
 * the signup screen of the system
 */
SignUp::SignUp(QWidget *i_parent , Login& login) :
    QDialog(i_parent),
    ui(new Ui::SignUp)
{
    this->login=login;
    const int FIXEDWIDTHSIGNUPWINDOW = 500;
    const int FIXEDHEIGHTSIGNUPWINDOW = 450;

    ui->setupUi(this);

    ///@TODO Remove this image from a local directory and store them in the DB
    QPixmap pixLogo (":/images/logo.svg");
    ui->pictureLogo->setPixmap(pixLogo);

    this->setFixedWidth(FIXEDWIDTHSIGNUPWINDOW);
    this->setFixedHeight(FIXEDHEIGHTSIGNUPWINDOW);
    this->setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            this->size(),
            qApp->desktop()->availableGeometry()
        )
    );

    connect(ui->NewUserButton,SIGNAL(clicked()), this,
            SLOT(onNewUserButtonClicked()));
}

/*!
 * In this function, the user interface of the signup
 * system screen is destroyed
 */

SignUp::~SignUp(){}

/*!
 * In this function, if the user clicks the button of new user,
 * a message alert of success appears
 */

void SignUp::onNewUserButtonClicked()
{
  /*!
   * A variable is created that stores what the function that validates the data entered by the
   * user, returns
   */
  statusSignUp = login.signUp ( ( ui->lineEditUserName->text ( ) ).toStdString ( ),
                                ( ui->lineEditName->text ( ) ).toStdString ( ),
                                ( ui->lineEditLastName->text ( ) ).toStdString ( ),
                                ( ui->lineEditNewPassword->text ( ) ).toStdString ( ),
                                ( ui->lineEditNewPasswordCheck->text ( ) ).toStdString ( ) );

  /*!
   * If the function returns a success message the main screen of the program opens
   */
  if ( statusSignUp == Login::ConnectionMessage::goodEntry ) {
    QMessageBox messageNewUser;
    messageNewUser.setWindowTitle ( "New user" );
    messageNewUser.setText ( "The user has been created successfully" );
    messageNewUser.exec ( );
    this->close ( );
    /*!
     * If the function returns an error message, a message box is show to the user
     */
  } else {
    if ( statusSignUp == Login::ConnectionMessage::invalidUser ) {
      MessageSignUpError = "User is incorrect";
    } else if ( statusSignUp == Login::ConnectionMessage::invalidName ) {
      MessageSignUpError = "Name is incorrect";
    } else if ( statusSignUp == Login::ConnectionMessage::invalidLastName ) {
      MessageSignUpError = "Last Name is incorrect";
    } else if ( statusSignUp == Login::ConnectionMessage::wrongPassword ) {
      MessageSignUpError = "Password is incorrect: Use at least one capital letter, one small letter and one number";
    } else if ( statusSignUp == Login::ConnectionMessage::notEqualPasswords ) {
      MessageSignUpError = "Passwords are not equal";
    }
    QMessageBox messageBoxIncorrect;
    messageBoxIncorrect.critical ( nullptr, "Error", MessageSignUpError );
    messageBoxIncorrect.setFixedSize ( 500, 200 );
  }
}
