#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QDialog>

namespace Ui {
class HomeWindow;
}

class HomeWindow : public QDialog
{
    Q_OBJECT
    QTimer *timer;

public:
    explicit HomeWindow(QWidget *i_parent = nullptr);
    ~HomeWindow();

/*!
 * The functions of button actions are declared so
 * they can be used later
 */
private slots:
    void onButtonPreviousClicked();
    void onButtonNextClicked();
    void onPushButtonSubscribeClicked();
    void on_pushButton_2_clicked();

private:
  Ui::HomeWindow *ui;
  const int NOEVENTS = 0;
  const int FIRSTEVENT = 0;
  const int OPERATIONONE = 1;
  const int ONEEVENT = 1;
  int index = 0;
  QString eventStatus;
  QString nameEvent;
  QString dateEvent;
  QString hourEvent;
  QString descriptionEvent;
  QString pathImageEvent;
  QString UserImage;
};

#endif // HOMEWINDOW_H
