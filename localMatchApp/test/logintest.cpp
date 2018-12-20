#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include "Login.h"
using namespace testing;

/// Check if the "hasCorrectFormat" function validate
/// the good cases, when the password is correct.
TEST ( LoginTest, TestPasswordGoodCases ) {
  Login objectOfTest;

  std::string normalPassword = "Robert0";
  std::string minimumPassword = "R0i";
  std::string longPasswordOfNumbers = "4123412341234123412RR12341234123r";
  std::string longPasswordOfCapital = "EWRTWERGDFSGSD3DFGDFGSDFr";
  std::string longPasswordOfLittle = "wertwertwerw4wertwerRtwert";
  std::string minimumPassword2 = "Il0";

  EXPECT_TRUE ( objectOfTest.hasCorrectFormat ( normalPassword ) );
  EXPECT_TRUE ( objectOfTest.hasCorrectFormat ( minimumPassword ) );
  EXPECT_TRUE ( objectOfTest.hasCorrectFormat ( longPasswordOfNumbers ) );
  EXPECT_TRUE ( objectOfTest.hasCorrectFormat ( longPasswordOfCapital ) );
  EXPECT_TRUE ( objectOfTest.hasCorrectFormat ( longPasswordOfLittle ) );
  EXPECT_TRUE ( objectOfTest.hasCorrectFormat (minimumPassword2 ) );
}

/// Check if the "hasCorrectFormat" function validate
/// the bad cases, when the password isn't correct.
TEST ( LoginTest, TestPasswordBadCases ) {
  Login objectOfTest;

  std::string allCapital = "ROBERTO";
  std::string allLittle = "roberto";
  std::string allNumbers = "4083470";
  std::string empty = "";
  std::string littleAndNumbers = "sdfgsdfg9sdf";
  std::string capitalAndLittle = "EWRTWERsdfgsd";

  EXPECT_FALSE ( objectOfTest.hasCorrectFormat ( allCapital ) );
  EXPECT_FALSE ( objectOfTest.hasCorrectFormat ( allLittle ) );
  EXPECT_FALSE ( objectOfTest.hasCorrectFormat ( allNumbers ) );
  EXPECT_FALSE ( objectOfTest.hasCorrectFormat ( empty ) );
  EXPECT_FALSE ( objectOfTest.hasCorrectFormat ( littleAndNumbers ) );
  EXPECT_FALSE ( objectOfTest.hasCorrectFormat ( capitalAndLittle ) );
}

/// Check the signUp function, with all the possible returns.
TEST(LoginTest, TestSignUp){
  Login objectOfTest;

  std::string emptyUserspace = "";
  std::string sameUser = "Lol2018";
  std::string newUser = "newUser";
  std::string goodPass = "Lol2018";
  std::string wrongPassGoodFormat = "Il0";
  std::string BadPass = "lol";

  EXPECT_EQ(Login::ConnectionMessage::goodEntry,objectOfTest.signUp(newUser,goodPass,goodPass));
  EXPECT_EQ(Login::ConnectionMessage::invalidUser,objectOfTest.signUp(sameUser,goodPass,goodPass));
  EXPECT_EQ(Login::ConnectionMessage::invalidUser,objectOfTest.signUp(emptyUserspace,goodPass,goodPass));
  EXPECT_EQ(Login::ConnectionMessage::wrongPassword,objectOfTest.signUp(newUser,BadPass,goodPass));
  EXPECT_EQ(Login::ConnectionMessage::wrongPassword,objectOfTest.signUp(newUser,goodPass,BadPass));
  EXPECT_EQ(Login::ConnectionMessage::notEqualPasswords,objectOfTest.signUp(newUser,goodPass,wrongPassGoodFormat));
}

/// Check the entry function with all the possible returns.
TEST(LoginTest, TestEntry){
  Login objectOfTest;

  std::string sameUser = "Lol2018";
  std::string anotherUser = "newUser";
  std::string goodPass = "Lol2018";
  std::string basPass = "Il0";

  EXPECT_EQ(Login::ConnectionMessage::goodEntry,objectOfTest.entry(sameUser,goodPass));
  EXPECT_EQ(Login::ConnectionMessage::doesntExists,objectOfTest.entry(anotherUser,goodPass));
  EXPECT_EQ(Login::ConnectionMessage::wrongPassword,objectOfTest.entry(sameUser,basPass));
  EXPECT_EQ(Login::ConnectionMessage::doesntExists,objectOfTest.entry(anotherUser,basPass));

}
