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
    vector<vector<int>> arr(n);
    vector<vector<int>> hor, ver;
    int x1, y1, x2, y2;
    vector<int> yarr;
    for (int i = 0; i < n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        arr[i] = {x1, y1, x2, y2};
        if (x1 == x2) ver.push_back({x1, y1, y2});
        if (y1 == y2) {
            hor.push_back({x1, y1, +1});
            hor.push_back({x2, y1, -1});
        }
        yarr.push_back(y1);
        yarr.push_back(y2);
    }
    sort(yarr.begin(), yarr.end());
    yarr.erase(unique(all(yarr)), yarr.end());
    unordered_map<int, int> yma;
    for (int i = 0; i < yarr.size(); i++) {
        yma[yarr[i]] = i;
    }

    sort(ver.begin(), ver.end());
    sort(hor.begin(), hor.end(), [&](const auto a, const auto b) {
        if (a[0] == b[0]) return a[2] > b[2];
        return a[0] < b[0];
    });
    
    int k = yarr.size();
    FT ft(k + 1);
    int l = ver.size(), m = hor.size();
    ll ans = 0;
    for (int i = 0, j = 0; i < l; i++) {
        int x = ver[i][0], y1 = ver[i][1], y2 = ver[i][2];
        int yy1 = yma[y1], yy2 = yma[y2];
        while (j < m && (hor[j][0] < x || (hor[j][0] == x && hor[j][2] == 1))) {
            ft.update(yma[hor[j][1]], hor[j][2]);
            j++;
        }
        ans += ft.query(yy2 + 1) - ft.query(yy1);
        while (j < m && (hor[j][0] < x || (hor[j][0] == x && hor[j][2] == -1))) {
            ft.update(yma[hor[j][1]], hor[j][2]);
            j++;
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}