#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>

/*!
 * The class of user interface type is created to be able
 * to develop the login window
*/
namespace Ui {
 class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow( QWidget *i_parent = nullptr);
    ~MainWindow();

/*!
 * The functions of button actions are declared so
 * they can be used later
*/
private slots:

    void  onButtonSignUpClicked();

    void onButtonLoginClicked();

private:
    Ui:: MainWindow *ui;

};

#endif // MAINWINDOW_H


