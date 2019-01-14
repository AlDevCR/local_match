#include "homewindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QStyle>
#include "ui_homewindow.h"

/*!
 * It is created all that is necessary
 * to build the main screen of the system
 */
HomeWindow::HomeWindow ( QWidget *i_parent ) : QDialog ( i_parent ), ui ( std::make_unique<Ui::HomeWindow>() )
{
    ui->setupUi(this);
    ///@TODO Change this default value to the data by DB
    /*!
    1 = Personal user
    2 = Commercial user
    3 = Administrator user
    */
    typeUser = 2;

    if ( typeUser == 1 ) {
      typeOfUser = TypeOfUser::personalUser;
    } else if ( typeUser == 2 ) {
      typeOfUser = TypeOfUser::commercialUser;
    } else if ( typeUser == 3 ) {
      typeOfUser = TypeOfUser::administratorUser;
    }

    /*! It is initialized with zero because the carousel
     * will begin with the first position */
    indexOfCarousel = 0;

    /*! It shows information in the carousel is called and the index value is sent */
    showInformationCarousel(indexOfCarousel);

    /*! It shows buttons in the carousel is called and the index value is sent */
    showButtonsCarousel(indexOfCarousel);

    /*! If the user type is personal the area of manage event is not visible */
    if ( typeOfUser == TypeOfUser::personalUser ) {
      ui->labelTypeUser->setText ( "Personal Account" );
      ui->groupBoxManageEvent->setVisible ( false );
      ui->labelMyEvents->setVisible ( true );
      ui->listWidgetEvents->setVisible ( true );
      ui->ButtonModify->setVisible ( false );
      ui->ButtonDelete->setVisible ( false );
      ui->ButtonSubscribe->setVisible ( true );
      /*! If the user type is commercial the area of manage event is visible */
    } else if ( typeOfUser == TypeOfUser::commercialUser ) {
      ui->labelTypeUser->setText ( "Commercial Account" );
      ui->groupBoxManageEvent->setVisible ( true );
      ui->labelMyEvents->setVisible ( false );
      ui->listWidgetEvents->setVisible ( false );
      ui->groupBoxEvent->setTitle ( "My Events" );
      ui->ButtonModify->setVisible ( true );
      ui->ButtonDelete->setVisible ( true );
      ui->ButtonSubscribe->setVisible ( false );
      /*! If the user type is administrator the area of manage event is visible */
    } else if ( typeOfUser == TypeOfUser::administratorUser ) {
      ui->labelTypeUser->setText ( "Administrator Account" );
      ui->groupBoxManageEvent->setVisible ( true );
      ui->labelMyEvents->setVisible ( false );
      ui->listWidgetEvents->setVisible ( false );
      ui->ButtonModify->setVisible ( false );
      ui->ButtonDelete->setVisible ( false );
      ui->ButtonSubscribe->setVisible ( false );
    }

    ///@TODO Remove this images from a local directory and store them in the DB
    QPixmap pixUser (":/images/user.svg");
    QPixmap pixLogo (":/images/logo.svg");
    QPixmap pixPrevious ( ":/images/backIcon.svg" );
    QPixmap pixNext ( ":/images/nextIcon.svg" );
    QPixmap pixSubscribe ( ":/images/subscribeIcon.svg" );
    QPixmap pixUnsubscribe ( ":/images/unsubscribeIcon.svg" );
    QPixmap pixLogout ( ":/images/logoutIcon.svg" );
    QPixmap pixHome ( ":/images/homeIcon.svg" );
    QPixmap pixModify ( ":/images/modifyIcon.svg" );
    QPixmap pixDelete ( ":/images/deleteIcon.svg" );

    pixLogo = pixLogo.scaled (WIDTHSIZELOGO, HEIGHTSIZELOGO, Qt::KeepAspectRatio,
                               Qt::SmoothTransformation);

    ui->pictureUser->setPixmap (pixUser);
    ui->pictureLogo->setPixmap (pixLogo);
    ui->ButtonPrevious->setIcon ( pixPrevious );
    ui->ButtonNext->setIcon ( pixNext );
    ui->ButtonPrevious->setIconSize ( pixPrevious.rect ( ).size ( ) );
    ui->ButtonNext->setIconSize ( pixNext.rect ( ).size ( ) );
    ui->toolButtonLocalEvents->setVisible ( false );
    ui->ButtonSubscribe->setIcon ( pixSubscribe );
    ui->ButtonUnsubscribe->setIcon ( pixUnsubscribe );
    ui->ButtonLogOut->setIcon ( pixLogout );
    ui->toolButtonLocalEvents->setIcon ( pixHome );
    ui->ButtonUnsubscribe->setVisible ( false );
    ui->ButtonNewEvent->setIcon ( pixSubscribe );
    ui->ButtonModify->setIcon ( pixModify );
    ui->ButtonDelete->setIcon ( pixDelete );

    ///@TODO Remove these default values and set the data of all combo box by the DB
    listTypeEvents = ( QStringList ( ) << "Sports"
                                       << "Music" );
    ui->comboBoxTypeEvent->addItems ( listTypeEvents );
    listProvinces = ( QStringList ( ) << "San Jose"
                                      << "Alajuela"
                                      << "Heredia"
                                      << "Cartago"
                                      << "Puntarenas"
                                      << "Guanacaste"
                                      << "Limon" );
    ui->comboBoxProvince->addItems ( listProvinces );
    listCantons = ( QStringList ( ) << "Escazu"
                                    << "Acosta"
                                    << "Perez Zeledon" );
    ui->comboBoxCanton->addItems ( listCantons );
    listDistricts = ( QStringList ( ) << "San Antonio"
                                      << "San Rafael" );
    ui->comboBoxDistrict->addItems ( listDistricts );

    /*! Set the current date to the date time edit */
    ui->dateTimeEditInitial->setDateTime ( QDateTime::currentDateTime ( ) );
    ui->dateTimeEditFinal->setDateTime ( QDateTime::currentDateTime ( ) );
    ui->dateTimeEditInitial->setMinimumDateTime ( QDateTime::currentDateTime ( ) );
    ui->dateTimeEditFinal->setMinimumDateTime ( ui->dateTimeEditInitial->dateTime ( ) );
    ui->labelCurrentDateTime->setText (
        QDateTime::currentDateTime ( ).toString ( "dd/MM/yyyy hh:mm" ) );

    ///@TODO Remove the values default and set the data by the DB
    userName = "[LastName] + [Name]";
    ui->labelNameUser->setText (userName);
    ui->labelNameEvent->setStyleSheet ("font-weight: bold;");
    ui->labelEventInitialDate->setStyleSheet (
        "font-weight: bold; color: "
        "rgb(187, 205, 225);" );
    ui->labelEventFinalDate->setStyleSheet (
        "font-weight: bold; color: "
        "rgb(187, 205, 225);" );
    ui->labelDescription->setWordWrap (true);

    /*!
     * The connection of slots to the signals when the user click the buttons
     */
    connect (ui->ButtonNext, SIGNAL (clicked ()), this, SLOT (onButtonNextClicked ()));
    connect (ui->ButtonPrevious, SIGNAL (clicked ()), this, SLOT (onButtonPreviousClicked ()));
    connect ( ui->ButtonSubscribe, SIGNAL ( clicked ( ) ), this,
              SLOT ( onButtonSubscribeClicked ( ) ) );
    connect ( ui->ButtonNewImage, SIGNAL ( clicked ( ) ), this,
              SLOT ( onButtonNewImageClicked ( ) ) );
    connect ( ui->ButtonLogOut, SIGNAL ( clicked ( ) ), this, SLOT ( onButtonLogOutClicked ( ) ) );
}

void HomeWindow::onButtonSubscribeClicked ( ) {
  /*!
   * If the user click the button of subscribe, a new item of local event is
   * added to the list widget of my events
   */
  ui->listWidgetEvents->addItem (
      new QListWidgetItem ( QIcon ( event.getImageEvent ( ) ), event.getNameEvent ( ) ) );
  ui->listWidgetEvents->setStyleSheet (
      "QListWidget::item {"
      "border-style: solid;"
      "border-width:1px;"
      "border-bottom-color:black;"
      "background-color:white;"
      "qproperty-alignment: 'AlignBottom | AlignRight';"
      "}"
      "QListWidget::item:selected {"
      "background-color: rgb(237, 240, 255);"
      "color: black;"
      "}" );
}

void HomeWindow::onButtonLogOutClicked ( ) {
  this->close ( );
}

/*!
 * In this function, the user interface of the
 * main system screen is destroyed
 */

HomeWindow::~HomeWindow(){}

void HomeWindow::onButtonPreviousClicked()
{
    /*! A number is subtracted from the index to go to the previous event */
    indexOfCarousel--;

    /*! The function to show information in the carousel is called and the index value is sent */
    showInformationCarousel(indexOfCarousel);

    /*! The function to show buttons in the carousel is called and the index value is sent */
    showButtonsCarousel(indexOfCarousel);
}

void HomeWindow::onButtonNextClicked()
{
    /*! A number is added to the index to go to the next event */
    indexOfCarousel++;

    /*! The function to show information in the carousel is called and the index value is sent */
    showInformationCarousel(indexOfCarousel);

    /*! The function to show buttons in the carousel is called and the index value is sent */
    showButtonsCarousel(indexOfCarousel);
}

void HomeWindow::onButtonNewImageClicked ( ) {
  ///@TODO In this function is necessary to save the image by the user in the database
  tempImageEvent =
      QFileDialog::getOpenFileName ( this, tr ( "Open file" ), "/home", "Vector image (*.svg);;" );

  QMessageBox messageNewImageEvent;
  QPixmap pixStatusImage;
  if ( tempImageEvent != "" ) {
    QPixmap pixNewImageEvent ( tempImageEvent );
    pixNewImageEvent = pixNewImageEvent.scaled ( WIDTHSIZEIMAGEEVENT, HEIGHTSIZEIMAGEEVENT,
                                                 Qt::KeepAspectRatio, Qt::SmoothTransformation );
    messageNewImageEvent.setIconPixmap ( pixNewImageEvent );
    messageNewImageEvent.setWindowTitle ( "New image of the event" );
    messageNewImageEvent.exec ( );
    pixStatusImage.load ( ":/images/newImageIcon.svg" );
    ui->ButtonNewImage->setText ( "Image selected" );
  } else {
    messageNewImageEvent.critical ( nullptr, "Error", "No image selected" );
    pixStatusImage.load ( ":/images/noImageIcon.svg" );
    ui->ButtonNewImage->setText ( "No image" );
  }
  ui->ButtonNewImage->setIcon ( pixStatusImage );
}

void HomeWindow::showInformationCarousel(int i_indexOfCarousel)
{
    /*!
     *  It is assigned the values ​​brought from the function select event to the object
     *  type event to be able to call the get function the values ​​return
     */
    event = databaseManager.selectEvent ( i_indexOfCarousel );

    /*! To the index of the carousel is added a number because it starts in zero */
    eventStatus = QString::number(i_indexOfCarousel+1)+"/"+QString::number(event.getTotalEvents())+" of events";

    /*! If there are no events a message is show to the user */
    if(event.getTotalEvents() == NOEVENTS)
    {
        ui->labelNameEvent->setText("No Data");
    }
    /*! If there are at least one event the information of the user is showed */
    else{
        ui->labelNameEvent->setText (event.getNameEvent());
        ui->labelDescription->setText (event.getDescriptionEvent());
        ui->labelEventInitialDate->setText (event.getInitialDateEvent());
        ui->labelEventFinalDate->setText (event.getFinalDateEvent());
        ui->pictureEvent->setPixmap ( event.getImageEvent ( ) );
        ui->labelEventStatus->setText(eventStatus);
    }
}

void HomeWindow::showButtonsCarousel(int i_indexOfCarousel)
{
    /*! If there are only one event the next and previous buttons are disabled */
    if (event.getTotalEvents() == ONEEVENT)
    {
        ui->ButtonPrevious->setDisabled(true);
        ui->ButtonNext->setDisabled(true);
    /*! If the event is the first, the button previous is disabled */
    } else if ( i_indexOfCarousel == FIRSTEVENT ) {
      ui->ButtonPrevious->setDisabled ( true );
      ui->ButtonNext->setDisabled ( false );
      /*! If the event is the last, the button next is disabled */
      /*! To the index of the carousel is substracted a number because the total of events
       * is a number superior */
    } else if ( i_indexOfCarousel == ( event.getTotalEvents ( ) - 1 ) ) {
      ui->ButtonPrevious->setDisabled ( false );
      ui->ButtonNext->setDisabled ( true );
      /*! If the event is not the first and the last, all the buttons are enabled */
    } else {
      ui->ButtonPrevious->setDisabled ( false );
      ui->ButtonNext->setDisabled ( false );
    }
}
