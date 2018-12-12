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



private slots:

    void onButtonSignUpClicked();

    void onButtonLoginClicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H


