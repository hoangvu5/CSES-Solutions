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

void dfs(int v, vector<vector<int>>& adj, vector<bool> &vis) {
    vis[v] = true;
    for (auto &u : adj[v]) {
        if (vis[u]) continue;
        dfs(u, adj, vis);
    }
}

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<vector<int>> inv(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].emplace_back(b);
        inv[b].emplace_back(a);
    }

    vector<bool> via(n + 1, false), vii(n + 1, false);
    dfs(1, adj, via);
    dfs(1, inv, vii);
    for (int i = 2; i <= n; i++) {
        if (!via[i]) {
            cout << "NO\n" << 1 << ' ' << i << '\n';
            return;
        }
        if (!vii[i]) {
            cout << "NO\n" << i << ' ' << 1 << '\n';
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}