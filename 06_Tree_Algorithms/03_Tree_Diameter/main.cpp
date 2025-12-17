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
    int n; cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int x = -1, h = 0;
    function<void(int, int, int)> dfs = [&](int u, int p, int l) -> void {
        if (l > h) { x = u; h = l; }
        for (auto &v : adj[u]) {
            if (v == p) continue;
            dfs(v, u, l + 1);
        }
    };
    dfs(1, 0, 0);
    dfs(x, 0, 0);
    cout << h << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}