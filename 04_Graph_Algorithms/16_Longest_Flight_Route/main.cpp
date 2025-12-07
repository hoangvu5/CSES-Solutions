#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cout<<#x<<" = "<<x<<'\n'
#define dbgv(x) for(int i=0;i<x.size();i++)cout<<x[i]<<' ';cout<<'\n'
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> indeg(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].emplace_back(b);
        indeg[b]++;
    }
    queue<int> qu;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) qu.push(i);
    }
    vector<int> topo;
    while (!qu.empty()) {
        int u = qu.front(); qu.pop();
        topo.push_back(u);
        for (auto &v : adj[u]) {
            if (--indeg[v] == 0) qu.push(v);
        }
    }
    // Longest path + DAG: Topological sort + DP
    // If has cycle, then it's NP-hard
    vector<int> dist(n + 1, INT_MIN);
    vector<int> par(n + 1, -1);
    dist[1] = 0;
    for (auto &u : topo) {
        if (dist[u] == INT_MIN) continue;
        for (auto &v : adj[u]) {
            if (dist[u] + 1 > dist[v]) {
                dist[v] = dist[u] + 1;
                par[v] = u;
            }
        }
    }
    if (dist[n] < 0) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    cout << dist[n] + 1 << '\n';
    vector<int> path;
    for (int cur = n; cur != -1; cur = par[cur]) {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end());
    for (auto &x : path) cout << x << ' ';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}