#include "../headers/mainwindow.h"
#include "ui_mainwindow.h"
#include "../headers/signup.h"
#include "../headers/homewindow.h"
#include "QDesktopWidget"
#include <QMessageBox>
#include <QStyle>

/*!
 * In this function is created what is necessary to
 * build the login screen of the system
*/
MainWindow::MainWindow(QWidget *i_parent) :
    QMainWindow(i_parent),
    ui(new Ui::MainWindow)
{
    const int FIXEDWIDTHMAINWINDOW = 500;
    const int FIXEDHEIGHTMAINWINDOW = 450;
    ui->setupUi(this);
    QPixmap pix (":/images/logo.svg");
    ui->pictureLogo->setPixmap(pix);
    this->setFixedWidth(FIXEDWIDTHMAINWINDOW);
    this->setFixedHeight(FIXEDHEIGHTMAINWINDOW);
    this->setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            this->size(),
            qApp->desktop()->availableGeometry()
        )
    );
    connect(ui->buttonSignUp,SIGNAL(clicked()), this,
            SLOT(onButtonSignUpClicked()));
    connect(ui->buttonLogin,SIGNAL(clicked()), this,
            SLOT(onButtonLoginClicked()));
}

/*!
 * In this function, the user interface of the login
 * system screen is destroyed
*/
MainWindow::~MainWindow()
{
    delete ui;
}

/*!
 * In this function, if the user clicks the button of signup,
 * the registration window opens
*/
void MainWindow::onButtonSignUpClicked()
{
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
    this->hide();
    HomeWindow homeWindow;
    homeWindow.setModal(true);
    homeWindow.exec();

}

