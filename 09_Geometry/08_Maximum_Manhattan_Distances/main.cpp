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
    int n; cin >> n;
    vector<vector<ll>> arr(n);
    ll x, y, ans = 0;
    int l = (1 << 2);
    vector<ll> mx(l, LLONG_MIN), mn(l, LLONG_MAX);
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        arr[i] = {x, y};
        for (int d = 0; d < (1 << 2); d++) {
            ll cur = 0;
            for (int j = 0; j < 2; j++) {
                if (d & (1 << j)) cur += arr[i][j];
                else cur -= arr[i][j];
            }
            mx[d] = max(mx[d], cur);
            mn[d] = min(mn[d], cur);
            ans = max(ans, mx[d] - mn[d]);
        }
        cout << ans << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}