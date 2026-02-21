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
    int n; cin >> n;
    vector<array<int, 3>> arr(n);
    set<int> coor;
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1];
        arr[i][2] = i;
        coor.insert(arr[i][0]);
        coor.insert(arr[i][1]);
    }
    sort(arr.begin(), arr.end(), [&](const auto &a, const auto &b) {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    });
    // Compression
    unordered_map<int, int> comp;
    int m = 0;
    for (auto &x : coor) {
        comp[x] = m++;
    }

    vector<int> a(n), b(n);
    // Count number <= end
    FT f(m);
    for (int i = n - 1; i >= 0; i--) {
        auto &[st, en, id] = arr[i];
        a[id] = f.query(comp[en] + 1);
        f.update(comp[en], 1);
    }
    // Count number >= end
    FT g(m);
    for (int i = 0; i < n; i++) {
        auto &[st, en, id] = arr[i];
        b[id] = g.query(m - comp[en] + 1);
        g.update(m - comp[en], 1);
    }
    for (int i = 0; i < n; i++) cout << a[i] << ' ';
    cout << '\n';
    for (int i = 0; i < n; i++) cout << b[i] << ' ';
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}