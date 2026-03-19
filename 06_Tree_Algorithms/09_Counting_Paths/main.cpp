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

vector<vi> treeJump(vi& P){
    int on = 1, d = 1;
    while(on < sz(P)) on *= 2, d++;
    vector<vi> jmp(d, P);
    rep(i,1,d) rep(j,0,sz(P))
        jmp[i][j] = jmp[i-1][jmp[i-1][j]];
    return jmp;
}

int jmp(vector<vi>& tbl, int nod, int steps){
    rep(i,0,sz(tbl))
        if(steps&(1<<i)) nod = tbl[i][nod];
    return nod;
}

int lca(vector<vi>& tbl, vi& depth, int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    a = jmp(tbl, a, depth[a] - depth[b]);
    if (a == b) return a;
    for (int i = sz(tbl); i--;) {
        int c = tbl[i][a], d = tbl[i][b];
        if (c != d) a = c, b = d;
    }
    return tbl[0][a];
}

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> depth(n + 1, 0), par(n + 1, 0);
    auto dfs = [&](auto&& self, int u, int p) -> void {
        par[u] = p;
        for (int v: adj[u]) {
            if (v == p) continue;
            depth[v] = depth[u] + 1;
            self(self, v, u);
        }
    };
    dfs(dfs, 1, 0);

    vector<vector<int>> tbl = treeJump(par);
    vector<ll> pref(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        pref[a]++;
        pref[b]++;
        int l = lca(tbl, depth, a, b);
        int p = par[l];
        if (l >= 0) pref[l]--;
        if (p >= 0) pref[p]--;
    }

    auto efs = [&](auto&& self, int u, int p) -> void {
        for (int v: adj[u]) {
            if (v == p) continue;
            self(self, v, u);
            pref[u] += pref[v];
        }
    };
    efs(efs, 1, 0);
    for (int i = 1; i <= n; i++) {
        cout << pref[i] << ' ';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}