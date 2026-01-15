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

vector<vector<int>> adj, inv, graph;
vector<bool> vis;
vector<int> topo, idx, coins, comp;
vector<ll> dp, tot;
ll ans;
int k; ll cur;

void dfsa(int v) {
    vis[v] = true;
    for (auto &u : adj[v]) {
        if (!vis[u]) dfsa(u);
    }
    topo.push_back(v);
}

void dfsi(int v) {
    idx[v] = k; cur += coins[v];
    for (auto &u : inv[v]) {
        if (idx[u] == -1) dfsi(u);
    }
}

void dfsu(int u) {
    vis[u] = true;
    dp[u] = tot[u];
    for (int v : graph[u]) {
        if (!vis[v]) dfsu(v);
        dp[u] = max(dp[u], dp[v] + tot[u]);
    }
}

void solve() {
    int n, m; cin >> n >> m;
    adj.resize(n + 1);
    inv.resize(n + 1);
    coins.resize(n + 1);
    vis.assign(n + 1, false);
    for (int i = 1; i <= n; i++) {
        cin >> coins[i];
    }
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].emplace_back(b);
        inv[b].emplace_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfsa(i);
    }
    reverse(topo.begin(), topo.end());
    idx.assign(n + 1, -1);
    k = 0;
    
    for (auto &v : topo) {
        if (idx[v] == -1) {
            cur = 0;
            comp.push_back(v); dfsi(v);
            tot.push_back(cur);
            k++;
        }
    }
    // idx: node index to SCC index
    // tot: SCC index to number of coins
    // graph: adjacency list where each node is a SCC
    graph.resize(k);
    for (int u = 1; u <= n; u++) {
        for (int v : adj[u]) {
            if (idx[u] != idx[v]) {
                graph[idx[u]].push_back(idx[v]);
            }
        }
    }
    
    vis.assign(k, 0);
    dp.assign(n + 1, 0);
    for (int i = 0; i < k; i++) {
        if (!vis[i]) dfsu(i);
    }

    ans = 0;
    for (int i = 0; i < k; i++) ans = max(ans, dp[i]);
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}