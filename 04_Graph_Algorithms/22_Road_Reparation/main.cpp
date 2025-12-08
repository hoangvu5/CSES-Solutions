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
        adj[b].emplace_back(a, c);
    }
    ll ans = 0;
    vector<bool> vis(n + 1, false);
    vector<pii> min_e(n + 1, {INT_MAX, -1});
    set<pii> se;
    min_e[1] = {0, -1}; se.insert({0, 1});
    for (int i = 0; i < n; i++) {
        if (se.empty()) {
            cout << "IMPOSSIBLE\n";
            return;
        }
        auto [w, v] = *se.begin();
        se.erase(se.begin());
        vis[v] = true;
        ans += w;
        for (auto &[u, we] : adj[v]) {
            if (!vis[u] && we < min_e[u].first) {
                se.erase({min_e[u].first, u});
                min_e[u] = {we, v};
                se.insert({min_e[u].first, u});
            }
        }
    }
    cout << ans << '\n';
    // for (int i = 2; i <= n; i++) {
    //     cout << i << ' ' << min_e[i].second << '\n';
    // }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}