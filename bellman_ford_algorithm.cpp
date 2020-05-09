#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int INF = INT_MAX;
const int N = 1e5;

vector<tuple<int, int, int>> edges;
int dist[N];
int predecessor[N];

void bellman_ford_algorithm(int u, int n) {
	for (int i = 1; i <= n; i++) dist[i] = INF;
	dist[u] = 0;
	predecessor[u] = -1;
	for (int i = 1; i <= n - 1; i++) {
		for (auto e : edges) {
			int a, b, w;
			tie(a, b, w) = e;
			if (dist[a] + w < dist[b]) predecessor[b] = a;
			dist[b] = min(dist[b], dist[a] + w);
		}
	}
	for (auto e : edges) {
		int a, b, w;
		tie(a, b, w) = e;
		if (dist[a] + w < dist[b]) {
			cout << "Error: graph contains negative-weight cycle." << "\n";
		}
	}
}

void reconstruct(int target) {
	int current = target;
	vector<int> path;
	while (current != -1) {
		path.insert(path.begin(), current);
		current = predecessor[current];
	}
	string ans;
	for (int x : path) {
		ans += to_string(x) + " -> ";
	}
	for (int i = 1; i <= 4; i++) ans.pop_back();
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	edges.push_back({1, 2, 5});
	edges.push_back({1, 3, 3});
	edges.push_back({1, 4, 7});
	edges.push_back({3, 4, 1});
	edges.push_back({4, 5, 2});
	edges.push_back({2, 5, 2});

	bellman_ford_algorithm(1, 6);
	reconstruct(5);
}
