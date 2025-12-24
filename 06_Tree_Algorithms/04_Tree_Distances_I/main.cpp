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
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> firMax(n, 0);
    vector<int> secMax(n, 0);
    vector<int> child(n, 0);

    function<void(int,int)> dfs = [&](const int& u, const int& p) -> void {
        firMax[u] = 0;
        secMax[u] = 0;
        for (auto &v : adj[u]) {
            if (v == p) continue;
            dfs(v, u);
            if (firMax[v] + 1 > firMax[u]) {
                secMax[u] = firMax[u];
                firMax[u] = firMax[v] + 1;
                child[u] = v;
            } else if (firMax[v] + 1 > secMax[u]) {
                secMax[u] = firMax[v] + 1;
            }
        }
    };
    
    function<void(int, int)> dfs2 = [&](const int& u, const int& p) -> void {
        for (auto &v : adj[u]) {
            if (v == p) continue;
            if (child[u] == v) {
                if (firMax[v] < secMax[u] + 1) {
                    secMax[v] = firMax[v];
                    firMax[v] = secMax[u] + 1;
                    child[v] = u;
                } else {
                    secMax[v] = max(secMax[v], secMax[u] + 1);
                }
            } else {
                secMax[v] = firMax[v];
                firMax[v] = firMax[u] + 1;
                child[v] = u;
            }
            dfs2(v, u);
        }
    };

    dfs(0, -1);
    dfs2(0, -1);
    for (int i = 0; i < n; i++) cout << firMax[i] << ' ';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}