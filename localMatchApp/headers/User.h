#ifndef USER_H
#define USER_H
#include <QtSql>

class User
{

private:
  QString code;
  QString userName;
  QString userPassword;
  QString typeUserCode;
  QString imageUser;
  /**
   * members from TypeUser Database table
   */
  QString nameTypeUser;
  QString descriptionTypeUser;

public:
  User();
  ~User();
  User(const User &User2);

  QString getCode();
  QString getUserName();
  QString getUserPassword();
  QString getTypeUserCode();
  QString getImageUser();
  QString getNameTypeUser();
  QString getDescriptionTypeUser();

  void setCode(QString newCode);
  void setUserName(QString newUserName);
  void setUserPassword(QString newUserPassword);
  void setTypeUserCode(QString newTypeUser);
  void setImageUser(QString newImageUser);
  void setNameTypeUser(QString nameTypeUser);
  void setDescriptionTypeUser(QString descriptionTypeUser);
};

#endif // USER_H
