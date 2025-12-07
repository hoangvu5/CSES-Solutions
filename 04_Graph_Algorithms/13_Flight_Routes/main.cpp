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
    int n, m, k; cin >> n >> m >> k;
    vector<vector<pii>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
    }

    vector<multiset<ll>> dist(n + 1);
    multiset<pair<ll, int>> se;
    dist[1].insert(0);
    se.insert({0, 1});
    while (!se.empty()) {
        auto [d, u] = *se.begin();
        se.erase(se.begin());
        for (auto &[v, w] : adj[u]) {
            ll nd = d + w;
            if (dist[v].size() == k && nd >= *dist[v].rbegin()) continue;
            dist[v].insert(nd);
            if (dist[v].size() > k) {
                se.erase(se.find({*(--dist[v].end()), v}));
                dist[v].erase(--dist[v].end());
            }
            se.insert({nd, v});
        }
    }
    for (auto &x : dist[n]) cout << x << ' ';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}