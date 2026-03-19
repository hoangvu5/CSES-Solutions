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
    int n, a, b; cin >> n >> a >> b;
    vector<ll> pref(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> pref[i];
        pref[i] += pref[i - 1];
    }
    multiset<ll> se;
    ll ans = LLONG_MIN;
    for (int i = 1; i <= n; i++) {
        if (i - a >= 0) {
            se.insert(pref[i - a]);
        }
        if (!se.empty())
            ans = max(ans, pref[i] - *se.begin());
        if (i - b >= 0) {
            se.erase(se.find(pref[i - b]));
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}