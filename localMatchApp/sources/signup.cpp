#include "../headers/signup.h"
#include "ui_signup.h"
#include "QDesktopWidget"
#include <QMessageBox>
#include <QStyle>

/*!
 * In this function is created what is necessary to build
 * the signup screen of the system
*/
 SignUp::SignUp(QWidget *i_parent) :
    QDialog(i_parent),
    ui(new Ui::SignUp)
{
     const int FIXEDWIDTHSIGNUPWINDOW = 500;
    const int FIXEDHEIGHTSIGNUPWINDOW = 450;
    ui->setupUi(this);
    ui->lineEditNewUser->setPlaceholderText("Username");
    ui->lineEditNewPassword->setPlaceholderText("Password");
    ui->lineEditNewPasswordCheck->setPlaceholderText("Repeat Password");
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
 SignUp::~SignUp()
{
    delete ui;
}

/*!
 * In this function, if the user clicks the button of new user,
 * a message alert of success appears
*/
void  SignUp::onNewUserButtonClicked()
{
    QMessageBox messageNewUser;
    messageNewUser.setWindowTitle("New user");
    messageNewUser.setText("The user has been created successfully");
    messageNewUser.exec();
}
