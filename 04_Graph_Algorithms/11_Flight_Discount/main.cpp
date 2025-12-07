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

void dijkstra(vector<vector<pii>> &adj, vector<ll> &dist, int start) {
    set<pair<ll, int>> se;
    dist[start] = 0; se.insert({0, start});
    while (!se.empty()) {
        auto [d, v] = *se.begin();
        se.erase(se.begin());
        for (auto &[u, w] : adj[v]) {
            if (dist[v] + w < dist[u]) {
                se.erase({dist[u], u});
                dist[u] = dist[v] + w;
                se.insert({dist[u], u});
            }
        }
    }
}

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<pii>> adj(n + 1), inv(n + 1);
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
        inv[b].emplace_back(a, c);
        edges.push_back({a, b, c});
    }
    vector<ll> disa(n + 1, LLONG_MAX);
    vector<ll> disi(n + 1, LLONG_MAX);
    dijkstra(adj, disa, 1);
    dijkstra(inv, disi, n);
    ll ans = LLONG_MAX;
    for (auto &edge : edges) {
        int u = edge[0], v = edge[1];
        ll w = edge[2];
        if (disa[u] == LLONG_MAX || disi[v] == LONG_MAX) continue;
        ans = min(ans, disa[u] + disi[v] + w / 2);
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}