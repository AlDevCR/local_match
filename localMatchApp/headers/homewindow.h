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

private slots:

    void onPushButtonNextClicked();
    void onPushButtonPreviousClicked();
    void mousePressEvent(QMouseEvent *event);

    void onPushButtonSubscribeClicked();

private:
    Ui::HomeWindow *ui;
    int index = 1;
    int totalEvents = 3;
    QString nameEvent;
    QString dateEvent;
    QString hourEvent;
    QString descriptionEvent;
    QString pathImageEvent;
};

#endif // HOMEWINDOW_H
