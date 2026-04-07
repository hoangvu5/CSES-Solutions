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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x+=0x9e3779b97f4a7c15;x=(x^(x>>30))*0xbf58476d1ce4e5b9;x=(x^(x>>27))*0x94d049bb133111eb;
        return x^(x>>31);}
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);}
};

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
    int n; cin >> n;
    vector<int> arr(n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int a, b;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int timer = 0;
    vector<int> tin(n), tout(n);
    auto dfs = [&](auto&& self, int u, int p) -> void {
        tin[u] = timer++;
        for (int v : adj[u]) {
            if (v == p) continue;
            self(self, v, u);
        }
        tout[u] = timer++;
    };
    dfs(dfs, 0, -1);

    unordered_map<int, int, custom_hash> ma;
    FT tree(2 * n + 1);
    vector<int> itin(n), itout(n);
    iota(itin.begin(), itin.end(), 0);
    iota(itout.begin(), itout.end(), 0);
    sort(itin.begin(), itin.end(), [&](int a, int b) {
        return tin[a] < tin[b];
    });
    sort(itout.begin(), itout.end(), [&](int a, int b) {
        return tout[a] < tout[b];
    });

    int j = 0;
    vector<int> ans(n);
    for (int v : itout) {
        while (j < n && tin[itin[j]] <= tout[v]) {
            int u = itin[j];
            if (ma.find(arr[u]) == ma.end()) {
                ma[arr[u]] = tin[u];
                tree.update(ma[arr[u]], 1);
            } else {
                tree.update(ma[arr[u]], -1);
                ma[arr[u]] = tin[u];
                tree.update(ma[arr[u]], 1);
            }
            j++;
        }
        ans[v] = tree.query(tout[v] + 1) - tree.query(tin[v]);
    }
    for (int i = 0; i < n; i++) cout << ans[i] << ' ';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}