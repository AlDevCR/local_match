#include "../headers/homewindow.h"
#include <QStyle>
#include "ui_homewindow.h"

/*!
 * In this function is created what is necessary
 * to build the main screen of the system
 */
HomeWindow::HomeWindow ( QWidget *i_parent ) : QDialog ( i_parent ), ui ( new Ui::HomeWindow ) {
  const int WIDTHSIZELOGO = 150;
  const int HEIGHTSIZELOGO = 24;
  ui->setupUi ( this );
  QPixmap pixEvent ( ":/images/eventExample.svg" );
  QPixmap pixUser ( ":/images/user.svg" );
  QPixmap pixLogo ( ":/images/logo.svg" );
  pixLogo = pixLogo.scaled ( WIDTHSIZELOGO, HEIGHTSIZELOGO, Qt::KeepAspectRatio,
                             Qt::SmoothTransformation );
  ui->pictureEvent->setPixmap ( pixEvent );
  ui->pictureUser->setPixmap ( pixUser );
  ui->pictureLogo->setPixmap ( pixLogo );
  ui->labelNameUser->setText ( "User Name" );
  ui->labelNameEvent->setText ( "New Year Party 2018" );
  ui->labelNameEvent->setStyleSheet ( "font-weight: bold;" );
  ui->labelDateEvent->setText ( "05/12/2018" );
  ui->labelDateEvent->setStyleSheet (
      "font-weight: bold; color: "
      "rgb(187, 205, 225);" );
  ui->labelHourEvent->setText ( "18:00 - 23:00" );
  ui->labelHourEvent->setStyleSheet (
      "font-weight: bold; color: "
      "rgb(187, 205, 225);" );
  ui->labelDescription->setWordWrap ( true );
  ui->labelDescription->setText (
      "So perhaps, you've generated some fancy "
      "text, and you're content that you can now "
      "copy and paste your fancy text in the "
      "comments section of funny cat videos, but "
      "perhaps you're wondering how it's even "
      "possible to change the font of your text? "
      "Is it some sort of hack? Are you copying "
      "and pasting an actual font?" );
}

/*!
 * In this function, the user interface of the
 * main system screen is destroyed
 */
HomeWindow::~HomeWindow ( ) {
  delete ui;
}
