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

void dfs(int u, int p, vector<int>& depth, vector<vector<int>>& adj, vector<int> &par) {
    par[u] = p;
    for (int v: adj[u]) {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u, depth, adj, par);
    }
}

void solve() {
    int n, q; cin >> n >> q;
    vector<int> par(n + 1, 0);
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> depth(n + 1, 0);
    dfs(1, 0, depth, adj, par);
    vector<vector<int>> tbl = treeJump(par);
    while (q--) {
        int u, v; cin >> u >> v;
        int l = lca(tbl, depth, u, v);
        cout << depth[u] + depth[v] - 2 * depth[l] << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}