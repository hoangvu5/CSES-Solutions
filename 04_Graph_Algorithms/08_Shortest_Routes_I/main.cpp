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
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
    }
    vector<ll> dist(n + 1, LLONG_MAX);
    set<pair<ll, int>> se;
    dist[1] = 0; se.insert({0, 1});
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
    for (int i = 1; i <= n; i++) cout << dist[i] << ' ';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}