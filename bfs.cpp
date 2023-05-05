// Author: Harsh Bardolia

#include<bits/stdc++.h>
using namespace std;

typedef long long   ll;
#define endl        "\n"
#define sz(x)       ((int)(x).size())
#define fast ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

void solve() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int source, goal;
	cin >> source >> goal;

	vector<vector<int>> paths;
	vector<int> p;
	p.push_back(source);
	queue<pair<int, vector<int>>> q;
	q.push({source, p});

	while (!q.empty()) {
		auto p = q.front();
		q.pop();

		int cur = p.first;
		auto path = p.second;

		set<int> s;
		for (auto x : path)
			s.insert(x);

		if (sz(s) != sz(path)) continue;

		if (cur == goal) {
			paths.push_back(path);
		}

		for (auto ngb : adj[cur]) {
			path.push_back(ngb);
			q.push({ngb, path});
			path.pop_back();
		}
	}

	cout << "All paths:" << endl;
	for (auto path : paths) {
		for (auto x : path)
			cout << x << " ";
		cout << endl;
	}
}

int main() {
#ifdef Harsh
	freopen("Error.txt", "w", stderr);
#endif
	fast;
	ll t = 1;
	// cin >> t;
	while (t--)
		solve();
	return 0;
}