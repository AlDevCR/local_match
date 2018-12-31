/**
 * \class Login
 *
 * \brief Create the connection with the database and the core.
 *
 * Check out the format of the password and check if the
 * user exists, in the sign-up function.
 */

#ifndef LOGIN_H
#define LOGIN_H

#include <string>
class Login {
 public:
  /// Message with the state of the methods "signUp" and "entry".
  enum class ConnectionMessage {
    notEqualPasswords,
    goodEntry,
    doesntExists,
    invalidUser,
    invalidName,
    invalidadLastName,
    wrongPassword
  };

  Login ( );

  ~Login ( );
  Login ( const Login& ) = default;
  Login& operator= ( const Login& ) = default;

  /** Checks the format of the password when a user wants to sign-up in the
   * application, the correct format of a password has minimum a digit, a capital letter,
   * and a small letter.*/
  bool hasCorrectFormat (const std::string &i_password );

  /** Add a new user in the application database*/
  ConnectionMessage signUp ( const std::string &i_user, const std::string &i_name,
                             const std::string &i_lastName, const std::string &i_password,
                             const std::string &i_repeatedPassword );

  /** Log-in in the database and allow the access in the application.*/
  ConnectionMessage entry (const std::string &i_user, const std::string &i_password );
};
#endif // LOGIN_H
