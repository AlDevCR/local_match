#include "Headers/logIn.h"

using namespace std;

logIn::logIn()
{
    //Connect to database.
}

logIn::~logIn()
{
    //Disconnect to database.
}

int logIn::signUp(const string i_user, const string i_password, const string i_repeatedPassword)
{
  //Send information to database.
  string userInDatabase="";
  if(i_user.compare(userInDatabase) == 0)
    {
      if(isEqualPass(i_password,i_repeatedPassword))
        {
          //Set user and password in table
          return connectionMessage::goodEntry;
        }
      else
        {
          return connectionMessage::wrongPassword;
        }
    }
  else
    {
      return connectionMessage::ocupatedUser;
    }
}

bool logIn::isEqualPass(const string i_password, const string i_repeatedPassword)
{
  //Compare strings and return TRUE for equal.
  if (i_password.compare(i_repeatedPassword) != 0)
    {
      return false;
    }
  else
    {
      return true;
    }
}

int logIn::entry(const string i_user, const string i_password)
{
  //Search the user and compare password
  //Query asking for password based on user
  string userInDatabase="";
  string passInDatabase="";
  if(i_user.compare(userInDatabase) != 0)
    {
      return connectionMessage::doesntExists;
    }
  else if (i_password.compare(passInDatabase) != 0)
    {
      return connectionMessage::wrongPassword;
    }
  else
    {
      return connectionMessage::goodEntry;
    }
}
