#include <cstdio>
#include <algorithm>
#include <string>
#include <map>

int N, M;
std::map<std::string, std::string> dictionary1;
std::map<std::string, int> dictionary2;

int main(int const argc, char const** argv)
{
  scanf("%d %d", &N, &M);

  for (int i = 0; i < N; ++i)
  {
    char name[21];
    scanf("%s", name);

    std::string key = name;

    dictionary1[std::to_string(i + 1)] = key;
    dictionary2[key] = i + 1;
  }

  for (int i = 0; i < M; ++i)
  {
    char k[21];
    scanf("%s", k);

    std::string key = k;

    if (dictionary1.find(key) != std::end(dictionary1))
    {
      printf("%s\n", dictionary1[key].c_str());
    }
    else
    {
      printf("%d\n", dictionary2[key]);
    }
  }

  return 0;
}
