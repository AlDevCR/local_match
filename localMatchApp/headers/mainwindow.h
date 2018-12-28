#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLineEdit>
#include <QMainWindow>
#include <memory>

/*!
 * It is created to be able
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

    MainWindow ( const MainWindow &mainWindow ) = default;

    MainWindow &operator= ( const MainWindow &mainWindow ) = default;

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
 /*! It will be used to be able to use all the graphic
  * interface elements of Main Window */
 std::unique_ptr< Ui::MainWindow > ui;
};

#endif // MAINWINDOW_H
