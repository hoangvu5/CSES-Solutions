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
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> deg(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].emplace_back(b);
        deg[b]++;
    }
    queue<int> qu;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) qu.push(i);
    }
    vector<int> ans;
    while (!qu.empty()) {
        int v = qu.front(); qu.pop();
        ans.emplace_back(v);
        for (auto &u : adj[v]) {
            if (--deg[u] == 0) qu.push(u);
        }
    }
    if (ans.size() != n) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    for (auto &x : ans) cout << x << ' ';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}