#include <iostream>
#include <string>

std::string N;

int main(int const argc, char const** argv)
{
  std::cin >> N;

  bool flag = false;

  if (N.length() == 1 && N[0] - '0' == 0) std::cout << "0";
  for (auto const c : N)
  {
    int num = c - '0';

    if (num < 4 && !flag)
    {
      if (num == 0) continue;
      else if (num == 1) std::cout << "1";
      else if (num == 2) std::cout << "10";
      else if (num == 3) std::cout << "11";

      flag = true;
    }
    else
    {
      if (num == 0) std::cout << "000";
      else if (num == 1) std::cout << "001";
      else if (num == 2) std::cout << "010";
      else if (num == 3) std::cout << "011";
      else if (num == 4) std::cout << "100";
      else if (num == 5) std::cout << "101";
      else if (num == 6) std::cout << "110";
      else if (num == 7) std::cout << "111";

      flag = true;
    }
  }
  std::cout << std::endl;

  return 0;
}
