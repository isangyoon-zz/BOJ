#include <iostream>

int N;
bool board[15][15];
bool check1[15];
bool check2[31];
bool check3[31];

bool isPossible(int row, int col)
{
  return (check1[col] || check2[row + col] || check3[row - col + N]) ? false : true;
}

int solve(int row = 0)
{
  if (row == N) return 1;

  int count = 0;
  for (int col = 0; col < N; ++col)
  {
    if (isPossible(row, col))
    {
      check1[col] = true;
      check2[row + col] = true;
      check3[row - col + N] = true;

      board[row][col] = true;

      count += solve(row + 1);

      check1[col] = false;
      check2[row + col] = false;
      check3[row - col + N] = false;

      board[row][col] = false;
    }
  }

  return count;
}

int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  std::cin >> N;

  std::cout << solve() << std::endl;

  return 0;
}
