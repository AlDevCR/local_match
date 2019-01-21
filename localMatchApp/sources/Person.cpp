#include "Person.h"

Person::Person(){}

Person::~Person(){}

void Person::setCodePerson(QString codePerson){
    this->codePerson = codePerson;
}
QString Person::getCodePerson(){
    return codePerson;
}

void Person::setNamePerson(QString namePerson){
    this->namePerson = namePerson;
}
QString Person::getNamePerson(){
    return namePerson;
}

void Person::setFirstLastName(QString firstLastName){
    this->firstLastName = firstLastName;
}
QString Person::getFirstLastName(){
    return firstLastName;
}

void Person::setSecondLastName(QString secondLastName){
    this->secondLastName = secondLastName;
}
QString Person::getSecondLastName(){
    return secondLastName;
}

void Person::setBirthDay(QString birthDay){
    this->birthDay = birthDay;
}
QString Person::getBirthDay(){
    return birthDay;
}

void Person::setUserCode(QString userCode){
    this->userCode = userCode;
}
QString Person::getUserCode(){
    return userCode;
}
