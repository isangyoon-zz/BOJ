#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <queue>
#include <map>

int A, B, C;
std::map<std::tuple<int, int, int>, bool> used;
std::vector<int> answers;

void bfs()
{
  std::queue<std::tuple<int, int, int> > q;

  q.push(std::make_tuple(0, 0, C));

  while (!q.empty())
  {
    const auto current = q.front();
    q.pop();

    const int a = std::get<0>(current);
    const int b = std::get<1>(current);
    const int c = std::get<2>(current);

    used[current] = true;

    if (a == 0) answers.push_back(c);

    // C -> B
    if (c > 0 && b != B)
    {
      auto diff = B - b;
      auto key = std::make_tuple(a, (c >= diff) ? B : b + c, (c >= diff) ? c - diff : 0);

      if (!used[key])
      {
        used[key] = true;
        q.push(key);
      }
    }

    // C -> A
    if (c > 0 && a != A)
    {
      auto diff = A - a;
      auto key = std::make_tuple((c >= diff) ? A : a + c, b, (c >= diff) ? c - diff : 0);

      if (!used[key])
      {
        used[key] = true;
        q.push(key);
      }
    }

    // B -> A
    if (b > 0 && a != A)
    {
      auto diff = A - a;
      auto key = std::make_tuple((b >= diff) ? A : a + b, (b >= diff) ? b - diff : 0, c);

      if (!used[key])
      {
        used[key] = true;
        q.push(key);
      }
    }

    // B -> C
    if (b > 0 && c != C)
    {
      auto diff = C - c;
      auto key = std::make_tuple(a, (b >= diff) ? b - diff : 0, (b >= diff) ? C : b + c);

      if (!used[key])
      {
        used[key] = true;
        q.push(key);
      }
    }

    // A -> B
    if (a > 0 && b != B)
    {
      auto diff = B - b;
      auto key = std::make_tuple((a >= diff) ? a - diff : 0, (a >= diff) ? B : a + b, c);

      if (!used[key])
      {
        used[key] = true;
        q.push(key);
      }
    }

    // A -> C
    if (a > 0 && c != C)
    {
      auto diff = C - c;
      auto key = std::make_tuple((a >= diff) ? a - diff : 0, b , (a >= diff) ? C : a + c);

      if (!used[key])
      {
        used[key] = true;
        q.push(key);
      }
    }
  }
}

int main(int argc, char const** argv)
{
  std::cin >> A >> B >> C;

  bfs();

  std::sort(std::begin(answers), std::end(answers));

  for(auto const answer : answers)
  {
    std::cout << answer << " ";
  }
  std::cout << std::endl;

  return 0;
}
