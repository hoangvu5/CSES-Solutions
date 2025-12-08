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

const int mod = 1e9 + 7;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<pii>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
    }
    // Dijkstra
    vector<ll> dist(n + 1, LLONG_MAX);
    vector<int> dp(n + 1, 0);
    vector<int> lo(n + 1, INT_MAX);
    vector<int> hi(n + 1, 0);
    multiset<pair<ll, int>> se;
    dp[1] = 1; lo[1] = hi[1] = 0;
    dist[1] = 0; se.insert({0, 1});
    while (!se.empty()) {
        auto [d, u] = *se.begin();
        se.erase(se.begin());
        if (d != dist[u]) continue;
        for (auto &[v, w] : adj[u]) {
            ll nd = d + w;
            if (nd < dist[v]) {
                dist[v] = nd;
                dp[v] = dp[u];
                lo[v] = lo[u] + 1;
                hi[v] = hi[u] + 1;
                se.insert({dist[v], v});
            } else if (nd == dist[v]) {
                dp[v] = (dp[v] + dp[u]) % mod;
                lo[v] = min(lo[v], lo[u] + 1);
                hi[v] = max(hi[v], hi[u] + 1);
            }
        }
    }
    cout << dist[n] << ' ' << dp[n] << ' ' << lo[n] << ' ' << hi[n];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}