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

// A centroid: Removal results in CCs <= floor(n / 2) nodes
// Every tree has either 1 or 2 centroids
int n;
vector<vector<int>> adj;
vector<int> sub_size;

int get_size(int u, int p) {
    int res = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        res += get_size(v, u);
    }
    return sub_size[u] = res;
}

int get_centroid(int u, int p) {
    for (int v : adj[u]) {
        if (v == p) continue;
        if (sub_size[v] * 2 > n) return get_centroid(v, u);
    }
    return u;
}

void solve() {
    cin >> n;
    int a, b;
    adj.assign(n, vector<int>());
    sub_size.resize(n);
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    get_size(0, -1);
    cout << get_centroid(0, -1) + 1 << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}