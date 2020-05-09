#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int N = 1e5;
vector<int> adj[N];
queue<int> q;
bool vis[N];
int dist[N];

void bfs(int u) {
	vis[u] = true;
	dist[u] = 0;
	q.push(u);
	while (!q.empty()) {
		u = q.front(); q.pop();	
		for (int v : adj[u]) {
			if (!vis[v]) {
				vis[v] = true;
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	adj[1].push_back(2);
	adj[1].push_back(4);
	adj[1].push_back(3);
	adj[3].push_back(1);
	adj[3].push_back(4);
	adj[4].push_back(3);
	adj[4].push_back(1);
	adj[4].push_back(2);
	adj[4].push_back(5);
	adj[2].push_back(1);
	adj[2].push_back(4);
	adj[2].push_back(5);
	adj[5].push_back(2);
	adj[5].push_back(4);
	
	bfs(1);
	for (int i = 1; i <= 5; i++) cout << "dist[" << i << "]: " << dist[i] << "\n";
}
