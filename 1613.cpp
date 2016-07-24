#include <cstdio>

int N, K, S;
int adj[401][401];

void floyd()
{
  for (int k = 1; k <= N; ++k)
  {
    for (int i = 1; i <= N; ++i)
    {
      for (int j = 1; j <= N; ++j)
      {
        if ((adj[i][k] == -1 || adj[i][k] == 1) && (adj[i][k] == adj[k][j]))
        {
          adj[i][j] = adj[i][k];
        }
      }
    }
  }
}

int main(int argc, char const** argv)
{
  scanf("%d %d", &N, &K);

  for (auto i = 1; i <= K; ++i)
  {
    int n1, n2;
    scanf("%d %d", &n1, &n2);

    adj[n1][n2] = -1;
    adj[n2][n1] = 1;
  }

  floyd();

  scanf("%d", &S);

  for (auto i = 1; i <= S; ++i)
  {
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    printf("%d\n", adj[n1][n2]);
  }

  return 0;
}
