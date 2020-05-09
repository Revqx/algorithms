#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int N = 1e5;
const int INF = INT_MAX;
vector<pair<int, int>> adj[N];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
bool vis[N];
int predecessor[N];
int dist[N];

void dijkstras_algorithm(int u, int n) {
	for (int i = 1; i <= n; i++) dist[i] = INF;
	dist[u] = 0;
	predecessor[u] = -1;
	q.push({0, u});
	while (!q.empty()) {
		int u = q.top().second; q.pop();
		if (!vis[u]) {
			vis[u] = true;
			for (auto v : adj[u]) {
				int b = v.first, w = v.second;
				if (dist[u] + w < dist[b]) {
					dist[b] = dist[u] + w;
					predecessor[b] = u;
					q.push({dist[b], b});
				}
			}
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
	
	adj[1].push_back({2, 5});
	adj[1].push_back({3, 3});
	adj[1].push_back({4, 7});
	adj[3].push_back({4, 1});
	adj[3].push_back({1, 3});
	adj[2].push_back({1, 5});
	adj[2].push_back({4, 3});
	adj[2].push_back({5, 2});
	adj[4].push_back({3, 1});
	adj[4].push_back({1, 7});
	adj[4].push_back({2, 3});
	adj[4].push_back({5, 2});
	adj[5].push_back({2, 2});
	adj[5].push_back({4, 2});
	
	dijkstras_algorithm(1, 5);
	reconstruct(5);
}
