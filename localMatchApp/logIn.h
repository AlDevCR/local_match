#include <string>


class logIn
{
public:
  logIn();
  ~logIn();
  logIn ( const logIn & ) = default;
  logIn &  operator= ( const logIn & ) = default;

  int signUp(const std::string i_user, const std::string i_password);

  bool isEqualPass(const std::string i_password, const std::string i_repeatedPassword);

  int entry(const std::string i_user, const std::string i_password);
};
