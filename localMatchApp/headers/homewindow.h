#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QDialog>

/*!
 * The class of user interface type is created to
 * be able to develop the main screen
*/
namespace Ui {
 class HomeWindow;
}

class HomeWindow : public  QDialog
{
    Q_OBJECT

public:
    explicit HomeWindow( QWidget *i_parent = nullptr);
    ~HomeWindow();

private:
    Ui:: HomeWindow *ui;
};

#endif // HOMEWINDOW_H
