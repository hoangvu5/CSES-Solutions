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
    vector<vector<pii>> adj(n + 1);
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
        edges.push_back({a, b, c});
    }
    // Normally, would look for negative cycle reachable from starting vertex 1
    // By changing dist all to 0, can look for any negative cycle
    vector<ll> dist(n + 1, 0);
    vector<int> par(n + 1, -1);
    int x = -1;
    for (int i = 0; i < n; i++) {
        x = -1;
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1];
            ll w = edge[2];
            if (dist[u] != LLONG_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                par[v] = u;
                x = v;
            }
        }
    }
    if (x == -1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) x = par[x];
    
    vector<int> cycle;
    for (int v = x;; v = par[v]) {
        cycle.push_back(v);
        if (v == x && cycle.size() > 1) break;
    }
    reverse(cycle.begin(), cycle.end());
    for (auto &v : cycle) cout << v << ' ';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}