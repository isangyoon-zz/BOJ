#include <iostream>
#include <vector>
#include <queue>
#include <functional>

typedef int Integer;
typedef unsigned long long BigInteger;
typedef std::pair<Integer, BigInteger> Node;
typedef std::vector<Node> Graph;

const int INF = 100000000;

int N, M, X;

Graph a[1000001];
std::vector<BigInteger> distance;
std::vector<bool> visited;

void dijkstra(int start)
{
	distance.assign(N + 1, INF);
	visited.assign(N + 1, false);

	distance[start] = 0;

	auto compare = [](Node const& lhs, Node const& rhs) { return lhs.second > rhs.second; };
	std::priority_queue<Node, std::vector<Node>, decltype(compare)> q(compare);

	q.push({ start, 0 });

	while (!q.empty())
	{
		Node v = q.top();
		q.pop();

		if (visited[v.first]) continue;
		visited[v.first] = true;

		for (unsigned int i = 0; i < a[v.first].size(); ++i)
		{
			if (!visited[a[v.first][i].first] && distance[a[v.first][i].first] > a[v.first][i].second + v.second)
			{
				q.push({ a[v.first][i].first, (distance[a[v.first][i].first] = a[v.first][i].second + v.second) });
			}
		}
	}
}

int main(int argc, char** argv)
{
  std::ios::sync_with_stdio(false);
  
	std::cin >> N >> M >> X;

	for (auto i = 1; i <= M; ++i)
	{
		Integer from, to;
		BigInteger cost;

		std::cin >> from >> to >> cost;

		a[from].push_back({ to, cost });
	}

	std::vector<BigInteger> dist[1001];
	for (auto i = 1; i <= N; ++i)
	{
		dijkstra(i);
		dist[i] = distance;
	}

	BigInteger answer = 0;
	for (auto i = 2; i <= N; ++i)
	{
		if (answer < dist[i][X] + dist[X][i])
		{
			answer = dist[i][X] + dist[X][i];
		}
	}

	std::cout << answer << std::endl;

	return 0;
}
