#include "GeneralEvent.h"

GeneralEvent::GeneralEvent()
{
    idEvent = 0;
    totalEvents = 0;
    nameEvent = "";
    typeEvent = "";
    descriptionEvent = "";
    initialDateEvent = "";
    finalDateEvent = "";
    provinceEvent = "";
    cantonEvent = "";
    districtEvent = "";
    locationEvent = "";
    imageEvent = "";
}

GeneralEvent::~GeneralEvent(){}

void GeneralEvent::setIdEvent(int i_valueIdEvent)
{
    idEvent = i_valueIdEvent;
}
int GeneralEvent::getIdEvent()
{
    return idEvent;
}

void GeneralEvent::setTotalEvents(int i_valueTotalEvents)
{
    totalEvents = i_valueTotalEvents;
}
int GeneralEvent::getTotalEvents()
{
    return totalEvents;
}

void GeneralEvent::setNameEvent(QString i_valueNameEvent)
{
    nameEvent = i_valueNameEvent;
}
QString GeneralEvent::getNameEvent()
{
    return nameEvent;
}

void GeneralEvent::setTypeEvent ( QString i_valueTypeEvent ) {
  typeEvent = i_valueTypeEvent;
}
QString GeneralEvent::getTypeEvent ( ) {
  return typeEvent;
}

void GeneralEvent::setDescriptionEvent(QString i_valueDescriptionEvent)
{
    descriptionEvent = i_valueDescriptionEvent;
}
QString GeneralEvent::getDescriptionEvent()
{
    return descriptionEvent;
}

void GeneralEvent::setInitialDateEvent(QString i_valueInitialDateEvent)
{
    initialDateEvent = i_valueInitialDateEvent;
}
QString GeneralEvent::getInitialDateEvent()
{
    return initialDateEvent;
}

void GeneralEvent::setFinalDateEvent(QString i_valueFinalDateEvent)
{
    finalDateEvent = i_valueFinalDateEvent;
}
QString GeneralEvent::getFinalDateEvent()
{
    return finalDateEvent;
}

void GeneralEvent::setProvinceEvent ( QString i_valueProvinceEvent ) {
  provinceEvent = i_valueProvinceEvent;
}
QString GeneralEvent::getProvinceEvent ( ) {
  return provinceEvent;
}

void GeneralEvent::setCantonEvent ( QString i_valueCantonEvent ) {
  cantonEvent = i_valueCantonEvent;
}
QString GeneralEvent::getCantonEvent ( ) {
  return cantonEvent;
}

void GeneralEvent::setDistrictEvent ( QString i_valueDistrictEvent ) {
  districtEvent = i_valueDistrictEvent;
}
QString GeneralEvent::getDistrictEvent ( ) {
  return districtEvent;
}

void GeneralEvent::setLocationEvent ( QString i_valueLocationEvent ) {
  locationEvent = i_valueLocationEvent;
}
QString GeneralEvent::getLocationEvent ( ) {
  return locationEvent;
}

void GeneralEvent::setImageEvent(QString i_valueImageEvent)
{
    imageEvent = i_valueImageEvent;
}
QString GeneralEvent::getImageEvent()
{
    return imageEvent;
}
