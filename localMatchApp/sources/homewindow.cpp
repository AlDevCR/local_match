#include "homewindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QStyle>
#include "mainwindow.h"
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

    typeUser = 1;

    if ( typeUser == 1 ) {
      typeOfUser = TypeOfUser::personalUser;
    } else if ( typeUser == 2 ) {
      typeOfUser = TypeOfUser::commercialUser;
    } else if ( typeUser == 3 ) {
      typeOfUser = TypeOfUser::administratorUser;
    }

    /*! If the user type is personal the area of manage event is not visible */
    if ( typeOfUser == TypeOfUser::personalUser ) {
      ui->labelTypeUser->setText ( "Personal Account" );
      ui->groupBoxManageEvent->setVisible ( false );
      ui->labelMyEvents->setVisible ( true );
      ui->listWidgetEvents->setVisible ( true );
      ui->ButtonModifyEvent->setVisible ( false );
      ui->ButtonDeleteEvent->setVisible ( false );
      ui->ButtonNewEvent->setVisible ( false );
      /*! If the user type is commercial the area of manage event is visible */
    } else if ( typeOfUser == TypeOfUser::commercialUser ) {
      ui->labelTypeUser->setText ( "Commercial Account" );
      ui->groupBoxManageEvent->setVisible ( true );
      ui->labelMyEvents->setVisible ( false );
      ui->listWidgetEvents->setVisible ( false );
      ui->groupBoxEvent->setTitle ( "My Events" );
      ui->ButtonModifyEvent->setVisible ( true );
      ui->ButtonDeleteEvent->setVisible ( true );
      ui->ButtonSubscribe->setVisible ( false );
      ui->ButtonNewEvent->setVisible ( true );
      /*! If the user type is administrator the area of manage event is visible */
    } else if ( typeOfUser == TypeOfUser::administratorUser ) {
      ui->labelTypeUser->setText ( "Administrator Account" );
      ui->groupBoxManageEvent->setVisible ( true );
      ui->labelMyEvents->setVisible ( false );
      ui->listWidgetEvents->setVisible ( false );
      ui->ButtonModifyEvent->setVisible ( false );
      ui->ButtonDeleteEvent->setVisible ( false );
      ui->ButtonSubscribe->setVisible ( false );
      ui->ButtonNewEvent->setVisible ( true );
    }

    ui->ButtonModifyEvent->setToolTip ( "Modify this event" );
    ui->ButtonDeleteEvent->setToolTip ( "Delete this event" );
    ui->ButtonUpdateEvent->setVisible ( false );
    ui->ButtonCancel->setVisible ( false );

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

    showAvailableEvents ( );

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
    ui->ButtonModifyEvent->setIcon ( pixModify );
    ui->ButtonUpdateEvent->setIcon ( pixSubscribe );
    ui->ButtonDeleteEvent->setIcon ( pixDelete );
    ui->ButtonCancel->setIcon ( pixUnsubscribe );

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
    ui->labelDescriptionEvent->setWordWrap ( true );

    /*!
     * The connection of slots to the signals when the user click the buttons
     */
    connect (ui->ButtonNext, SIGNAL (clicked ()), this, SLOT (onButtonNextClicked ()));
    connect (ui->ButtonPrevious, SIGNAL (clicked ()), this, SLOT (onButtonPreviousClicked ()));
    connect ( ui->ButtonSubscribe, SIGNAL ( clicked ( ) ), this,
              SLOT ( onButtonSubscribeClicked ( ) ) );
    connect ( ui->ButtonUnsubscribe, SIGNAL ( clicked ( ) ), this,
              SLOT ( onButtonUnSubscribeClicked ( ) ) );
    connect ( ui->ButtonModifyEvent, SIGNAL ( clicked ( ) ), this,
              SLOT ( onButtonModifyEventClicked ( ) ) );
    connect ( ui->ButtonNewImage, SIGNAL ( clicked ( ) ), this,
              SLOT ( onButtonNewImageClicked ( ) ) );
    connect ( ui->ButtonCancel, SIGNAL ( clicked ( ) ), this, SLOT ( onButtonCancelClicked ( ) ) );
    connect ( ui->ButtonNewEvent, SIGNAL ( clicked ( ) ), this,
              SLOT ( onButtonNewEventClicked ( ) ) );
    connect ( ui->ButtonDeleteEvent, SIGNAL ( clicked ( ) ), this,
              SLOT ( onButtonDeleteEventClicked ( ) ) );
    connect ( ui->ButtonUpdateEvent, SIGNAL ( clicked ( ) ), this,
              SLOT ( onButtonUpdateEventClicked ( ) ) );
    connect ( ui->ButtonLogOut, SIGNAL ( clicked ( ) ), this, SLOT ( onButtonLogOutClicked ( ) ) );
    connect ( ui->listWidgetEvents, SIGNAL ( clicked ( QModelIndex ) ), this,
              SLOT ( onEventItemsClicked ( ) ) );
    connect ( ui->toolButtonLocalEvents, SIGNAL ( clicked ( ) ), this,
              SLOT ( onButtonLocalEventsClicked ( ) ) );
}

void HomeWindow::onButtonSubscribeClicked ( ) {

  ///@TODO In this function is necessary to call the function insertEventToUser that is in
  /// DatabaseManager
  /// class and assign it the current user's id session and the id of the event that was selected
  /// databaseManager.insertEventToUser( sessionId , event.getIdEvent() )

  /*!
   * Update the information of the local events
   */
  indexOfCarousel = 0;
  showInformationCarousel ( indexOfCarousel );

  /*!
   * Update the information of my events of the current user
   */
  ui->listWidgetEvents->clear ( );
  showValuesMyEvent ( );

  ///@TODO Remove that because is for UI test only
  ui->ButtonSubscribe->setVisible ( false );
  ui->ButtonUnsubscribe->setVisible ( true );
  ui->listWidgetEvents->addItem (
      new QListWidgetItem ( QIcon ( event.getImageEvent ( ) ), event.getNameEvent ( ) ) );
}

void HomeWindow::onButtonUnSubscribeClicked ( ) {

  ///@TODO In this function is necessary to call the function deleteEventToUser that is in
  /// DatabaseManager
  /// class and assign it the current user's id session and the id of the event that was selected
  /// databaseManager.deleteEventToUser( sessionId , event.getIdEvent() )

  /*!
   * Update the information of the local events
   */
  indexOfCarousel = 0;
  showInformationCarousel ( indexOfCarousel );

  /*!
   * Update the information of my events of the current user
   */
  ui->listWidgetEvents->clear ( );
  showValuesMyEvent ( );

  ///@TODO Remove that because is for UI test only
  ui->ButtonSubscribe->setVisible ( true );
  ui->ButtonUnsubscribe->setVisible ( false );
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

void HomeWindow::onButtonModifyEventClicked ( ) {
  /*! The information fields are filled with the event that was selected to modify */
  ui->lineEditNameEvent->setText ( nameEvent );
  ui->comboBoxTypeEvent->setCurrentText ( typeEvent );
  ui->textEditDescriptionEvent->setText ( descriptionEvent );
  ui->dateTimeEditInitial->setDateTime (
      QDateTime::fromString ( initialDateEvent, "dd/MM/yyyy hh:mm" ) );
  ui->dateTimeEditFinal->setDateTime (
      QDateTime::fromString ( finalDateEvent, "dd/MM/yyyy hh:mm" ) );
  ui->comboBoxProvince->setCurrentText ( provinceEvent );
  ui->comboBoxCanton->setCurrentText ( cantonEvent );
  ui->comboBoxDistrict->setCurrentText ( districtEvent );
  ui->textEditLocationEvent->setText ( locationEvent );
  ui->groupBoxManageEvent->setTitle ( "Modify Event" );
  ui->ButtonNewImage->setText ( "Change image" );
  ui->ButtonNewEvent->setText ( "Modify Event" );
  ui->ButtonCancel->setVisible ( true );
  ui->ButtonNewEvent->setEnabled ( true );
  ui->ButtonModifyEvent->setVisible ( false );
  ui->ButtonDeleteEvent->setVisible ( false );
  ui->ButtonUpdateEvent->setVisible ( true );
  ui->ButtonNewEvent->setVisible ( false );
}

void HomeWindow::onButtonNewEventClicked ( ) {
  ///@TODO In this function is necessary to save the new event created by the commercial user in the
  /// DB
}

void HomeWindow::onButtonUpdateEventClicked ( ) {
  ///@TODO In this function is necessary to update the event selected by the commercial user in the
  /// DB
}

void HomeWindow::onButtonDeleteEventClicked ( ) {
  ///@TODO In this function is necessary to delete the event selected by the commercial user in the
  /// DB
}

void HomeWindow::onEventItemsClicked ( ) {

  /*! The id of the selected event is assigned to a variable */
  idEventSelected = ui->listWidgetEvents->currentItem ( )->data ( Qt::UserRole );

  /*!
   *  It is assigned the values ​​brought from the function select event to the object
   *  type event to be able to call the get function the values ​​return
   */
  event = databaseManager.selectEventByIdEvent ( idEventSelected.toInt ( ) );
  assignValuesEvent ( event );

  /*! The values ​​of the variables are assigned to the labels of the event */
  ui->labelNameEvent->setText ( nameEvent );
  ui->labelTypeEvent->setText ( typeEvent );
  ui->labelDescriptionEvent->setText ( descriptionEvent );
  ui->labelEventInitialDate->setText ( initialDateEvent );
  ui->labelEventFinalDate->setText ( finalDateEvent );
  ui->labelLocationEvent->setText ( provinceEvent + " / " + cantonEvent + " / " + districtEvent );
  ui->pictureEvent->setPixmap ( imageEvent );
  ui->labelEventStatus->setText ( eventStatus );

  ui->ButtonSubscribe->setVisible ( false );
  ui->ButtonUnsubscribe->setVisible ( true );
  ui->ButtonNext->setVisible ( false );
  ui->ButtonPrevious->setVisible ( false );
  ui->labelEventStatus->setVisible ( false );
  ui->toolButtonLocalEvents->setVisible ( true );
  ui->groupBoxEvent->setTitle ( "My Events" );
}

void HomeWindow::onButtonCancelClicked ( ) {
  /*! If the modification of a certain event is canceled all the fields return to the normal state
   * to create a new event */
  ui->lineEditNameEvent->setText ( "" );
  ui->comboBoxTypeEvent->setCurrentIndex ( 0 );
  ui->textEditDescriptionEvent->setText ( "" );
  ui->dateTimeEditInitial->setDateTime ( QDateTime::currentDateTime ( ) );
  ui->dateTimeEditFinal->setDateTime ( QDateTime::currentDateTime ( ) );
  ui->comboBoxProvince->setCurrentIndex ( 0 );
  ui->comboBoxCanton->setCurrentIndex ( 0 );
  ui->comboBoxDistrict->setCurrentIndex ( 0 );
  ui->textEditLocationEvent->setText ( "" );
  ui->groupBoxManageEvent->setTitle ( "Create Event" );
  ui->ButtonNewImage->setText ( "New image" );
  ui->ButtonNewEvent->setText ( "Create Event" );
  ui->ButtonCancel->setVisible ( false );
  ui->ButtonModifyEvent->setVisible ( true );
  ui->ButtonDeleteEvent->setVisible ( true );
  ui->ButtonUpdateEvent->setVisible ( false );
  ui->ButtonNewEvent->setVisible ( true );
}

void HomeWindow::onButtonLocalEventsClicked ( ) {
  showAvailableEvents ( );
  ui->ButtonNext->setVisible ( true );
  ui->ButtonPrevious->setVisible ( true );
  ui->labelEventStatus->setVisible ( true );
  ui->toolButtonLocalEvents->setVisible ( false );
  ui->ButtonSubscribe->setVisible ( true );
  ui->ButtonUnsubscribe->setVisible ( false );
  ui->groupBoxEvent->setTitle ( "Local Events" );
}

void HomeWindow::showInformationCarousel(int i_indexOfCarousel)
{
    /*!
     *  It is assigned the values ​​brought from the function select event to the object
     *  type event to be able to call the get function the values ​​return
     */
    event = databaseManager.selectEventByIdCarrousel ( i_indexOfCarousel );

    assignValuesEvent ( event );

    /*! To the index of the carousel is added a number because it starts in zero */
    eventStatus = QString::number(i_indexOfCarousel+1)+"/"+QString::number(event.getTotalEvents())+" of events";

    /*! If there are no events a message is show to the user */
    if(event.getTotalEvents() == NOEVENTS)
    {
      QPixmap pixNoEvents ( ":/images/noEvents.svg" );
      ui->pictureEvent->setPixmap ( pixNoEvents );
      ui->labelDescriptionEvent->setText ( "No Events Availables" );
      ui->labelNameEvent->setVisible ( false );
      ui->labelTypeEvent->setVisible ( false );
      ui->labelEventInitialDate->setVisible ( false );
      ui->labelEventFinalDate->setVisible ( false );
      ui->labelLocationEvent->setVisible ( false );
      ui->ButtonModifyEvent->setVisible ( false );
      ui->ButtonDeleteEvent->setVisible ( false );
      ui->labelEventStatus->setVisible ( false );
      ui->ButtonNext->setVisible ( false );
      ui->ButtonPrevious->setVisible ( false );
      ui->ButtonSubscribe->setVisible ( false );
    }
    /*! If there are at least one event the information of the user is showed */
    else{
      ui->labelNameEvent->setText ( nameEvent );
      ui->labelTypeEvent->setText ( typeEvent );
      ui->labelDescriptionEvent->setText ( descriptionEvent );
      ui->labelEventInitialDate->setText ( initialDateEvent );
      ui->labelEventFinalDate->setText ( finalDateEvent );
      ui->labelLocationEvent->setText ( provinceEvent + " / " + cantonEvent + " / " +
                                        districtEvent );
      ui->pictureEvent->setPixmap ( imageEvent );
      ui->labelEventStatus->setText ( eventStatus );
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

void HomeWindow::assignValuesEvent ( GeneralEvent i_event ) {
  idEvent = i_event.getIdEvent ( );
  nameEvent = i_event.getNameEvent ( );
  typeEvent = i_event.getTypeEvent ( );
  descriptionEvent = i_event.getDescriptionEvent ( );
  initialDateEvent = i_event.getInitialDateEvent ( );
  finalDateEvent = i_event.getFinalDateEvent ( );
  provinceEvent = i_event.getProvinceEvent ( );
  cantonEvent = i_event.getCantonEvent ( );
  districtEvent = i_event.getDistrictEvent ( );
  locationEvent = i_event.getLocationEvent ( );
  imageEvent = i_event.getImageEvent ( );
}

void HomeWindow::showValuesMyEvent ( ) {
  ///@TODO In this function is necessary to call the function SelectMyEvents that is in
  /// DatabaseManager class and assign it the current user's id session
  ///@TODO Change the value "idMyEvent" with the id of the event by the DB and change the default
  /// text of the new item
  /// with the name of the event by the DB
  ///@TODO Change the for statement for a while that travels the map that has the information from
  /// the database
  ///@TODO Change the image path to the image by DB to the Icon of QListWidgetItem
  for ( int i = 0; i < 5; i++ ) {
    QListWidgetItem *newItem = new QListWidgetItem;
    int idMyEvent = i;
    newItem->setData ( Qt::UserRole, idMyEvent );
    newItem->setText ( "My Event " + QString::number ( i ) );
    newItem->setIcon ( QIcon ( ":/images/eventExample.svg" ) );
    ui->listWidgetEvents->addItem ( newItem );
  }
}

void HomeWindow::showAvailableEvents ( ) {
  /*! It is initialized with zero because the carousel
   * will begin with the first position */
  indexOfCarousel = 0;

  /*! It shows information in the carousel is called and the index value is sent */
  showInformationCarousel ( indexOfCarousel );

  /*! It shows buttons in the carousel is called and the index value is sent */
  showButtonsCarousel ( indexOfCarousel );

  ui->listWidgetEvents->clear ( );
  showValuesMyEvent ( );
}
