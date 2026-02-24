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
    int n; ll x; cin >> n >> x;
    ll ans = 0, pref = 0;
    unordered_map<ll, int> ma;
    ma[0] = 1;
    for (int i = 1; i <= n; i++) {
        int v; cin >> v;
        pref += v;
        ans += ma[pref-x];
        ma[pref]++;
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}