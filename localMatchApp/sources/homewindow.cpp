#include "homewindow.h"
#include "ui_homewindow.h"
#include <QStyle>
#include <QFileDialog>
#include "functionsevent.h"
#include "classevent.h"

/*!
 * In this function is created what is necessary
 * to build the main screen of the system
 */
HomeWindow::HomeWindow ( QWidget *i_parent ) : QDialog ( i_parent ), ui ( new Ui::HomeWindow ) {
    ui->setupUi(this);

    /*! The variable index is initialized with zero because the carousel
     * will begin with the fisrt position */
    indexOfCarousel = 0;

    /*! The carousel function is called and the index value is sent */
    manageCarousel(indexOfCarousel);

    ///@TODO Remove this images from a local directory and store them in the DB
    QPixmap pixUser (":/images/user.svg");
    QPixmap pixLogo (":/images/logo.svg");

    pixLogo = pixLogo.scaled (WIDTHSIZELOGO, HEIGHTSIZELOGO, Qt::KeepAspectRatio,
                               Qt::SmoothTransformation);

    ui->pictureUser->setPixmap (pixUser);
    ui->pictureLogo->setPixmap (pixLogo);

    ///@TODO Remove the name user value default and set the data by the DB
    ui->labelNameUser->setText ("User Name");
    ui->labelNameEvent->setStyleSheet ("font-weight: bold;");
    ui->labelEventInitialDate->setStyleSheet (
        "font-weight: bold; color: "
        "rgb(187, 205, 225);" );
    ui->labelEventFinalDate->setStyleSheet (
        "font-weight: bold; color: "
        "rgb(187, 205, 225);" );
    ui->labelDescription->setWordWrap (true);

  nameEvent = event.getNameEvent();
  descriptionEvent= event.getDescriptionEvent();
  initialDateEvent=event.getInitialDateEvent();
  finalDateEvent=event.getFinalDateEvent();
  pathImageEvent = event.getPathImageEvent();

  connect (ui->ButtonNext, SIGNAL (clicked ()), this, SLOT (onButtonNextClicked ()));
  connect (ui->ButtonPrevious, SIGNAL (clicked ()), this, SLOT (onButtonPreviousClicked ()));
  connect (ui->pushButtonSubscribe, SIGNAL (clicked ()), this, SLOT (onPushButtonSubscribeClicked ()));



}

/*!
 * In this function, the user interface of the
 * main system screen is destroyed
 */

HomeWindow::~HomeWindow()
{
  delete ui;
}

void HomeWindow::onPushButtonSubscribeClicked()
{
    ui->listWidget->addItem(new QListWidgetItem(QIcon(pathImageEvent),nameEvent));
    ui->listWidget->setStyleSheet("QListView::item { border-bottom: 1px solid black; padding: 2px; }");
}

void HomeWindow::onButtonPreviousClicked()
{
    /*! A number is subtracted from the index to go to the previous event */
    indexOfCarousel--;

    /*! The carousel function is called and the index value is sent */
    manageCarousel(indexOfCarousel);
}

void HomeWindow::onButtonNextClicked()
{
    /*! A number is added to the index to go to the next event */
    indexOfCarousel++;

    /*! The carousel function is called and the index value is sent */
    manageCarousel(indexOfCarousel);
}

void HomeWindow::manageCarousel(int i_indexOfCarousel){

    /*!
     *  It is assigned the values ​​brought from the function select event to the object
     *  type event to be able to call the get function the values ​​return
     */
   FunctionsEvent functionOfEvent;
   event = functionOfEvent.selectEvent(i_indexOfCarousel);

    /*! To the index of the carousel is added a number because it starts in zero */
    eventStatus = QString::number(i_indexOfCarousel+1)+"/"+QString::number(event.getTotalEvents())+" of events";

    /*! If there are no events a message is show to the user */
    if(event.getTotalEvents() == NOEVENTS){
        ui->labelNameEvent->setText("No Data");
    /*! If there are at least one event the information of the user is showed */
    }else{
        /*! If there are only one event the next and previous buttons are disabled */
        if (event.getTotalEvents() == ONEEVENT) {
            ui->ButtonPrevious->setDisabled(true);
            ui->ButtonNext->setDisabled(true);

        /*! If there are more than one event */
        }else if(event.getTotalEvents() > ONEEVENT){
            /*! If the event is the first, the button previous is disabled */
            if(indexOfCarousel==FIRSTEVENT){
                ui->ButtonPrevious->setDisabled(true);
            }else{
                ui->ButtonPrevious->setDisabled(false);
            }

            /*! If the event is the last, the button next is disabled */
            /*! To the index of the carousel is substracted a number because the total of events
             * is a number superior */
            if(indexOfCarousel==(event.getTotalEvents()-1)){
                ui->ButtonNext->setDisabled(true);
            }else{
                ui->ButtonNext->setDisabled(false);
            }
        }

        ui->labelNameEvent->setText (event.getNameEvent());
        ui->labelDescription->setText (event.getDescriptionEvent());
        ui->labelEventInitialDate->setText (event.getInitialDateEvent());
        ui->labelEventFinalDate->setText (event.getFinalDateEvent());
        ui->pictureEvent->setPixmap (event.getPathImageEvent());
        ui->labelEventStatus->setText(eventStatus);
    }

}
