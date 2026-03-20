#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

template <class T> struct Seg {
    int n; T ID = 0; vector<T> seg;
    Seg(): n(0) {}
    Seg(int n): n(n), seg(2*n, 0) {}
    void update(int pos, T x) {
        for (seg[pos+n] = x, pos += n; pos > 1; pos >>= 1)
            seg[pos>>1] = max(seg[pos], seg[pos^1]);
    }
    T query(int l, int r) {
        T res = ID;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l&1) res = max(res, seg[l++]);
            if (r&1) res = max(res, seg[--r]);
        }
        return res;
    }
};

vector<vi> adj;
vi val, heavy, parent, head, pos, depth;
int cur_pos, n, q;
Seg<int> seg;

void dfs(int root) {
    vi order;
    vi stk = {root};
    parent[root] = -1;
    depth[root] = 0;
    while (!stk.empty()) {
        int v = stk.back(); stk.pop_back();
        order.push_back(v);
        for (int c : adj[v]) {
            if (c == parent[v]) continue;
            parent[c] = v;
            depth[c] = depth[v] + 1;
            stk.push_back(c);
        }
    }
    vi sz(n, 1);
    for (int i = order.size()-1; i >= 0; i--) {
        int v = order[i];
        for (int c : adj[v]) {
            if (c == parent[v]) continue;
            sz[v] += sz[c];
            if (heavy[v] == -1 || sz[c] > sz[heavy[v]])
                heavy[v] = c;
        }
    }
}

void decompose(int root, int h) {
    // use explicit stack of {node, head}
    vector<pair<int,int>> stk = {{root, h}};
    while (!stk.empty()) {
        auto [v, hd] = stk.back(); stk.pop_back();
        head[v] = hd;
        pos[v] = cur_pos++;
        // push light children first (processed later)
        for (int c : adj[v]) {
            if (c != parent[v] && c != heavy[v])
                stk.push_back({c, c});
        }
        // push heavy child last (processed next)
        if (heavy[v] != -1)
            stk.push_back({heavy[v], hd});
    }
}

int answer(int a, int b) {
    int res = 0;
    for (; head[a] != head[b]; b = parent[head[b]]) {
        if (depth[head[a]] > depth[head[b]]) swap(a, b);
        res = max(res, seg.query(pos[head[b]], pos[b]));
    }
    if (depth[a] > depth[b]) swap(a, b);
    return max(res, seg.query(pos[a], pos[b]));
}

void solve() {
    cin >> n >> q;
    val.resize(n);
    for (int i = 0; i < n; i++) cin >> val[i];
    adj.resize(n);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    heavy.assign(n, -1);
    parent.resize(n); head.resize(n);
    pos.resize(n); depth.resize(n);
    cur_pos = 0;
    dfs(0);
    decompose(0, 0);
    seg = Seg<int>(n);
    for (int i = 0; i < n; i++)
        seg.update(pos[i], val[i]);

    int type, a, b;
    while (q--) {
        cin >> type >> a >> b; a--;
        if (type == 1)
            seg.update(pos[a], b);
        else {
            b--;
            cout << answer(a, b) << '\n';
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}