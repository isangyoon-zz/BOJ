#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

int t[511];
std::vector<int> adj[511];
int indgree[511];
bool win[511][511];

int T;
int N, M;

int main(int argc, char const** argv)
{
  std::cin >> T;

  while(T--)
  {
    std::cin >> N;

    for (auto i = 1; i <= N; ++i)
    {
      std::cin >> t[i];

      adj[i].clear();
      indgree[i] = 0;

      for (auto j = 1; j <= N; ++j)
      {
        win[i][j] = false;
      }
    }

    for (auto i = 1; i <= N; ++i)
    {
      for (auto j = i + 1; j <= N; ++j)
      {
        ++indgree[t[j]];

        adj[t[i]].push_back(t[j]);
        win[t[i]][t[j]] = true;
      }
    }

    std::cin >> M;

    for (auto i = 1; i <= M; ++i)
    {
      int A, B;
      std::cin >> A >> B;

      if (win[A][B])
      {
        --indgree[B];
        ++indgree[A];

        adj[A].erase(std::find(std::begin(adj[A]), std::end(adj[A]), B));
        adj[B].push_back(A);
      }
      else
      {
        ++indgree[B];
        --indgree[A];

        adj[B].erase(std::find(std::begin(adj[B]), std::end(adj[B]), A));
        adj[A].push_back(B);
      }
    }

    std::queue<int> q;
    for (auto i = 1; i <= N; ++i)
    {
      if (!indgree[i]) q.push(i);
    }

    bool isAmbiguous = (q.size() > 1) ? true : false;

    std::vector<int> answers;
    while (!q.empty() && !isAmbiguous)
    {
      int v = q.front();
      q.pop();

      answers.push_back(v);

      for (auto const u : adj[v])
      {
        --indgree[u];

        if (!indgree[u]) q.push(u);
      }

      isAmbiguous = (q.size() > 1) ? true : false;
    }

    if (isAmbiguous)
    {
      std::cout << "?" << std::endl;
    }
    else
    {
      if (answers.size() != N)
      {
        std::cout << "IMPOSSIBLE" << std::endl;
      }
      else
      {
        for (auto const answer : answers)
        {
          std::cout << answer << " ";
        }
        std::cout << std::endl;
      }
    }
  }

  return 0;
}
