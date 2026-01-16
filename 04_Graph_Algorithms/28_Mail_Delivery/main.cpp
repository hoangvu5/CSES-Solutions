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

int n, m, si, big;
vector<bool> vis;
vector<unordered_set<int>> adj;
vector<int> deg, path, circuit;

void dfs(int u) {
    vis[u] = true; si++;
    for (auto &v : adj[u]) {
        if (!vis[v]) dfs(v);
    }
}

void solve() {
    // All vertices have even degrees
    // Graph is connected excluding isolated vertices
    cin >> n >> m;
    adj.resize(n + 1);
    deg.assign(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
        deg[u]++; deg[v]++;
    }
    for (int i = 1; i <= n; i++) {
        if (deg[i] % 2 == 1) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }

    vis.assign(n + 1, false);
    dfs(1);
    for (int i = 2; i <= n; i++) {
        if (vis[i]) continue;
        si = 0; dfs(i);
        if (si > 1) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }

    // Print an Euler circuit
    path.clear(); path.push_back(1);
    circuit.clear();
    while (path.size() > 0) {
        int u = path.back();
        if (adj[u].size() > 0) {
            int v = *adj[u].begin();
            adj[u].erase(v);
            adj[v].erase(u);
            path.push_back(v);
        } else {
            circuit.push_back(path.back());
            path.pop_back();
        }
    }
    reverse(circuit.begin(), circuit.end());
    for (auto &u : circuit) {
        cout << u << ' ';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}