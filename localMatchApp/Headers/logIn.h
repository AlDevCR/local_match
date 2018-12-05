#include <string>


class logIn
{
private:
  bool isEqualPass(const std::string i_password, const std::string i_repeatedPassword);
  enum connectionMessage { wrongPassword, goodEntry, doesntExists, ocupatedUser};
public:
  logIn();
  ~logIn();
  logIn ( const logIn & ) = default;
  logIn &  operator= ( const logIn & ) = default;

  int signUp(const std::string i_user, const std::string i_password, const std::string i_repeatedPassword);

  int entry(const std::string i_user, const std::string i_password);
};
