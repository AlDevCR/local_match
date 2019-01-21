#ifndef ACTIVITY_H
#define ACTIVITY_H
#include <QtSql>

class Activity
{
private:
    QString code;
    QString activityName;
    QString activityDescription;
    QString initialDate;
    QString finalDate;
    QString duration;
    QString imageActivity;
    QString region;
    QString canton;
    QString district;
    QString location;
    QString activityTypeCode;
    /**
     * members from TypeActivity Database table
     */
    QString nameTypeActivity;
    QString descriptionTypeActivity;

public:
    Activity();
    ~Activity();
    Activity(const Activity& existingActivity);

    void setCode(QString Code);
    void setActivityName(QString NameActivity);
    void setActivityDescription(QString ActivityDescription);
    void setInitialDate(QString InitialDate);
    void setFinalDate(QString FinalDate);
    void setDuration(QString Duration);
    void setImageActivity(QString ImageActivity);
    void setRegion(QString Region);
    void setCanton(QString Canton);
    void setDistrict(QString District);
    void setLocation(QString Location);
    void setActivityTypeCode(QString ActivityTypeCode);
    void setNameTypeActivity(QString nameTypeActivity);
    void setDescriptionTypeActivity(QString descriptionTypeActivity);

    QString getCode();
    QString getActivityName();
    QString getActivityDescription();
    QString getInitialDate();
    QString getFinalDate();
    QString getDuration();
    QString getImageActivity();
    QString getRegion();
    QString getCanton();
    QString getDistrict();
    QString getLocation();
    QString getActivityTypeCode();
    QString getNameTypeActivity();
    QString getDescriptionTypeActivity();

};

#endif // ACTIVITY_H
