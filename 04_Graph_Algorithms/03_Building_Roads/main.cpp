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
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> vis(n + 1, 0);
    function<void(int)> dfs = [&](const int &cur) {
        vis[cur] = true;
        for (auto &chi : adj[cur]) {
            if (vis[chi]) continue;
            dfs(chi);
        }
    };
    vector<int> cc; // Store one node each CC
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        cc.push_back(i); dfs(i);
    }
    cout << cc.size() - 1 << '\n';
    for (int i = 1; i < cc.size(); i++) {
        cout << cc[i - 1] << ' ' << cc[i] << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}