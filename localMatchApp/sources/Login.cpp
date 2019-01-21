#include "Login.h"
#include <iostream>

using namespace std;

Login::ConnectionMessage Login::signUp ( const string& i_user, const string& i_name,
                                         const string& i_lastName, const string& i_password,
                                         const string& i_repeatedPassword ) {                                      
  ConnectionMessage signUpConnectionState=ConnectionMessage::goodEntry;
  updateUsersMap();

  if ( !hasCorrectFormat ( i_password ) || !hasCorrectFormat ( i_repeatedPassword ) ) {
    signUpConnectionState= ConnectionMessage::wrongPassword;
  }

  else if ( i_password != i_repeatedPassword ) {
    signUpConnectionState=ConnectionMessage::notEqualPasswords;
  }

  else if ( usersMap.count(i_user)>0 || i_user.length()==0) {
    signUpConnectionState= ConnectionMessage::invalidUser;
  }

  else if ( i_name.length ( ) == 0 ) {
    signUpConnectionState = ConnectionMessage::invalidName;
  }

  else if ( i_lastName.length ( ) == 0 ) {
    signUpConnectionState = ConnectionMessage::invalidLastName;
  }

  if(signUpConnectionState==ConnectionMessage::goodEntry){
    conn.addNewUser(QString::fromUtf8(i_user.c_str()),QString::fromUtf8(i_password.c_str()));
    conn.addNewPerson(QString::fromUtf8(i_user.c_str()),QString::fromUtf8(i_name.c_str()),QString::fromUtf8(i_lastName.c_str()));
    }
  return signUpConnectionState;
}

Login::ConnectionMessage Login::entry ( const string& i_user, const string& i_password ) {
  ConnectionMessage signUpConnectionState=ConnectionMessage::goodEntry;
  updateUsersMap();

  if ( !usersMap.count(i_user)>0 ) {
    signUpConnectionState= ConnectionMessage::doesntExists;
  }
  else if ( i_password != usersMap[i_user].getUserPassword().toStdString() ) {
    signUpConnectionState= ConnectionMessage::wrongPassword;
  }
  if(signUpConnectionState == ConnectionMessage::goodEntry){
    actualUser=i_user;
  }
  
  return signUpConnectionState;
}

bool Login::hasCorrectFormat ( const string& i_password ) {
  bool hasANumber=false;
  bool hasACapital=false;
  bool hasASmallLetter=false;
  bool correctFormat= false;

  for ( const auto &i : i_password ){
      if ( isupper ( i ) ) {
        hasACapital= true;
      }

      else if ( islower ( i ) ) {
        hasASmallLetter= true;
      }

      else if ( isdigit ( i ) ) {
        hasANumber= true;
      }
      if ( hasANumber && hasACapital&& hasASmallLetter) {
        correctFormat= true;
        break;
      }
    }

  return correctFormat;
}

void Login::updateUsersMap(){
  personsMap.clear();
  QVector<QVector<QString>> personTable = conn.tableFromDB("person");
  QVector<QString> usersPass = conn.usersPassword();
  QVector<QVector<QString>> usersTable = conn.tableFromDB("Users");

  for(int index=0; index < usersTable[0].size(); index++){
      User user;
      Person person;

      person.setCodePerson(personTable[0][index]);
      person.setNamePerson(personTable[1][index]);
      person.setFirstLastName(personTable[2][index]);
      person.setSecondLastName(personTable[3][index]);
      person.setBirthDay(personTable[4][index]);
      person.setUserCode(personTable[5][index]);

      user.setCode(usersTable[0][index]);
      user.setTypeUserCode(usersTable[3][index]);
      user.setUserName(usersTable[1][index]);
      user.setUserPassword(usersPass[index]);

      personsMap.emplace(personTable[5][index].toStdString(),person);
      usersMap.emplace(usersTable[1][index].toStdString(),user);
    }
}
void Login::updateActivityMap(){
  activityMap.clear();
  QVector<QVector<QString>> activityTable = conn.tableFromDB("activity");

  for (int index = 0; index < activityTable[0].size(); index++){
      Activity activityElement;

      activityElement.setCode(activityTable[0][index]);
      activityElement.setActivityName(activityTable[1][index]);
      activityElement.setActivityDescription(activityTable[2][index]);
      activityElement.setInitialDate(activityTable[3][index]);
      activityElement.setFinalDate(activityTable[4][index]);
      activityElement.setDuration(activityTable[5][index]);
      activityElement.setImageActivity(activityTable[6][index]);
      activityElement.setRegion(activityTable[7][index]);
      activityElement.setCanton(activityTable[8][index]);
      activityElement.setDistrict(activityTable[9][index]);
      activityElement.setLocation(activityTable[10][index]);
      activityElement.setActivityTypeCode(activityTable[11][index]);

      activityMap.emplace(activityTable[1][index].toStdString(),activityElement);
      indexActivityMap.emplace(index,activityTable[1][index].toStdString());
  }
}
