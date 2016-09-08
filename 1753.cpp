#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

const int INFINITE = 1 << 30;

int V, E;
std::vector<std::pair<int, int> > adj[200001];

std::vector<int> dijkstra(int start)
{
	std::vector<bool> visited(V + 1, false);
	std::vector<int> distance(V + 1, INFINITE);

	auto compare = [](std::pair<int, int> const& lhs, std::pair<int, int> const& rhs) { return lhs.second > rhs.second; };
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, decltype(compare)> heap(compare);

	heap.push(std::make_pair(start, distance[start] = 0));

	while (!heap.empty())
	{
		std::pair<int, int> current = heap.top();
		heap.pop();

		int cv = current.first;
		int cw = current.second;

		if (visited[cv]) continue;
		visited[cv] = true;

		for (auto i = 0; i < adj[cv].size(); ++i)
		{
			if (!visited[adj[cv][i].first] && distance[adj[cv][i].first] > adj[cv][i].second + cw)
			{
				heap.push(std::make_pair(adj[cv][i].first, (distance[adj[cv][i].first] = adj[cv][i].second + cw)));
			}
		}
	}

	return distance;
}

int main(int argc, char** argv)
{
    scanf("%d %d", &V, &E);

	int start;
    scanf("%d", &start);

	while(E--)
	{
		int from, to;
		int cost;

        scanf("%d %d %d", &from, &to, &cost);

		adj[from].push_back(std::make_pair(to, cost));
	}

	auto distance = dijkstra(start);

	for (auto i = 1; i <= V; ++i)
	{
		if (distance[i] == INFINITE) printf("INF\n");
		else printf("%d\n", distance[i]);
	}

	return 0;
}
