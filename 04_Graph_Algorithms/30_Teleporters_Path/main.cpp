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

int n, m, si, start;
vector<bool> vis, used;
vector<vector<pair<int, int>>> adj;
vector<int> in, out, circuit, iter;
stack<int> path;

void dfs(int u) {
    vis[u] = true; si++;
    for (auto &[v, i] : adj[u]) {
        if (!vis[v]) dfs(v);
    }
}

void solve() {
    // Only vertex 1 and n with odd degree
    // Graph is connected excluding isolated vertices
    cin >> n >> m;
    adj.resize(n + 1);
    in.assign(n + 1, 0);
    out.assign(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back({v, i});
        out[u]++; in[v]++;
    }
    
    if (out[1] != in[1] + 1 || in[n] != out[n] + 1) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    for (int i = 2; i < n; i++) {
        if (in[i] != out[i]) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    
    start = 1;
    vis.assign(n + 1, false);
    dfs(1); if (!vis[n]) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    for (int i = 2; i < n; i++) {
        if (vis[i]) continue;
        si = 0; dfs(i);
        if (si > 1) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    
    // Print an Euler path
    path.push(1);
    circuit.clear();
    iter.assign(n + 1, 0);
    used.assign(m, false);
    while (!path.empty()) {
        int u = path.top();
        while (iter[u] < adj[u].size() && used[adj[u][iter[u]].second]) iter[u]++;
        if (iter[u] < adj[u].size()) {
            auto [v, i] = adj[u][iter[u]];
            used[i] = true;
            path.push(v);
        } else {
            circuit.push_back(u);
            path.pop();
        }
    }
    if (circuit.size() != m + 1) {
        cout << "IMPOSSIBLE\n";
        return;
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