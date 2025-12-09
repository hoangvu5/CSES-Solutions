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

vector<vector<int>> adj, inv;
vector<bool> vis;
vector<int> topo, kd;
int k;

void dfsa(int v) {
    vis[v] = true;
    for (auto &u : adj[v]) {
        if (!vis[u]) dfsa(u);
    }
    topo.push_back(v);
}

void dfsi(int v) {
    kd[v] = k;
    for (auto &u : inv[v]) {
        if (kd[u] == -1) dfsi(u);
    }
}

void solve() {
    int n, m; cin >> n >> m;
    adj.resize(n + 1);
    inv.resize(n + 1);
    vis.assign(n + 1, false);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].emplace_back(b);
        inv[b].emplace_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfsa(i);
    }
    reverse(topo.begin(), topo.end());
    kd.assign(n + 1, -1);
    k = 0;
    for (auto &v : topo) {
        if (kd[v] == -1) {
            k++; dfsi(v);
        }
    }
    cout << k << '\n';
    for (int i = 1; i <= n; i++) cout << kd[i] << ' ';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}