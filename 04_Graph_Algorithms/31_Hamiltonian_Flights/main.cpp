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

int n, m, N;
vector<vector<int>> adj, dp;
const int MOD = 1e9 + 7;

void solve() {
    cin >> n >> m;
    N = 1 << n;
    adj.resize(n);
    dp.assign(N, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].emplace_back(v);
    }
    dp[1][0] = 1;
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int x = mask; x; x &= x - 1) {
            int u = __builtin_ctz(x);
            if (dp[mask][u] == 0) continue;
            for (auto &v : adj[u]) {
                if (mask & (1 << v)) continue;
                int nextMask = mask | (1 << v);
                dp[nextMask][v] += dp[mask][u];
                dp[nextMask][v] %= MOD;
            }
        }
    }
    cout << dp[(1 << n) - 1][n - 1] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}