#include <iostream>
#include <algorithm>
#include <locale>
#include <string>

std::string word;

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  while (std::getline(std::cin, word) && !std::cin.bad() && !std::cin.eof())
  {
    std::size_t lower = 0;
    std::size_t upper = 0;
    std::size_t numeric = 0;
    std::size_t space = 0;

    std::locale locale("C");
    std::for_each(std::begin(word), std::end(word), [&](auto w) { if (std::islower(w, locale)) ++lower; else if (std::isupper(w, locale)) ++upper; else if (std::isdigit(w, locale)) ++numeric; else if (w == 0x20) ++space; });

    std::cout << lower << " " << upper << " " << numeric << " " << space << std::endl;
  }

  return 0;
}
