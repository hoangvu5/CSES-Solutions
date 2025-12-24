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

void solve() {
    int n, q; cin >> n >> q;
    vector<int> g(n + 1);
    g[1] = 0;
    for (int i = 2; i <= n; i++) {
        int p; cin >> p;
        g[i] = p;
    }

    vector<vector<int>> tbl = treeJump(g);
    while (q--) {
        int x, k; cin >> x >> k;
        int ans = jmp(tbl, x, k);
        cout << (ans ? ans : -1) << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}