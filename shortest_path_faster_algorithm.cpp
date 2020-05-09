#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int N = 1e5;
const int INF = INT_MAX;

vector<pair<int, int>> adj[N];
deque<int> q;
int dist[N];
int predecessor[N];
bool inqueue[N];

void shortest_path_faster_algorithm(int u, int n) {
	for (int i = 1; i <= n; i++) dist[i] = INF;
	dist[u] = 0;
	q.push_back(u);
	inqueue[u] = true;
	predecessor[u] = -1;

	while (!q.empty()) {
		u = q.front(); q.pop_front();
		inqueue[u] = false;

		for (auto e : adj[u]) {
			int a = u;
			int b = e.first;
			int w = e.second;

			if (dist[a] + w < dist[b]) {
				dist[b] = dist[a] + w;
				predecessor[b] = a;

				if (!inqueue[b]) {	
					q.push_back(b);
					inqueue[b] = true;
					if (q.back() < q.front()) {
						int x = q.back(); q.pop_back();
						q.push_front(x);
					}
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
	
	shortest_path_faster_algorithm(1, 5);
	reconstruct(5);
}
