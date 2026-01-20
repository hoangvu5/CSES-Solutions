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

void solve() {
    int n; cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int v = 2; v <= n; v++) {
        int u; cin >> u;
        adj[u].push_back(v);
    }
    vector<int> sub(n + 1, 0);
    function<int(int)> dfs = [&](const int& u) -> int {
        int cnt = 0;
        for (auto &v : adj[u]) {
            cnt += dfs(v) + 1;
        }
        return sub[u] = cnt;
    };
    dfs(1);
    for (int i = 1; i <= n; i++) cout << sub[i] << ' ';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}