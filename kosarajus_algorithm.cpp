#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN = 1e5;
vector<int> adj[mxN];
vector<int> radj[mxN];

bool vis1[mxN];
bool vis2[mxN];

stack<int> st;

int component[mxN], deg[mxN];

void dfs1(int u) {
	vis1[u] = true;
	for (int v : adj[u]) {
		if (!vis1[v])	
			dfs1(v);
	}
	st.push(u);
}

void dfs2(int u, int rep) {
	vis2[u] = true;
	component[u] = rep;
	for (int v : radj[u]) {
		if (!vis2[v])
			dfs2(v, rep);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	vector<string> airports = {
		"BGI", "CDG", "DEL", "DOH", "DSM", "EWR", "EYW", "HND", "ICN", "JFK", "LGA", "LHR", "ORD", "SAN", "SFO", "SIN", "TLV", "BUD"
	};

	vector<vector<string>> routes = {
		{"DSM", "ORD"},
		{"ORD", "BGI"},
		{"BGI", "LGA"},
		{"SIN", "CDG"},
		{"CDG", "SIN"},
		{"CDG", "BUD"},
		{"DEL", "DOH"},
		{"DEL", "CDG"},
		{"TLV", "DEL"},
		{"EWR", "HND"},
		{"HND", "ICN"},
		{"HND", "JFK"},
		{"ICN", "JFK"},
		{"JFK", "LGA"},
		{"EYW", "LHR"},
		{"LHR", "SFO"},
		{"SFO", "SAN"},
		{"SFO", "DSM"},
		{"SAN", "EYM"}
	};
	
	string startingAirport = "LGA";

	int n = airports.size();
	map<string, int> mp;

	for (int i = 0; i < n; i++) {
		mp[airports[i]] = i;
	}
	
	for (vector<string> connection : routes) {
		adj[mp[connection[0]]].push_back(mp[connection[1]]);
	}	
	
	for (int i = 0; i < n; i++) {
		for (int j : adj[i]) {
			radj[j].push_back(i);
		}
	}

	for (int i = 0; i < n; i++) {
		if (!vis1[i]) {
			dfs1(i);
		}
	}
	
	while (st.size() > 0) {
		int u = st.top();
		st.pop();

		if (!vis2[u])
			dfs2(u, u);
	}

	for (int i = 0; i < n; i++) {
		for (int j : adj[i]) {
			if (component[i] != component[j])	
				deg[component[j]]++;
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (component[i] == i && deg[i] == 0 && i != component[mp[startingAirport]])
			ans++;
	}

	cout << ans << "\n";
}
