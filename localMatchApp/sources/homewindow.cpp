#include "../headers/homewindow.h"
#include "ui_homewindow.h"
#include <QStyle>
#include <QFileDialog>
#include "../headers/functions.h"
#include "../headers/events.h"

/*!
 * In this function is created what is necessary
 * to build the main screen of the system
 */
HomeWindow::HomeWindow ( QWidget *i_parent ) : QDialog ( i_parent ), ui ( new Ui::HomeWindow ) {
  event = f.SelectEvent(index);
  const int WIDTHSIZELOGO = 150;
  const int HEIGHTSIZELOGO = 24;
  ui->setupUi (this);
  QPixmap pixUser (":/images/user.svg");
  QPixmap pixLogo (":/images/logo.svg");
  pixLogo = pixLogo.scaled ( WIDTHSIZELOGO, HEIGHTSIZELOGO, Qt::KeepAspectRatio,
                             Qt::SmoothTransformation );
  nameEvent = event.getNameEvent();
  descriptionEvent= event.getDescriptionEvent();
  initialDateEvent=event.getInitialDateEvent();
  finalDateEvent=event.getFinalDateEvent();
  pathImageEvent = event.getPathImageEvent();
  eventStatus = QString::number(index+OPERATIONONE)+"/"+QString::number(event.getTotalEvents())+" of events";

  ui->pictureUser->setPixmap (pixUser);
  ui->pictureLogo->setPixmap (pixLogo);
  ui->labelNameUser->setText ("User Name");
  ui->labelNameEvent->setText (nameEvent);
  ui->labelDescription->setText (descriptionEvent);
  ui->labelEventInitialDate->setText (initialDateEvent);
  ui->labelEventFinalDate->setText (finalDateEvent);
  ui->pictureEvent->setPixmap (pathImageEvent);
  ui->labelEventStatus->setText(eventStatus);
  ui->labelNameEvent->setStyleSheet ("font-weight: bold;");
  ui->labelEventInitialDate->setStyleSheet (
      "font-weight: bold; color: "
      "rgb(187, 205, 225);" );
  ui->labelEventFinalDate->setStyleSheet (
      "font-weight: bold; color: "
      "rgb(187, 205, 225);" );
  ui->labelDescription->setWordWrap (true);
  if(event.getTotalEvents() == NOEVENTS){
      ui->labelNameEvent->setText("No Data");
  }else if (event.getTotalEvents() == ONEEVENT) {
      ui->ButtonPrevious->setDisabled(true);
      ui->ButtonNext->setDisabled(true);
  }else if(event.getTotalEvents() > ONEEVENT){
      if(index==FIRSTEVENT){
          ui->ButtonPrevious->setDisabled(true);
      }else{
          ui->ButtonPrevious->setDisabled(false);
      }
      if(index==(event.getTotalEvents()-OPERATIONONE)){
          ui->ButtonNext->setDisabled(true);
      }else{
          ui->ButtonNext->setDisabled(false);
      }
  }
  connect (ui->ButtonNext, SIGNAL (clicked ()), this, SLOT (onButtonNextClicked ()));
  connect (ui->ButtonPrevious, SIGNAL (clicked ()), this, SLOT (onButtonPreviousClicked ()));
  connect (ui->pushButtonSubscribe, SIGNAL (clicked ()), this, SLOT (onPushButtonSubscribeClicked ()));
}

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
    index--;
    eventStatus = QString::number(index+OPERATIONONE)+"/"+QString::number(event.getTotalEvents())+" of events";
    ui->labelEventStatus->setText(eventStatus);
    if(event.getTotalEvents() == NOEVENTS){
        ui->labelNameEvent->setText("No Data");
    }else if (event.getTotalEvents() == ONEEVENT) {
        ui->ButtonPrevious->setDisabled(true);
        ui->ButtonNext->setDisabled(true);
    }else if(event.getTotalEvents() > ONEEVENT){
        if(index==FIRSTEVENT){
            ui->ButtonPrevious->setDisabled(true);
        }else{
            ui->ButtonPrevious->setDisabled(false);
        }
        if(index==(event.getTotalEvents()-OPERATIONONE)){
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
}

void HomeWindow::onButtonNextClicked()
{
    index++;
    eventStatus = QString::number(index+OPERATIONONE)+"/"+QString::number(event.getTotalEvents())+" of events";
    ui->labelEventStatus->setText(eventStatus);
    if(event.getTotalEvents() == NOEVENTS){
        ui->labelNameEvent->setText("No Data");
    }else if (event.getTotalEvents() == ONEEVENT) {
        ui->ButtonPrevious->setDisabled(true);
        ui->ButtonNext->setDisabled(true);
    }else if(event.getTotalEvents() > ONEEVENT){
        if(index==FIRSTEVENT){
            ui->ButtonPrevious->setDisabled(true);
        }else{
            ui->ButtonPrevious->setDisabled(false);
        }
        if(index==(event.getTotalEvents()-OPERATIONONE)){
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
}
