#include <cstdio>
#include <cstring>

const int N = 16;
const int MAX_N = N * N * N + 4;
const int MAX_M = N * N * 4 + 4;
const int MAX = N * N * N * 4 + 100;

int _answer[MAX_N];
int _depth;

struct ID
{
  int x, y;
  int number;

  ID() {}
  ID(int x, int y, int number) : x(x), y(y), number(number) {}
};

class DLX
{
public:
  DLX() {}
  ~DLX() {}

  void initialize(int n, int m)
  {
    _n = n;
    _m = m;

    for (int i = 0; i <= _m; ++i)
    {
      _S[i] = 0;
      _U[i] = _D[i] = i;
      _L[i] = i - 1;
      _R[i] = i + 1;
    }

    _R[_m] = 0;
    _L[0] = _m;

    _size = _m;

    for (int i = 1; i <= _n; ++i)
    {
      _H[i] = -1;
    }
  }

  void link(int r, int c)
  {
    ++_S[_COL[++_size] = c];
    _ROW[_size] = r;

    _D[_size] = _D[c];
    _U[_D[c]] = _size;
    _U[_size] = c;
    _D[c] = _size;

    if (_H[r] < 0)
    {
      _H[r] = _L[_size] = _R[_size] = _size;
    }
    else
    {
      _R[_size] = _R[_H[r]];
      _L[_R[_H[r]]] = _size;
      _L[_size] = _H[r];
      _R[_H[r]] = _size;
    }
  }

  void resume(int c)
  {
    for (int i = _U[c]; i != c; i = _U[i])
    {
      for (int j = _L[i]; j != i; j = _L[j])
      {
        ++_S[_COL[_U[_D[j]] = _D[_U[j]] = j]];
      }
    }

    _L[_R[c]] = _R[_L[c]] = c;
  }

  void remove(int c)
  {
    _L[_R[c]] = _L[c];
    _R[_L[c]] = _R[c];

    for (int i = _D[c]; i != c; i = _D[i])
    {
      for (int j = _R[i]; j != i; j = _R[j])
      {
        _U[_D[j]] = _U[j];
        _D[_U[j]] = _D[j];

        --_S[_COL[j]];
      }
    }
  }

  bool dance(int depth)
  {
    if (_R[0] == 0)
    {
      _depth = depth;

      return true;
    }

    int c = _R[0];
    for (int i = _R[0]; i != 0; i = _R[i])
    {
      if (_S[c] > _S[i])
      {
        c = i;
      }
    }
    remove(c);

    for (int i = _D[c]; i != c; i = _D[i])
    {
      _answer[depth] = _ROW[i];

      for (int j = _R[i]; j != i; j = _R[j]) remove(_COL[j]);

      if (dance(depth + 1)) return true;

      for (int j = _L[i]; j != i; j = _L[j]) resume(_COL[j]);
    }
    resume(c);

    return false;
  }

private:
  int _n, _m;
  int _size;
  int _U[MAX], _D[MAX], _L[MAX], _R[MAX];
  int _ROW[MAX], _COL[MAX];
  int _H[MAX_N], _S[MAX_M];
};

char board[1001];
ID id[MAX_N];
DLX dlx;

void solve()
{
  int n = 0;
  int m = N * N * 4;

  for (int i = 0, length = std::strlen(board); i < length; ++i)
  {
    if (board[i] == '-') n += 16;
    else ++n;
  }

  dlx.initialize(n, m);

  n = 0;
  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < N; ++j)
    {
      char c = board[i * N + j];

      if (c == '-')
      {
        for (int k = 1; k <= N; ++k)
        {
          id[++n] = ID(i, j, k);

          dlx.link(n, i * N + k);
          dlx.link(n, j * N + k + N * N);
          dlx.link(n, (i / 4 * 4 + j / 4) * N + k + N * N * 2);
          dlx.link(n, i * N + j + 1 + N * N * 3);
        }
      }
      else
      {
        id[++n] = ID(i, j, c - 'A' + 1);

        dlx.link(n, i * N + c - 'A' + 1);
        dlx.link(n, j * N + c - 'A' + 1 + N * N);
        dlx.link(n, (i / 4 * 4 + j / 4) * N + c - 'A' + 1 + N * N * 2);
        dlx.link(n, i * N + j + 1 + N * N * 3);
      }
    }
  }

  if (!dlx.dance(0)) return;
  else
  {
    for (int i = _depth - 1; i >= 0; --i)
    {
      int number = _answer[i];

      board[id[number].x * N + id[number].y] = id[number].number + 'A' - 1;
    }

    for (int i = 0; i < N * N; ++i)
    {
      printf("%c", board[i]);

      if ((i + 1) % N == 0) printf("\n");
    }
    printf("\n");
  }
}

int main(int const argc, char const** argv)
{
  while (scanf("%s", board) != EOF)
  {
    for (int i = 1; i < N; ++i) scanf("%s", board + i * N);

    solve();
  }

  return 0;
}
