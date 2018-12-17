#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>

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

};

#endif // MAINWINDOW_H


