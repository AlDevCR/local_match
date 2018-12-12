#include "../headers/homewindow.h"
#include "ui_homewindow.h"
#include <QStyle>

HomeWindow::HomeWindow(QWidget *i_parent) :
    QDialog(i_parent),
    ui(new Ui::HomeWindow)
{
    const int WIDTHSIZELOGO = 150;
    const int HEIGHTSIZELOGO = 24;
    ui->setupUi(this);;
    QPixmap pixUser (":/images/user.svg");
    QPixmap pixLogo (":/images/logo.svg");
    QPixmap pixEvent (":/images/eventExample1.svg");
    pixLogo = pixLogo.scaled(WIDTHSIZELOGO, HEIGHTSIZELOGO, Qt::KeepAspectRatio,
                             Qt::SmoothTransformation);
    ui->pictureUser->setPixmap(pixUser);
    ui->pictureLogo->setPixmap(pixLogo);
    ui->pictureEvent->setPixmap(pixEvent);
    ui->labelNameUser->setText("Marcelino Solano");
    ui->labelNameEvent->setText("New Year Party 2018");
    ui->labelNameEvent->setStyleSheet("font-weight: bold;");
    ui->labelDateEvent->setText("05/12/2018");
    ui->labelDateEvent->setStyleSheet("font-weight: bold; color: "
                                      "rgb(187, 205, 225);");
    ui->labelHourEvent->setText("18:00 - 23:00");
    ui->labelHourEvent->setStyleSheet("font-weight: bold; color: "
                                      "rgb(187, 205, 225);");
    ui->labelDescription->setText("So perhaps, you've generated some fancy "
                                  "text, and you're content that you can now "
                                  "copy and paste your fancy text in the "
                                  "comments section of funny cat videos, but "
                                  "perhaps you're wondering how it's even "
                                  "possible to change the font of your text? "
                                  "Is it some sort of hack? Are you copying "
                                  "and pasting an actual font?");
    ui->labelDescription->setWordWrap(true);
    connect(ui->pushButtonNext,SIGNAL(clicked()), this,
            SLOT(onPushButtonNextClicked()));
    connect(ui->pushButtonPrevious,SIGNAL(clicked()), this,
            SLOT(onPushButtonPreviousClicked()));
}

HomeWindow::~HomeWindow()
{
    delete ui;
}

void HomeWindow::onPushButtonNextClicked()
{
    index = index +1;
    dateEvent = QString::number(index);
    switch (index) {
        case 1:
        {
            nameEvent = "New Year Party 2018";
            //dateEvent = QString::number(index);
            hourEvent = "18:00 - 23:00";
            descriptionEvent = "So perhaps, you've generated some fancy "
                                       "text, and you're content that you can now "
                                       "copy and paste your fancy text in the "
                                       "comments section of funny cat videos, but "
                                       "perhaps you're wondering how it's even "
                                       "possible to change the font of your text? "
                                       "Is it some sort of hack? Are you copying "
                                       "and pasting an actual font?";
            pathImageEvent = ":/images/eventExample1.svg";
            break;
        }
        case 2:
        {
            //ui->labelNameEvent->setText("nameEventddd");
            nameEvent = "New Year Party fffffffff2018";
            //dateEvent = QString::number(index);
            hourEvent = "18:00 - 23:00";
            descriptionEvent = "So perhaps, you've generated some fancy "
                                       "text, and you're content that you can now "
                                       "copy and paste your fancy text in the "
                                       "comments section of funny cat videos, but "
                                       "perhaps you're wondering how it's even "
                                       "possible to change the font of your text? "
                                       "Is it some sort of hack? Are you copying "
                                       "and pasting an actual font?";
            pathImageEvent = ":/images/eventExample2.svg";
            break;
        }
        case 3:
        {
            //ui->labelNameEvent->setText("nameEventfdfddddddddddd");
            nameEvent = "New Year Party rrere2018";
            //dateEvent = QString::number(index);
            hourEvent = "18:00 - 23:00";
            descriptionEvent = "So perhaps, you've generated some fancy "
                                       "text, and you're content that you can now "
                                       "copy and paste your fancy text in the "
                                       "comments section of funny cat videos, but "
                                       "perhaps you're wondering how it's even "
                                       "possible to change the font of your text? "
                                       "Is it some sort of hack? Are you copying "
                                       "and pasting an actual font?";
            pathImageEvent = ":/images/eventExample3.svg";
            break;
        }
    }
    ui->pictureEvent->setPixmap(pathImageEvent);
    ui->labelNameEvent->setText(nameEvent);
    ui->labelDateEvent->setText(dateEvent);
    ui->labelHourEvent->setText(hourEvent);
    ui->labelDescription->setText(descriptionEvent);
}

void HomeWindow::onPushButtonPreviousClicked()
{
    index = index -1;
    switch (index) {
        case 1:
        {
            nameEvent = "New Year Party 2018";
            //ui->labelNameEvent->setText("nameEvent");
            dateEvent = QString::number(index);
            hourEvent = "18:00 - 23:00";
            descriptionEvent = "So perhaps, you've generated some fancy "
                                       "text, and you're content that you can now "
                                       "copy and paste your fancy text in the "
                                       "comments section of funny cat videos, but "
                                       "perhaps you're wondering how it's even "
                                       "possible to change the font of your text? "
                                       "Is it some sort of hack? Are you copying "
                                       "and pasting an actual font?";
            pathImageEvent = ":/images/eventExample1.svg";
            break;
        }
        case 2:
        {
            //ui->labelNameEvent->setText("nameEventddd");
            nameEvent = "New Year Party fffffffff2018";
            dateEvent = QString::number(index);
            hourEvent = "18:00 - 23:00";
            descriptionEvent = "So perhaps, you've generated some fancy "
                                       "text, and you're content that you can now "
                                       "copy and paste your fancy text in the "
                                       "comments section of funny cat videos, but "
                                       "perhaps you're wondering how it's even "
                                       "possible to change the font of your text? "
                                       "Is it some sort of hack? Are you copying "
                                       "and pasting an actual font?";
            pathImageEvent = ":/images/eventExample2.svg";
            break;
        }
        case 3:
        {
            //ui->labelNameEvent->setText("nameEventfdfddddddddddd");
            //nameEvent = "New Year Party rrere2018";
            dateEvent = QString::number(index);
            hourEvent = "18:00 - 23:00";
            descriptionEvent = "So perhaps, you've generated some fancy "
                                       "text, and you're content that you can now "
                                       "copy and paste your fancy text in the "
                                       "comments section of funny cat videos, but "
                                       "perhaps you're wondering how it's even "
                                       "possible to change the font of your text? "
                                       "Is it some sort of hack? Are you copying "
                                       "and pasting an actual font?";
            pathImageEvent = ":/images/eventExample3.svg";
            break;
        }
    }
    ui->pictureEvent->setPixmap(pathImageEvent);
    //ui->labelNameEvent->setText(nameEvent);
    ui->labelDateEvent->setText(dateEvent);
    ui->labelHourEvent->setText(hourEvent);
    ui->labelDescription->setText(descriptionEvent);
}

void HomeWindow::mousePressEvent(QMouseEvent *event)
{
    if(totalEvents == 0){
        nameEvent = "No Data";
        ui->labelNameEvent->setText(nameEvent);
    }else if (totalEvents == 1) {
        ui->pushButtonPrevious->setDisabled(true);
        ui->pushButtonNext->setDisabled(true);
    }else if(totalEvents > 1){
        if(index==1){
            ui->pushButtonPrevious->setDisabled(true);
        }else{
            ui->pushButtonPrevious->setDisabled(false);
        }
        if(index==totalEvents){
            ui->pushButtonNext->setDisabled(true);
        }else{
            ui->pushButtonNext->setDisabled(false);
        }
    }
}


