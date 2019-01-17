#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include "GeneralEvent.h"

/*!
 * It is created to
 * be able to develop the functions
 * that will manage the database
 */
class DatabaseManager {
 public:
  DatabaseManager ();

  ~DatabaseManager ();

  DatabaseManager(const DatabaseManager &event) = default;

  DatabaseManager &operator= (const DatabaseManager &event) = default;

  /*!
   * It selects the information of the events
   * needed by the home user interface of the events
   */
  GeneralEvent selectEvent ( int i_index );

private:

  /*! It saves the id of the event */
  int idEvent;

  /*! It saves the total of the events */
  int totalEvents;

  /*! It saves the name of the event */
  QString nameEvent;

  /*! It saves the type of the event */
  QString typeEvent;

  /*! It saves the description of the event */
  QString descriptionEvent;

  /*! It saves the initial date of the event */
  QString initialDateEvent;

  /*! It saves the final date of the event */
  QString finalDateEvent;

  /*! It saves the province of the event */
  QString provinceEvent;

  /*! It saves the canton of the event */
  QString cantonEvent;

  /*! It saves the district of the event */
  QString districtEvent;

  /*! It saves the location of the event */
  QString locationEvent;

  /*! It saves the image of the event */
  QString imageEvent;
};

#endif // DATABASEMANAGER_H
