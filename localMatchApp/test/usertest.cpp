#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include "User.h"
using namespace testing;

TEST ( UserTest, setAndGetFunctionMembers ) {
    User user;

    QString code = "123";
    QString userName = "USuaR10";
    QString password = "m0la.hund0";
    QString userCode = "a@!45J%q";
    QString userImage = "Happy ;-) Face";
    QString typeUser = "single";
    QString description = "This is just a generic speech to denote that this is long a string of characteres";

    user.setCode(code);
    user.setUserName(userName);
    user.setUserPassword(password);
    user.setTypeUserCode(userCode);
    user.setImageUser(userImage);
    user.setNameTypeUser(typeUser);
    user.setDescriptionTypeUser(description);

    EXPECT_EQ(code,user.getCode());
    EXPECT_EQ(userName,user.getUserName());
    EXPECT_EQ(password,user.getUserPassword());
    EXPECT_EQ(userCode,user.getTypeUserCode());
    EXPECT_EQ(userImage,user.getImageUser());
    EXPECT_EQ(typeUser,user.getNameTypeUser());
    EXPECT_EQ(description,user.getDescriptionTypeUser());
}
