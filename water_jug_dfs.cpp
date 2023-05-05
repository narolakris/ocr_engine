/*
dfs for water jug
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
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

void dfs(pair<int, int> cur, pair<int, int> terminate, set<pair<int, int>>& vis, map<pair<int, int>, pair<int, int>>& par, int a, int b, int d) {
    if (cur == terminate) {
        return;
    }

    int x = cur.fi;
    int y = cur.se;

    if (x + y == d) {
        terminate = cur;
        return;
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
            dfs(state, terminate, vis, par, a, b, d);
        }
    }
}

void solve() {
    int a, b, d;
    cin >> a >> b >> d;

    pair<int, int> terminate = { -1, -1};
    map<pair<int, int>, pair<int, int>> par;
    par[ {0, 0}] = terminate;

    pair<int, int> lastState = terminate;

    set<pair<int, int>> vis;
    vis.insert({0, 0});

    dfs({0, 0}, terminate, vis, par, a, b, d);

    if (lastState == terminate) {
        cout << "Not possible" << endl;
        return;
    }

    vector<pair<int, int>> ans;

    while (lastState != terminate) {
        ans.pb(lastState);
        lastState = par[lastState];
    }

    reverse(all(ans));

    for (auto state : ans) {
        cout << state.fi << " " << state.se << endl;
    }
}

int main() {
    fast;

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }
}