#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include "Activity.h"
using namespace testing;

TEST ( activityTest, setAndGetFunctionMembers ) {
    Activity activity;

    QString code = "569984245645";
    QString activityName = "___Ep1C EvEnt5";
    QString activityDescription = " AN extense description of the activity concept.";
    QString initialDate = "23/04/2019";
    QString finalDate = "28/may/19";
    QString duration = "3:17:23";
    QString imageActivity = "EP1C 1Ma6E";
    QString region = "L0s A1pes suiz0s";
    QString canton = "Somewhere !n Alpes";
    QString district = "###District###";
    QString location = "200m____, 3km___,___";
    QString activityTypeCode = "av369e";
    QString nameTypeActivity = "fest1val";
    QString descriptionTyeActivity = "This is just a generic speech to denote that this is long a string of characteres";

    activity.setCode(code);
    activity.setActivityName(activityName);
    activity.setActivityDescription(activityDescription);
    activity.setInitialDate(initialDate);
    activity.setFinalDate(finalDate);
    activity.setDuration(duration);
    activity.setImageActivity(imageActivity);
    activity.setRegion(region);
    activity.setCanton(canton);
    activity.setDistrict(district);
    activity.setLocation(location);
    activity.setActivityTypeCode(activityTypeCode);
    activity.setNameTypeActivity(nameTypeActivity);
    activity.setDescriptionTypeActivity(descriptionTyeActivity);

    EXPECT_EQ(code,activity.getCode());
    EXPECT_EQ(activityName,activity.getActivityName());
    EXPECT_EQ(activityDescription,activity.getActivityDescription());
    EXPECT_EQ(initialDate,activity.getInitialDate());
    EXPECT_EQ(finalDate,activity.getFinalDate());
    EXPECT_EQ(duration,activity.getDuration());
    EXPECT_EQ(imageActivity,activity.getImageActivity());
    EXPECT_EQ(region,activity.getRegion());
    EXPECT_EQ(canton,activity.getCanton());
    EXPECT_EQ(district,activity.getDistrict());
    EXPECT_EQ(location,activity.getLocation());
    EXPECT_EQ(activityTypeCode,activity.getActivityTypeCode());
    EXPECT_EQ(nameTypeActivity,activity.getNameTypeActivity());
    EXPECT_EQ(descriptionTyeActivity,activity.getDescriptionTypeActivity());
    }
