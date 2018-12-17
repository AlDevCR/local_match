#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLineEdit>
#include <QMainWindow>

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
    explicit MainWindow(QWidget *i_parent = nullptr);
    ~MainWindow();

 /*!
  * The functions of button actions are declared so
  * they can be used later
  */
 private slots:
    /*!
     * The function when the user click the button to sign up is declare
     */
    void onButtonSignUpClicked ( );

    /*!
     * The function when the user click the button to log in is declare
     */
    void onButtonLoginClicked ( );

    private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H


