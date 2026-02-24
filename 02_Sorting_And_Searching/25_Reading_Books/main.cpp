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
    // 8 5 4
    // 8 8
    int n; cin >> n;
    ll s = 0, m = 0;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        s += x;
        m = max(m, x);
    }
    cout << max(s, 2 * m) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}