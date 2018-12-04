#include "log.h"

using namespace std;

log::log()
{
    //Connect to database.
}

log::~log()
{
    //disconnect to database.
}

int log::signUp(const string user, const string password)
{
  //Send information to database.
  return 0;
}

bool log::isEqualPass(const string pass, const string rePass)
{
  //Compare strings and return TRUE for equal.
  return true;
}

int log::entry(const string user, const string password)
{
  //search the user and compare password
  return 0;
}
