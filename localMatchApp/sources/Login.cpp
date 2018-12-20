#include "Login.h"
#include <iostream>

using namespace std;

Login::Login ( ) {
  // TODO: Connect to database.
}

Login::~Login ( ) {
  // TODO: Disconnect to database.
}

Login::ConnectionMessage Login::signUp ( const string& i_user, const string& i_password,
                                         const string& i_repeatedPassword ) {
  ConnectionMessage signUpConnectionState=ConnectionMessage::goodEntry;
  // TODO: Send and receive information to database.
  // This string is just created for debug process
  string userInDatabase = "Lol2018";

  if ( !hasCorrectFormat ( i_password ) || !hasCorrectFormat ( i_repeatedPassword ) ) {
    signUpConnectionState= ConnectionMessage::wrongPassword;
  }

  else if ( i_password != i_repeatedPassword ) {
    signUpConnectionState=ConnectionMessage::notEqualPasswords;
  }

  else if ( i_user==userInDatabase || i_user.length()==0) {
    signUpConnectionState= ConnectionMessage::invalidUser;
  }

  // TODO: Set user and password in table.
  return signUpConnectionState;
}

Login::ConnectionMessage Login::entry ( const string& i_user, const string& i_password ) {
  ConnectionMessage signUpConnectionState=ConnectionMessage::goodEntry;
  // TODO: Search the user and compare password
  // TODO: Query asking for password based on user
  // These strings are just created for debug process
  string userInDatabase = "Lol2018";
  string passInDatabase = "Lol2018";

  if ( i_user != userInDatabase ) {
    signUpConnectionState= ConnectionMessage::doesntExists;
  }
  else if ( i_password != passInDatabase ) {
    signUpConnectionState= ConnectionMessage::wrongPassword;
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
