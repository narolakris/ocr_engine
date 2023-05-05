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
    int n = 3;
    vector<vector<int>> source(n, vector<int>(n));
    vector<vector<int>> goal(n, vector<int>(n));

    for (auto &a : source) {
        for (auto &x : a)
            cin >> x;
    }

    for (auto &a : goal) {
        for (auto &x : a)
            cin >> x;
    }

    vector<vector<int>> terminate = {{ -1, -1, -1}, { -1, -1, -1}, { -1, -1, -1}};

    queue<vector<vector<int>>> q;
    q.push(source);

    set<vector<vector<int>>> vis;
    vis.insert(source);

    map<vector<vector<int>>, vector<vector<int>>> par;
    par[source] = terminate;

    vector<int> dir = {1, 0, -1, 0, 1};
    vector<vector<int>> lastState = terminate;

    while (!q.empty()) {
        auto curState = q.front();
        auto cur = curState;
        q.pop();

        if (curState == goal) {
            lastState = goal;
            break;
        }

        int x = -1, y = -1;
        for (int i = 0; i < n && x == -1; i++) {
            for (int j = 0; j < n; j++) {
                if (curState[i][j] == 0) {
                    x = i;
                    y = j;
                    break;
                }
            }
        }

        function<bool(int, int)> isValid = [&](int i, int j) {
            return (i >= 0 && j >= 0 && i < n && j < n);
        };

        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i];
            int ny = y + dir[i + 1];
            if (isValid(nx, ny)) {
                swap(curState[x][y], curState[nx][ny]);
                if (vis.find(curState) == vis.end()) {
                    vis.insert(curState);
                    par[curState] = cur;
                    q.push(curState);
                }
                swap(curState[x][y], curState[nx][ny]);
            }
        }
    }

    if (lastState == terminate) {
        cout << "Cannot" << endl;
        return;
    }

    auto print = [&](vector<vector<int>> a) {
        for (auto x : a) {
            for (auto y : x)
                cout << y << " ";
            cout << endl;
        }
        cout << endl;
    };

    vector<vector<vector<int>>> path;
    while (lastState != terminate) {
        path.push_back(lastState);
        lastState = par[lastState];
    }

    cout << endl << "Path will be as follows:" << endl << endl;
    reverse(all(path));
    for (auto p : path)
        print(p);
}

int main() {
    fast;
    ll t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}