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
    FT(int n) : s(n, 0) {}
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
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    // Sort queries by right endpoint
    // BIT, coordinate compression, save most recent
    vector<pair<int, int>> queries(q);
    int a, b;
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        a--; b--;
        queries[i] = {a, b};
    }
    vector<ll> ans(q);
    vector<int> idx(q);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](const auto& a, const auto& b) {
        return queries[a].second < queries[b].second;
    });
    unordered_map<int, int, custom_hash> ma;
    FT tree(n + 1);
    int j = 0;
    for (int i : idx) {
        auto [fi, se] = queries[i];
        while (j <= se) {
            int col = arr[j];
            if (ma.find(col) == ma.end()) {
                ma[col] = j;
                tree.update(ma[col], 1);
            } else {
                tree.update(ma[col], -1);
                ma[col] = j;
                tree.update(ma[col], 1);
            }
            j++;
        }
        ans[i] = tree.query(se + 1) - tree.query(fi);
    }
    for (int i = 0; i < q; i++) cout << ans[i] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}