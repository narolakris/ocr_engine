#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fi first
#define se second

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> edges(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }

    function<void(int)> aStar = [&] (int source) {

        set<pair<int, int>> s;
        vector<int> visited(n), distance(n, INT_MAX), parent(n);

        function<void(int, int)> path = [&] (int n, int source) {
            if (parent[n] == -1) {
                cout << source << " ";
                return;
            }

            path(parent[n], source);
            cout << n << " ";
        };

        s.insert({0, source});
        distance[source] = 0;
        parent[source] = -1;

        while (!s.empty()) {
            auto curr = *s.begin();
            s.erase(curr);

            int vertex = curr.se;
            int cur_dis = curr.fi;

            if (visited[vertex] == 1)
                continue;

            visited[vertex] = 1;
            distance[vertex] = cur_dis;

            for (auto ver : edges[vertex]) {
                auto v = ver.fi;
                auto w = ver.se;

                if (visited[v] == 0) {
                    if (distance[vertex] + w < distance[v]) {
                        parent[v] = vertex;
                        distance[v] = distance[vertex] + w;
                    }
                    s.insert({cur_dis + w, v});
                }
            }
        }

        cout << "Vertex\t\tDistance\tPath" << endl;
        for (int i = 0; i < n; i++) {
            cout << i << "\t\t\t" << distance[i] << "\t\t\t";
            path(i, source);
            cout << endl;
        }
    };
    
    // Finding shortest path
    aStar(0);
}

/*

Input:
9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7


*/