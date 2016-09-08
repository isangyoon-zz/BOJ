#include <iostream>
#include <vector>

int T;
int next[100001];
std::vector<int> degree;
std::vector<bool> visited;

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> T;

  while (T--)
  {
    int N;
    std::cin >> N;

    degree.assign(N + 1, 0);
    visited.assign(N + 1, false);

    for (auto i = 1; i <= N; ++i)
    {
      std::cin >> next[i];
      ++degree[next[i]];
    }

    int answer = 0;
    for (auto i = 1; i <= N; ++i)
    {
      int current = i;

      while (!degree[current] && !visited[current])
      {
        visited[current] = true;
        --degree[next[current]];

        current = next[current];

        ++answer;
      }
    }

    std::cout << answer << std::endl;
  }

  return 0;
}
