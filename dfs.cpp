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
    int minPath = INT_MAX;
    vector<int> vis(n + 1, 0);
    vector<int> curPath;

    function<void(int)> dfs = [&](int cur) {
        vis[cur] = 1;
        curPath.push_back(cur);

        if (cur == goal) {
            int curLen = (int) curPath.size();

            // if (curLen == minPath) {
            //     paths.push_back(curPath);
            // }

            // if (curLen < minPath) {
            //     paths.clear();
            //     paths.push_back(curPath);
            //     minPath = curLen;
            // }

            paths.push_back(curPath);

            vis[cur] = 0;
            curPath.pop_back();
            return;
        }

        for (auto ngb : adj[cur]) {
            if (!vis[ngb]) dfs(ngb);
        }

        vis[cur] = 0;
        curPath.pop_back();
    };

    dfs(source);

    cout << "All paths:" << endl;
    for (auto path : paths) {
        minPath = min(minPath, sz(path));
        for (auto x : path)
            cout << x << " ";
        cout << endl;
    }

    cout << endl << "Minimum paths:" << endl;
    for (auto path : paths) {
        if (sz(path) == minPath) {
            for (auto x : path)
                cout << x << " ";
            cout << endl;
        }
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

/*

input:
4 5
1 2
1 3
2 3
2 4
3 4
1 4


*/