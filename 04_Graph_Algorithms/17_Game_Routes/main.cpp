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
    vector<vector<int>> adj(n + 1);
    vector<int> indeg(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].emplace_back(b);
        indeg[b]++;
    }
    queue<int> qu;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) qu.push(i);
    }
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    while (!qu.empty()) {
        int u = qu.front(); qu.pop();
        for (auto &v : adj[u]) {
            dp[v] = (dp[v] + dp[u]) % mod;
            if (--indeg[v] == 0) qu.push(v);
        }
    }
    cout << dp[n] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}