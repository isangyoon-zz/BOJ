#include <iostream>

const int DIVIDOR = 3;
const int N = DIVIDOR * DIVIDOR;
const int EMPTY = 0;

int board[N][N];

bool findEmpty(int& i, int& j)
{
  for (i = 0; i < N; ++i)
  {
    for (j = 0; j < N; ++j)
    {
      if (board[i][j] == EMPTY) return true;
    }
  }

  return false;
}

bool usedInRow(int row, int number)
{
  for (int col = 0; col < N; ++col)
  {
    if (board[row][col] == number) return true;
  }

  return false;
}

bool usedInColumn(int col, int number)
{
  for (int row = 0; row < N; ++row)
  {
    if (board[row][col] == number) return true;
  }

  return false;
}

bool usedInBox(int row, int col, int number)
{
  for (int i = 0; i < DIVIDOR; ++i)
  {
    for (int j = 0; j < DIVIDOR; ++j)
    {
      if (board[i + row][j + col] == number) return true;
    }
  }

  return false;
}

bool isPossible(int row, int col, int number)
{
  return !usedInRow(row, number) && !usedInColumn(col, number) && !usedInBox(row - row % DIVIDOR, col - col % DIVIDOR, number);
}

bool solve()
{
  int row, col;

  if (!findEmpty(row, col)) return true;

  for (int i = 1; i <= N; ++i)
  {
    if (isPossible(row, col, i))
    {
      board[row][col] = i;

      if (solve()) return true;

      board[row][col] = EMPTY;
    }
  }

  return false;
}


int main(int const argc, char const** argv)
{
  std::ios::sync_with_stdio(false);

  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < N; ++j)
    {
      std::cin >> board[i][j];
    }
  }

  if (solve())
  {
    for (int i = 0; i < N; ++i)
    {
      for (int j = 0; j < N; ++j)
      {
        std::cout << board[i][j] << " ";
      }
      std::cout << std::endl;
    }
  }

  return 0;
}
