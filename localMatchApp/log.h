#include <iostream>
#include <string>


class log
{
public:
  log();
  ~log();

  int signUp(const std::string user, const std::string password);

  bool isEqualPass(const std::string pass, const std::string rePass);

  int entry(const std::string user, const std::string password);
};
