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

void dfs(int cur, vector<vector<int>> &adj, vector<bool> &vis) {
    vis[cur] = true;
    for (auto &chi : adj[cur]) {
        if (!vis[chi]) dfs(chi, adj, vis);
    }
}

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> edges;
    vector<vector<int>> adj(n + 1), inv(n + 1);
    vector<bool> via(n + 1, 0), vii(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int a, b, x; cin >> a >> b >> x;
        edges.push_back({a, b, x});
        adj[a].push_back(b);
        inv[b].push_back(a);
    }
    dfs(1, adj, via);
    dfs(n, inv, vii);
    // If a positive cycle connecting both 1 and n, report -1
    // else, report maximum path
    vector<ll> dist(n + 1, LLONG_MIN);
    dist[1] = 0;
    for (int i = 0; i < n; i++) {
        for (vector<int> &edge : edges) {
            int u = edge[0], v = edge[1];
            ll w = edge[2];
            if (dist[u] != LLONG_MIN && dist[u] + w > dist[v]) {
                if (i == n - 1 && via[v] && vii[v]) {
                    cout << -1 << '\n';
                    return;
                }
                dist[v] = dist[u] + w;
            }
        }
    }
    cout << dist[n] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}