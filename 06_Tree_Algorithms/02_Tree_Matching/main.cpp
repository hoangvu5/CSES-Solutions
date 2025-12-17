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

    vector<array<int, 2>> dp(n + 1, {0, 0});
    function<void(int, int)> dfs = [&](int u, int p) -> void {
        int cand = 0;
        for (auto &v : adj[u]) {
            if (v == p) continue;
            dfs(v, u);
            dp[u][0] += max(dp[v][0], dp[v][1]);
            cand = max(cand, -max(dp[v][0], dp[v][1]) + dp[v][0] + 1);
        }
        dp[u][1] = dp[u][0] + cand; 
    };
    dfs(1, 0);
    cout << max(dp[1][1], dp[1][0]) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}