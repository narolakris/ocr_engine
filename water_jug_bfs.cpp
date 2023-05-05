// Author: Harsh Bardolia

#include<bits/stdc++.h>
using namespace std;

typedef long long   ll;
#define endl        "\n"
#define fi          first
#define se          second
#define pb          push_back
#define INF         1e18
#define MOD         1000000007
#define sz(x)       ((int)(x).size())
#define all(x)      (x).begin(), (x).end()
#define fast ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

void solve() {
	int a, b, d;
	cin >> a >> b >> d;

	queue<pair<int, int>> q;
	q.push({0, 0});

	set<pair<int, int>> vis;
	vis.insert({0, 0});

	pair<int, int> terminate = { -1, -1};
	map<pair<int, int>, pair<int, int>> par;
	par[ {0, 0}] = terminate;

	pair<int, int> lastState = terminate;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		int x = cur.fi;
		int y = cur.se;

		if (x + y == d) {
			lastState = cur;
			break;
		}

		set<pair<int, int>> newStates;

		newStates.insert({0, y});
		newStates.insert({x, 0});
		newStates.insert({a, y});
		newStates.insert({x, b});
		newStates.insert({min(a, x + y), max(0, x + y - a)});
		newStates.insert({max(0, x + y - b), min(b, x + y)});

		for (auto state : newStates) {
			if (vis.find(state) == vis.end()) {
				vis.insert(state);
				par[state] = cur;
				q.push(state);
			}
		}
	}

	if (lastState == terminate) {
		cout << "cannot do";
		return;
	}

	vector<pair<int, int>> path;
	while (lastState != terminate) {
		path.push_back(lastState);
		lastState = par[lastState];
	}

	reverse(all(path));
	for (auto state : path)
		cout << state.fi << " " << state.se << endl;
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