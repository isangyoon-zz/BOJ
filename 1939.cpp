#include <iostream>
#include <algorithm>
#include <vector>

int N, M;
int start, end;

std::vector<std::pair<int, int> > map[10001];
std::vector<int> weights;

bool bfs(int const v, int const end, int const weight, std::vector<bool>& visited)
{
  if (v == end) return true;

  for (auto const u : map[v])
  {
    if (!visited[u.first] && u.second >= weight)
    {
      visited[u.first] = true;

      if (bfs(u.first, end, weight, visited)) return true;
    }
  }

  return false;
}

int main(int argc, char const** argv)
{
  std::cin >> N >> M;

  while (M--)
  {
    int A, B, C;
    std::cin >> A >> B >> C;

    map[A].push_back({B, C});
    map[B].push_back({A, C});

    weights.push_back(C);
  }

  std::cin >> start >> end;

  std::sort(std::begin(weights), std::end(weights));

  unsigned int left = 0;
  unsigned int right = weights.size() - 1;

  int answer = 0;
  while (left <= right)
  {
    std::vector<bool> visited(N + 1, false);
    visited[start] = true;

    unsigned int mid = (left + right) / 2;
    if (bfs(start, end, weights[mid], visited))
    {
      answer = weights[mid];
      left = mid + 1;
    }
    else
    {
      right = mid - 1;
    }
  }

  std::cout << answer << std::endl;

  return 0;
}
