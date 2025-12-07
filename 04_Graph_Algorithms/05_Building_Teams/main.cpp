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
    vector<int> vis(n + 1, 0);
    function<bool(int, int)> dfs = [&](const int &cur, const int &col) -> bool {
        vis[cur] = col;
        for (auto &chi : adj[cur]) {
            if ((vis[chi] == 0 && !dfs(chi, 3 - col)) || vis[chi] == col) return false;
        }
        return true;
    };
    for (int i = 1; i <= n; i++) {
        if (vis[i] != 0) continue;
        if (!dfs(i, 1)) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << vis[i] << ' ';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}