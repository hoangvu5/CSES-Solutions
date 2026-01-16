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

int n, m;
vector<vector<pair<int, int>>> adj;
vector<int> iter, circuit;
vector<bool> vis;
stack<int> path;

void solve() {
    cin >> n;
    // Construct a graph
    // Nodes are bitmask length n
    if (n == 1) {
        cout << "01\n";
        return;
    }

    adj.resize(1 << (n - 1));
    int m = 0;
    for (int i = 0; i < (1 << (n - 1)); i++) {
        int l = ((i << 1) | 0) & ((1 << (n - 1)) - 1);
        int r = ((i << 1) | 1) & ((1 << (n - 1)) - 1);
        adj[i].push_back({l, m++});
        adj[i].push_back({r, m++});
    }

    // Find an Euler path
    iter.assign(1 << (n - 1), 0);
    vis.assign(m, false);
    circuit.clear();
    path.push(0);
    while (!path.empty()) {
        int u = path.top();
        while (iter[u] < adj[u].size() && vis[adj[u][iter[u]].second]) iter[u]++;
        if (iter[u] < adj[u].size()) {
            auto &[v, i] = adj[u][iter[u]];
            vis[i] = true;
            path.push(v);
        } else {
            circuit.push_back(u);
            path.pop();
        }
    }
    reverse(circuit.begin(), circuit.end());

    cout << string(n - 2, '0');
    for (auto &x : circuit) cout << (x & 1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}