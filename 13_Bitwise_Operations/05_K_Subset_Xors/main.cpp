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
    int n, k; cin >> n >> k;
    int rank = 0;
    vector<ll> basis(31);
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        for (int j = 30; j >= 0; j--) {
            if (!((x >> j) & 1)) continue;
            if (!basis[j]) { basis[j] = x; rank++; break; }
            x ^= basis[j];
        }
    }
    for (int j = 30; j >= 0; j--) {
        if (!basis[j]) continue;
        for (int l = j - 1; l >= 0; l--) {
            if ((basis[j] >> l) & 1) basis[j] ^= basis[l];
        }
    }
    ll copies = 1ll << (n - rank);
    vector<ll> b;
    for (int j = 0; j <= 30; j++)
        if (basis[j]) b.push_back(basis[j]);
    ll printed = 0;
    for (ll i = 0; printed < k; i++) {
        ll val = 0;
        for (int j = 0; j < rank; j++) {
            if ((i >> j) & 1) val ^= b[j];
        }
        ll times = min(copies, k - printed);
        for (ll t = 0; t < times; t++) cout << val << ' ';
        printed += times;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}