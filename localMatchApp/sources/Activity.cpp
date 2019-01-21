#include "Activity.h"

Activity::Activity(){}

Activity::~Activity(){}

Activity::Activity(const Activity& existingActivity)
{
    code = existingActivity.code;
    activityDescription = existingActivity.activityDescription;
    initialDate = existingActivity.initialDate;
    finalDate = existingActivity.finalDate;
    duration = existingActivity.duration;
    imageActivity = existingActivity.imageActivity;
    region = existingActivity.region;
    canton = existingActivity.canton;
    district = existingActivity.district;
    location = existingActivity.location;
    activityTypeCode = existingActivity.activityTypeCode;
    nameTypeActivity = existingActivity.nameTypeActivity;
    descriptionTypeActivity = existingActivity.descriptionTypeActivity;
}

void Activity::setCode(QString code)
{
    this->code = code;
}
QString Activity::getCode()
{
    return code;
}

void Activity::setActivityName(QString activityName)
{
    this->activityName = activityName;
}
QString Activity::getActivityName()
{
    return activityName;
}

void Activity::setActivityDescription(QString activityDescription)
{
    this->activityDescription = activityDescription;
}
QString Activity::getActivityDescription()
{
    return activityDescription;
}

void Activity::setInitialDate(QString initialDate)
{
    this->initialDate = initialDate;
}
QString Activity::getInitialDate()
{
    return initialDate;
}

void Activity::setFinalDate(QString finalDate){
    this->finalDate = finalDate;
}
QString Activity::getFinalDate(){
    return finalDate;
}

void Activity::setDuration(QString duration)
{
    this->duration=duration;
}
QString Activity::getDuration()
{
    return duration;
}

void Activity::setImageActivity(QString imageActivity)
{
    this->imageActivity = imageActivity;
}
QString Activity::getImageActivity()
{
    return imageActivity;
}

void Activity::setRegion(QString region)
{
    this->region = region;
}
QString Activity::getRegion()
{
    return region;
}

void Activity::setCanton(QString canton)
{
    this->canton = canton;
}
QString Activity::getCanton()
{
    return canton;
}

void Activity::setDistrict(QString district){
    this->district = district;
}
QString Activity::getDistrict(){
    return district;
}

void Activity::setLocation(QString location)
{
    this->location = location;
}
QString Activity::getLocation()
{
    return location;
}

void Activity::setActivityTypeCode(QString activityTypeCode)
{
    this->activityTypeCode = activityTypeCode;
}
QString Activity::getActivityTypeCode()
{
    return activityTypeCode;
}

void Activity::setNameTypeActivity(QString nameTypeActivity){
    this->nameTypeActivity = nameTypeActivity;
}
QString Activity::getNameTypeActivity(){
    return nameTypeActivity;
}

void Activity::setDescriptionTypeActivity(QString descriptionTypeActivity){
    this->descriptionTypeActivity = descriptionTypeActivity;
}
QString Activity::getDescriptionTypeActivity(){
    return descriptionTypeActivity;}
