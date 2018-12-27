#include "homewindow.h"
#include "ui_homewindow.h"
#include <QStyle>
#include <QFileDialog>

/*!
 * It is created all that is necessary
 * to build the main screen of the system
 */
HomeWindow::HomeWindow ( QWidget *i_parent ) : QDialog ( i_parent ), ui ( std::make_unique<Ui::HomeWindow>() )
{
    ui->setupUi(this);

    /*! It is initialized with zero because the carousel
     * will begin with the first position */
    indexOfCarousel = 0;

    /*! It shows information in the carousel is called and the index value is sent */
    showInformationCarousel(indexOfCarousel);

    /*! It shows buttons in the carousel is called and the index value is sent */
    showButtonsCarousel(indexOfCarousel);

    ///@TODO Remove this images from a local directory and store them in the DB
    QPixmap pixUser (":/images/user.svg");
    QPixmap pixLogo (":/images/logo.svg");

    pixLogo = pixLogo.scaled (WIDTHSIZELOGO, HEIGHTSIZELOGO, Qt::KeepAspectRatio,
                               Qt::SmoothTransformation);

    ui->pictureUser->setPixmap (pixUser);
    ui->pictureLogo->setPixmap (pixLogo);

    ///@TODO Remove the name user value default and set the data by the DB
    userName = "User Name";
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
    connect (ui->pushButtonSubscribe, SIGNAL (clicked ()), this, SLOT (onPushButtonSubscribeClicked ()));
}

void HomeWindow::onPushButtonSubscribeClicked()
{
    /*!
     * If the user click the button of subscribe, a new item of local event is
     * added to the list widget of my events
     */
    ui->listWidget->addItem(new QListWidgetItem(QIcon(event.getImageEvent()),
                                                event.getNameEvent()));
    ui->listWidget->setStyleSheet("QListView::item { border-bottom: 1px "
                                  "solid black; padding: 2px; }");
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

void HomeWindow::showInformationCarousel(int i_indexOfCarousel)
{
    /*!
     *  It is assigned the values ​​brought from the function select event to the object
     *  type event to be able to call the get function the values ​​return
     */
    event = databaseManager.selectEvent(i_indexOfCarousel);

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
        ui->pictureEvent->setPixmap (event.getImageEvent());
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
    }else if (i_indexOfCarousel==FIRSTEVENT)
    {
        ui->ButtonPrevious->setDisabled(true);
        ui->ButtonNext->setDisabled(false);
    /*! If the event is the last, the button next is disabled */
    /*! To the index of the carousel is substracted a number because the total of events
    * is a number superior */
    }else if(i_indexOfCarousel==(event.getTotalEvents()-1))
    {
        ui->ButtonPrevious->setDisabled(false);
        ui->ButtonNext->setDisabled(true);
    /*! If the event is not the first and the last, all the buttons are enabled */
    }else{
        ui->ButtonPrevious->setDisabled(false);
        ui->ButtonNext->setDisabled(false);
    }
}
