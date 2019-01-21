#ifndef PERSON_H
#define PERSON_H
#include <QtSql>

class Person
{
private:
    QString codePerson;
    QString namePerson;
    QString firstLastName;
    QString secondLastName;
    QString birthDay;
    QString userCode;

public:
    Person();
    ~Person();

    void setCodePerson(QString codePerson);
    void setNamePerson(QString namePerson);
    void setFirstLastName(QString firstLastName);
    void setSecondLastName(QString secondLastName);
    void setBirthDay(QString birthDay);
    void setUserCode(QString userCode);

    QString getCodePerson();
    QString getNamePerson();
    QString getFirstLastName();
    QString getSecondLastName();
    QString getBirthDay();
    QString getUserCode();

};

#endif // PERSON_H
