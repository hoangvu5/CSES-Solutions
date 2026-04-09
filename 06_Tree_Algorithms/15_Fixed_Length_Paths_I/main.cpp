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

int n, k, mx_depth;
ll ans = 0;
vector<vector<int>> adj;
vector<int> subtree_size;
vector<bool> is_removed;
vector<int> cnt;

int get_subtree_size(int u, int p = -1) {
    subtree_size[u] = 1;
    for (int v : adj[u]) {
        if (v == p || is_removed[v]) continue;
        subtree_size[u] += get_subtree_size(v, u);
    }
    return subtree_size[u];
}

int get_centroid(int u, int tree_size, int p = -1) {
    for (int v : adj[u]) {
        if (v == p || is_removed[v]) continue;
        if (subtree_size[v] * 2 > tree_size) {
            return get_centroid(v, tree_size, u);
        }
    }
    return u;
}

void get_cnt(int u, int p, bool filling, int depth = 1) {
    if (depth > k) return;
    mx_depth = max(mx_depth, depth);
    if (filling) cnt[depth]++;
    else ans += cnt[k - depth];
    for (int v : adj[u])
        if (!is_removed[v] && v != p) get_cnt(v, u, filling, depth + 1);
}

void build_centroid_decomp(int u = 0) {
    int centroid = get_centroid(u, get_subtree_size(u, -1));
    mx_depth = 0;
    for (int v : adj[centroid]) {
        if (is_removed[v]) continue;
        get_cnt(v, centroid, false);
        get_cnt(v, centroid, true);
    }
    fill(cnt.begin() + 1, cnt.begin() + mx_depth + 1, 0);
    is_removed[centroid] = true;
    for (int v : adj[centroid]) {
        if (is_removed[v]) continue;
        build_centroid_decomp(v);
    }
}

void solve() {
    cin >> n >> k;
    adj.assign(n, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // For each node, count iterate over
    // centroid ancestor and then query number of nodes
    // with distance k - (dist from node to centroid)
    // So each centroid must store number of nodes with 
    // each distance
    subtree_size.resize(n);
    is_removed.assign(n, 0);
    cnt.assign(n + 1, 0);
    cnt[0] = 1;
    build_centroid_decomp();
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}