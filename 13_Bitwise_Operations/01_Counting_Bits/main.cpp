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
    ll n; cin >> n;
    int p = 63 - __builtin_clzll(n);
    ll ans = n - (1ll << p) + 1;

    for (int i = p; i > 0; i--) {
        ll rem = (n + 1) / (1ll << i);
        ll mod = (n + 1) % (1ll << i);
        ll cnt = (1ll << (i - 1));
        ans += rem * cnt + max(0ll, mod - cnt);
    }
    cout << ans << '\n';
    // 0 1 0 1 0 1
    // 0 0 1 1 0 0 1 1 
    // 0 0 0 0 1 1 1 1 0 0 0
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}