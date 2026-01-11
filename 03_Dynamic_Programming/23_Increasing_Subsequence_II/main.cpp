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

const int MOD = 1e9 + 7;

struct FT {
    vector<ll> s;
    FT(int n) : s(n) {}
    void update(int pos, ll dif) { // a[pos] += dif
        for (; pos < sz(s); pos |= pos + 1) s[pos] = (s[pos] + dif) % MOD;
    }
    ll query(int pos) { // sum of values in [0, pos)
        ll res = 0;
        for (; pos > 0; pos &= pos - 1) res = (res + s[pos-1]) % MOD;
        return res;
    }
};


void solve() {
    int n; cin >> n;
    vector<int> arr(n + 1, 0);
    set<int> se; se.insert(0);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i]; se.insert(arr[i]);
    }
    int len = 0;
    map<int, int> ma;
    for (auto x : se) {
        ma[x] = len++;
    }
    FT ft(len);
    vector<int> dp(n + 1, 0);
    int ans = 0;
    dp[0] = 1; ft.update(0, 1);
    
    for (int i = 1; i <= n; i++) {
        int idx = ma[arr[i]];
        dp[i] = ft.query(idx);
        ft.update(idx, dp[i]);
        ans = (ans + dp[i]) % MOD;
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}