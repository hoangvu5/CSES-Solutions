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
    ll ans = 1;
    for (int j = 30; j >= 0; j--) {
        if (basis[j]) ans <<= 1;
        
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}