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

struct FT {
    vector<ll> s;
    FT(int n) : s(n) {}
    void update(int pos, ll dif) { // a[pos] += dif
        for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
    }
    ll query(int pos) { // sum of values in [0, pos)
        ll res = 0;
        for (; pos > 0; pos &= pos - 1) res += s[pos-1];
        return res;
    }
    int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
        // Returns n if no sum is >= sum, or -1 if empty sum is.
        if (sum <= 0) return -1;
        int pos = 0;
        for (int pw = 1 << 25; pw; pw >>= 1) {
            if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
                pos += pw, sum -= s[pos-1];
        }
        return pos;
    }
};


void solve() {
    int n, q; cin >> n >> q;
    vector<ll> val(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> tin(n + 1), tout(n + 1);
    int timer = 0;
    auto dfs = [&](auto&& self, int cur, int par) -> void {
        tin[cur] = timer++;
        for (int nxt : adj[cur]) {
            if (nxt == par) continue;
            self(self, nxt, cur);
        }
        tout[cur] = timer;
    };
    dfs(dfs, 1, 0);
    FT ft(n + 1);
    for (int i = 1; i <= n; i++) {
        ft.update(tin[i], val[i]);
        ft.update(tout[i], -val[i]);
    }
    int type, s; ll x;
    while (q--) {
        cin >> type >> s;
        if (type == 1) {
            cin >> x;
            ft.update(tin[s], x - val[s]);
            ft.update(tout[s], -x + val[s]);
            val[s] = x;
        } else {
            cout << ft.query(tin[s] + 1) << '\n';
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}