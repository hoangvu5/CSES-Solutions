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

const ll MOD = 1e9 + 7;

ll get_sum(ll x) {
    x %= MOD;
    if (x % 2 == 0) return x / 2 * (x + 1) % MOD;
    return (x + 1) / 2 * x % MOD;
}

void solve() {
    ll n; cin >> n;
    ll sum = 0;
    ll i = 1;
    while (i <= n) {
        ll f = n / i;
        ll l = n / f;
        sum = (sum + (get_sum(f) * (l - i + 1) % MOD)) % MOD;
        i = l + 1;
    }
    cout << sum << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}