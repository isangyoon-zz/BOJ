#include <iostream>
#include <vector>
#include <queue>
#include <functional>

typedef int Integer;
typedef unsigned long long BigInteger;
typedef std::pair<Integer, BigInteger> Node;
typedef std::vector<Node> Graph;

const int INF = 100000000;

int n, m;

Graph a[100001];
std::vector<BigInteger> distance;

void dijkstra(int start)
{
	distance.assign(n + 1, INF);
	std::vector<bool> visited(n + 1, false);

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
  
	std::cin >> n >> m;

	for (auto i = 1; i <= m; ++i)
	{
		int from, to;
		BigInteger cost;

		std::cin >> from >> to >> cost;

		a[from].push_back({ to, cost });
	}

	int start, end;
	std::cin >> start >> end;

	dijkstra(start);
	std::cout << distance[end] << std::endl;

	return 0;
}
