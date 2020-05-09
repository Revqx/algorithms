#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int N = 1e5;
vector<int> adj[N];
bool vis[N];
int edges = 0;

void dfs(int u) {
	if (!vis[u]) {
		vis[u] = true;
		edges += adj[u].size();
		for (auto v : adj[u]) {
			dfs(v);
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
	adj[4].push_back(6);
	adj[2].push_back(1);
	adj[2].push_back(4);
	adj[2].push_back(6);
	adj[6].push_back(2);
	adj[6].push_back(4);

	dfs(1);
	
	edges /= 2;
	cout << edges << "\n";
}
