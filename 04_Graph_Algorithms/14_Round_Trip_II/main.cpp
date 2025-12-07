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
vector<int> col, par;
int cycle_end = -1, cycle_start = -1;

bool dfs(int u) {
    col[u] = 1;
    for (auto &v : adj[u]) {
        if (col[v] == 0) {
            par[v] = u;
            if (dfs(v)) return true;
        } else if (col[v] == 1) {
            cycle_end = u;
            cycle_start = v;
            return true;
        }
    }
    col[u] = 2;
    return false;
}

void solve() {
    int n, m; cin >> n >> m;
    adj.resize(n + 1);
    col.assign(n + 1, 0);
    par.assign(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].emplace_back(b);
    }
    for (int i = 1; i <= n; i++) {
        if (col[i] == 0 && dfs(i)) {
            vector<int> ans;
            ans.push_back(cycle_start);
            int cur = cycle_end;
            while (cur != cycle_start) {
                ans.push_back(cur);
                cur = par[cur];
            }
            reverse(ans.begin(), ans.end());
            cout << ans.size() + 1 << '\n';
            cout << cycle_start << ' ';
            for (auto &x : ans) cout << x << ' ';
            return;
        }
    }
    cout << "IMPOSSIBLE\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}