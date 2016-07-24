#include <iostream>

const int next[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int map[501][501];
int visited[501][501];

int M, N;

bool movable(int x, int y)
{
    return (x > 0) && (x <= M) && (y > 0) && (y <= N);
}

int dfs(int x, int y)
{
    if(x == M && y == N) return 1;
    if(visited[x][y]) return visited[x][y];

    for(auto i = 0; i < 4; ++i)
    {
        int next_x = x + next[i][0];
        int next_y = y + next[i][1];

        if((map[x][y] > map[next_x][next_y]) && movable(next_x, next_y))
        {
            visited[x][y] += dfs(next_x, next_y);
        }
    }

    return visited[x][y];
}

int main(int argc, char** argv)
{
    std::ios::sync_with_stdio(false);

    std::cin >> M >> N;

    for(auto i = 1; i <= M; ++i)
    {
        for(auto j = 1; j <= N; ++j)
        {
            std::cin >> map[i][j];
        }
    }

    int H = dfs(1, 1);
    std::cout << H << std::endl;

    return 0;
}
