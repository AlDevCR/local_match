#include "User.h"

User::User()
{
//TODO: initialize variables
}

User::~User()
{
//TODO: use delete
}

User::User(const User &User2)
{
  code = User2.code;
  userName = User2.userName;
  userPassword = User2.userPassword;
  typeUserCode = User2.typeUserCode;
  imageUser = User2.imageUser;
  nameTypeUser = User2.nameTypeUser;
  descriptionTypeUser = User2.descriptionTypeUser;
}

QString User::getCode()
{
  return code;
}

QString User::getUserName()
{
  return userName;
}

QString User::getUserPassword()
{
  return userPassword;
}

QString User::getTypeUserCode()
{
  return typeUserCode;
}

QString User::getImageUser()
{
  return imageUser;
}

QString User::getNameTypeUser(){
    return nameTypeUser;
}

QString User::getDescriptionTypeUser(){
    return descriptionTypeUser;
}

void User::setCode(QString newCode)
{
  this->code = newCode;
}

void User::setUserName(QString newUserName)
{
  userName = newUserName;
}

void User::setUserPassword(QString newUserPassword)
{
  userPassword = newUserPassword;
}

void User::setTypeUserCode(QString newTypeUser)
{
  typeUserCode = newTypeUser;
}

void User::setImageUser(QString newImageUser)
{
  imageUser = newImageUser;
}

void User::setNameTypeUser(QString nameTypeUser){
    this->nameTypeUser = nameTypeUser;
}

void User::setDescriptionTypeUser(QString descriptionTypeUser){
    this->descriptionTypeUser = descriptionTypeUser;
}

