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

int n;
vector<vector<int>> adj;
vector<ll> num, ans;

void dfs(int u, int p, int d) {
    ans[0] += d;
    num[u] = 1;
    for (auto &v : adj[u]) {
        if (v == p) continue;
        dfs(v, u, d + 1);
        num[u] += num[v];
    }
}

void dfs1(int u, int p) {
    for (auto &v : adj[u]) {
        if (v == p) continue;
        ans[v] = ans[u] + n - 2 * num[v];
        dfs1(v, u);
    }
}

void solve() {
    cin >> n;
    adj.resize(n);
    num.assign(n, 0);
    ans.assign(n, 0);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, -1, 0);
    dfs1(0, -1);
    for (int i = 0; i < n; i++) cout << ans[i] << ' ';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}