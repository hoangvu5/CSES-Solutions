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

vector<vector<int>> adj;
vector<int> par, ans;

struct UF {
    vi e;
    UF(int n) : e(n, -1) {}
    bool sameSet(int a, int b) { return find(a) == find(b); }
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b]; e[b] = a;
        return true;
    }
};

void dfs(int cur) {
    for (auto &chi : adj[cur]) {
        if (chi == par[cur]) continue;
        par[chi] = cur;
        dfs(chi);
    }
}

void solve() {
    int n, m; cin >> n >> m;
    adj.resize(n);
    par.assign(n, -1);
    UF uf(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        if (!uf.join(a, b)) {
            dfs(b);
            int cur = a;
            while (cur != -1) {
                ans.push_back(cur);
                cur = par[cur];
            }
            // Shift index by +1
            cout << ans.size() + 1 << '\n';
            for (auto &x : ans) cout << x + 1 << ' ';
            cout << a + 1 << '\n';
            return;
        } else {
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }
    cout << "IMPOSSIBLE\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}