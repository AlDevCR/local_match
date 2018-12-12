#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>

namespace Ui {
class SignUp;
}

class SignUp : public QDialog
{
    Q_OBJECT

public:
    explicit SignUp(QWidget *i_parent = nullptr);
    ~SignUp();

private slots:
    void onNewUserButtonClicked();

private:
    Ui::SignUp *ui;
};

#endif // SIGNUP_H
