#ifndef DATABASE_H
#define DATABASE_H
#include <QtSql>
#include <QVector>


class Database
{
  private:
    QString driver = "QODBC";
    QString serverName = "PRDCR1DBASQL02";
    QString dataBaseName = "ASSISTANTLOG";
    QString userID = "astlog_adm";
    QString password = "AstLog@dm_2018";

    QString dsn = QString("DRIVER={ODBC Driver 17 for SQL Server};"
                          "SERVER=%1;"
                          "DATABASE=%2;"
                          "UID=%3;"
                          "PWD=%4;")
                          .arg(serverName)
                          .arg(dataBaseName)
                          .arg(userID)
                          .arg(password);

    QSqlDatabase appDatabase = QSqlDatabase::addDatabase(driver);

    void openSymmetricKeyForDB();

    void closeSymmetricKeyForDB();

  public:
    Database();
    ~Database();

    void openSymmetricKeyForDB();

    void closeSymmetricKeyForDB();

  public:
    Database();
    ~Database();

    QVector<QVector<QString>> tableFromDB(QString table);

    QVector<QString> usersPassword();

    void addNewUser(QString userName, QString userPassword);

    void addNewPerson(QString userName, QString name, QString firstLastName);

    void deleteUserPerson(QString userName);

};

#endif // DATABASE_H
