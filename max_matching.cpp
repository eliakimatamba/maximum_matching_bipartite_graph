
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <climits>
#include <algorithm>
using namespace std;
 
int bfs(vector<vector<int> > &residual, int s, int t, vector<int> &path) {
    queue<int> q;
    q.push(s);
    vector<int> visited(residual.size(), 0);
    visited[s] = 1;
    path[s] = -1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == t) break;
        for (int v=0; v<residual.size(); v++) {
            if (visited[v]==0 && residual[u][v] > 0) {
                q.push(v);
                path[v] = u;
                visited[v] = 1;
            }
        }
    }
    if (visited[t] == 0) return 0;
    return 1;
}
 
void max_flow(vector<vector<int> > &residual, int s, int t) {
    vector<int> path(residual.size());
    int f = 0;
    while (bfs(residual, s, t, path)) {
        int flow = INT_MAX;
        for (int u=t; u!=s; u=path[u]) {
            int v = path[u];
            flow = min(flow, residual[v][u]);
        }
        for (int u=t; u!=s; u=path[u]) {
            int v = path[u];
            residual[v][u] -= flow;
            residual[u][v] += flow;
        }
        f += flow;
    }
    cout << f << " ";
}
 
void perfect_match(vector<vector<int> > &residual, int s, int t) {
    vector<int> visited(residual.size(), 0);
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v=0; v<residual.size(); v++) {
            if (visited[v] == 0 && residual[u][v] > 0) {
                visited[v] = 1;
                q.push(v);
            }
        }
    }
    for (int i=0; i<residual.size(); i++) {
        if (visited[i] == 1) continue;
        for (int j=0; j<residual.size(); j++) {
            if (residual[i][j] > 0 && visited[j] == 0) {
                visited[j] = 1;
                break;
            }
        }
    }
    int cnt = 0;
    for (int i=0; i<residual.size(); i++) {
        if (visited[i] == 1) cnt++;
    }
    if (cnt == residual.size()) cout << "Y";
    else cout << "N";
}
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n, q;
        cin >> m >> n >> q;
        int nn = m+n+2;
        vector<vector<int> > residual(nn, vector<int>(nn, 0));
        int s = m+n, t = m+n+1;
        for (int i=0; i<m; i++) {
            residual[s][i] = 1;
        }
        for (int i=m; i<m+n; i++) {
            residual[i][t] = 1;
        }
        map<pair<int, int>, int> edges;
        while (q--) {
            int u, v;
            cin >> u >> v;
            if (edges.find(make_pair(u, v)) != edges.end()) {
                continue;
            }
            edges[make_pair(u, v)] = 1;
            residual[u-1][v+m-1] = 1;
        }
        max_flow(residual, s, t);
        perfect_match(residual, s, t);
        cout << endl;
    }
    return 0;
}
