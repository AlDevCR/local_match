#include "Database.h"
#include <QtSql>
#include <QtDebug>
#include <cstdlib>
#include <QVector>
#include "Login.h"

using namespace std;

Database::Database()
{
  appDatabase.setConnectOptions();
  appDatabase.setDatabaseName(dsn);

  if(!appDatabase.open())
  {
    qDebug() << "Error: " << appDatabase.lastError().text();
  }
}

Database::~Database()
{
  appDatabase.close();
}

void Database::openSymmetricKeyForDB()
{
  QSqlQuery query{};

  if(!query.exec(("OPEN SYMMETRIC KEY SymmetricKey_Local_Match "
                   "DECRYPTION BY CERTIFICATE Certificate_Local_Match;")))
  {
    qDebug() << "ERROR opening key"  << query.lastError().text() << endl;;
  }
}

void Database::closeSymmetricKeyForDB()
{
  QSqlQuery query{};

  if(!query.exec(("CLOSE SYMMETRIC KEY SymmetricKey_Local_Match;")))
  {
    qDebug() << "ERROR closing key"  << query.lastError().text() << endl;
  }
}

QVector<QString> Database::usersPassword()
{
  QSqlQuery query{};
  QString queryResult{};
  QVector<QString> passwordField{};
  int queryField = 0;

  openSymmetricKeyForDB();

  if(query.exec(QString("SELECT CONVERT(varchar, DecryptByKey(user_password)) AS 'Password' "
                        "FROM users")))
  {
    while(query.next())
    {
      queryResult = query.value(queryField).toString();
      passwordField.push_back(queryResult);
    }
  }
  else
  {
    qDebug() << "Error";
  }

  closeSymmetricKeyForDB();

  return passwordField;
}

QVector<QVector<QString>> Database::tableFromDB(QString table)
{
  QSqlQuery query{};
  QString queryResult{};
  QVector<QString> passwordField{};
  int queryField = 0;

  query.exec(QString("OPEN SYMMETRIC KEY SymmetricKey_Local_Match "
                     "DECRYPTION BY CERTIFICATE Certificate_Local_Match;"));

  if(query.exec(QString("SELECT CONVERT(varchar, DecryptByKey(user_password)) AS 'Password' "
                        "FROM users CLOSE SYMMETRIC KEY SymmetricKey_Local_Match;")))
  {
    while(query.next())
    {
      field.clear();
      query.first();
      query.previous();
      while(query.next())
      {
        if(queryField == 2 && table == "users")
        {
          field = usersPassword();
        }
        else
        {
          queryResult = query.value(queryField).toString();
          field.push_back(queryResult);
        }
      }
      completeTable.push_back(field);
      queryField += 1;
    }
  }
  else
  {
    qDebug() << "Error";
  }
  return passwordField;
}

void Database::addNewUser(QString userName, QString userPassword)
{
  QSqlQuery query{};
  QString userType = "3";

  openSymmetricKeyForDB();

  if(!query.exec(QString("DECLARE @type_user_exists AS INT "
                         "DECLARE @user_exists AS VARCHAR(50)"
                         "SET @type_user_exists = (SELECT code FROM type_user "
                         "WHERE code = %3)"
                         "SET @user_exists = (SELECT user_name FROM users "
                         "WHERE user_name = '%1')"
                         "IF @type_user_exists = %3"
                         "IF @user_exists IS NULL "
                         "BEGIN "
                         "INSERT INTO users"
                         "(user_name"
                         ",user_password"
                         ",type_user_code"
                         ",image_user)"
                         "VALUES"
                         "('%1'"
                         ",EncryptByKey (Key_GUID('SymmetricKey_Local_Match'),'%2')"
                         ",%3"
                         ",null)"
                         "END")
                .arg(userName)
                .arg(userPassword)
                .arg(userType)
                ))
  {
    qDebug() << "ERROR adding user " << query.lastError().text() << endl;
  }
  else
  {
    query.clear();
  }

  closeSymmetricKeyForDB();
}

void Database::addNewPerson(QString userName, QString name, QString firstLastName) {
  QSqlQuery query{};

  if(!query.exec(QString("DECLARE @person_exists AS INT "
                         "DECLARE @user_exists  AS INT "
                         "SET @user_exists = (SELECT code FROM users "
                         "WHERE user_name = '%1')"
                         "IF @user_exists IS NOT NULL "
                         "SET @person_exists = (SELECT user_code FROM person "
                         "WHERE user_code = @user_exists) "
                         "IF @user_exists IS NOT NULL "
                         "IF @person_exists IS NULL "
                         "BEGIN "
                         "INSERT INTO person"
                         "(name_person"
                         ",first_last_name"
                         ",second_last_name"
                         ",birth_date"
                         ",user_code) "
                         "VALUES "
                         "('%2'"
                         ",'%3'"
                         ",'CABRON'"
                         ",'0001-01-01'"
                         ",@user_exists)"
                         "END")
                 .arg(userName)
                 .arg(name)
                 .arg(firstLastName)
                 ))
  {
    qDebug() << "ERROR adding person " << query.lastError().text() << endl;
  }
  else
  {
    query.clear();
  }
}

void Database::deleteUserPerson(QString userName)
{
  QSqlQuery query{};

  if(!query.exec(QString("DECLARE @is_in_activities AS INT "
                         "DECLARE @is_in_person AS INT "
                         "DECLARE @user_exists AS INT "
                         "SET @user_exists = (SELECT TOP 1 code FROM users "
                         "WHERE user_name = '%1') "
                         "IF @user_exists IS NOT NULL "
                         "BEGIN "
                         "SET @is_in_activities = (SELECT TOP 1 user_code "
                         "FROM user_activity WHERE user_code = @user_exists) "
                         "SET @is_in_person = (SELECT TOP 1 user_code "
                         "FROM person WHERE user_code = @user_exists) "
                         "END "
                         "IF @is_in_activities IS NOT NULL "
                         "BEGIN "
                         "DELETE FROM user_activity "
                         "WHERE user_code = @user_exists "
                         "END "
                         "IF @is_in_person IS NOT NULL "
                         "BEGIN "
                         "DELETE FROM person "
                         "WHERE user_code = @user_exists "
                         "END "
                         "IF @user_exists IS NOT NULL "
                         "DELETE FROM users "
                         "WHERE code = @user_exists")
                 .arg(userName)
                 ))
  {
    qDebug() << "ERROR deleting person and user " << query.lastError().text() << endl;
  }
  else
  {
    query.clear();
  }
}

void Database::addNewUser(QString userName, QString userPassword)
{
  QSqlQuery query{};
  QString userType = "3";

  openSymmetricKeyForDB();

  if(!query.exec(QString("DECLARE @type_user_exists AS INT "
                         "DECLARE @user_exists AS VARCHAR(50)"
                         "SET @type_user_exists = (SELECT code FROM type_user "
                         "WHERE code = %3)"
                         "SET @user_exists = (SELECT user_name FROM users "
                         "WHERE user_name = '%1')"
                         "IF @type_user_exists = %3"
                         "IF @user_exists IS NULL "
                         "BEGIN "
                         "INSERT INTO users"
                         "(user_name"
                         ",user_password"
                         ",type_user_code"
                         ",image_user)"
                         "VALUES"
                         "('%1'"
                         ",EncryptByKey (Key_GUID('SymmetricKey_Local_Match'),'%2')"
                         ",%3"
                         ",null)"
                         "END")
                .arg(userName)
                .arg(userPassword)
                .arg(userType)
                ))
  {
    qDebug() << "ERROR adding user " << query.lastError().text() << endl;
  }
  else
  {
    query.clear();
  }

  closeSymmetricKeyForDB();
}

void Database::addNewPerson(QString userName, QString name, QString firstLastName) {
  QSqlQuery query{};

  if(!query.exec(QString("DECLARE @person_exists AS INT "
                         "DECLARE @user_exists  AS INT "
                         "SET @user_exists = (SELECT code FROM users "
                         "WHERE user_name = '%1')"
                         "IF @user_exists IS NOT NULL "
                         "SET @person_exists = (SELECT user_code FROM person "
                         "WHERE user_code = @user_exists) "
                         "IF @user_exists IS NOT NULL "
                         "IF @person_exists IS NULL "
                         "BEGIN "
                         "INSERT INTO person"
                         "(name_person"
                         ",first_last_name"
                         ",second_last_name"
                         ",birth_date"
                         ",user_code) "
                         "VALUES "
                         "('%2'"
                         ",'%3'"
                         ",'CABRON'"
                         ",'0001-01-01'"
                         ",@user_exists)"
                         "END")
                 .arg(userName)
                 .arg(name)
                 .arg(firstLastName)
                 ))
  {
    qDebug() << "ERROR adding person " << query.lastError().text() << endl;
  }
  else
  {
    query.clear();
  }
}

void Database::deleteUserPerson(QString userName)
{
  QSqlQuery query{};

  if(!query.exec(QString("DECLARE @is_in_activities AS INT "
                         "DECLARE @is_in_person AS INT "
                         "DECLARE @user_exists AS INT "
                         "SET @user_exists = (SELECT TOP 1 code FROM users "
                         "WHERE user_name = '%1') "
                         "IF @user_exists IS NOT NULL "
                         "BEGIN "
                         "SET @is_in_activities = (SELECT TOP 1 user_code "
                         "FROM user_activity WHERE user_code = @user_exists) "
                         "SET @is_in_person = (SELECT TOP 1 user_code "
                         "FROM person WHERE user_code = @user_exists) "
                         "END "
                         "IF @is_in_activities IS NOT NULL "
                         "BEGIN "
                         "DELETE FROM user_activity "
                         "WHERE user_code = @user_exists "
                         "END "
                         "IF @is_in_person IS NOT NULL "
                         "BEGIN "
                         "DELETE FROM person "
                         "WHERE user_code = @user_exists "
                         "END "
                         "IF @user_exists IS NOT NULL "
                         "DELETE FROM users "
                         "WHERE code = @user_exists")
                 .arg(userName)
                 ))
  {
    qDebug() << "ERROR deleting person and user " << query.lastError().text() << endl;
  }
  else
  {
    query.clear();
  }
}
