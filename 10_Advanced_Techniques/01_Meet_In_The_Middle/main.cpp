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
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int l = n / 2, L = (1 << l);
    vector<int> pref;
    pref.reserve(L);
    for (int i = 0; i < L; i++) {
        bool check = true;
        int cur = 0;
        for (int mask = i; mask; mask &= mask - 1) {
            cur += arr[__builtin_ctz(mask)];
            if (cur > x) {
                check = false;
                break;
            }
        }
        if (check) pref.push_back(cur);
    }
    sort(pref.begin(), pref.end());
    int r = n - n / 2, R = (1 << r);
    ll ans = 0;
    for (int i = 0; i < R; i++) {
        bool check = true;
        int cur = 0;
        for (int mask = i; mask; mask &= mask - 1) {
            cur += arr[l + __builtin_ctz(mask)];
            if (cur > x) {
                check = false;
                break;
            }
        }
        if (!check) continue;
        int need = x - cur;
        auto lo = lower_bound(pref.begin(), pref.end(), need);
        auto hi = upper_bound(pref.begin(), pref.end(), need);
        ans += (hi - lo);
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}