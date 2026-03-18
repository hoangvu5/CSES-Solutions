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

void print128(__int128 x) {
    if (x < 0) { cout << '-'; x = -x; }
    if (x > 9) print128(x / 10);
    cout << (char)('0' + x % 10);
}

__int128 manhattan_1d(vector<ll>& a) {
    sort(all(a));
    __int128 ans = 0, pref = 0;
    for (int i = 0; i < sz(a); i++) {
        ans += a[i] * i - pref;
        pref += a[i];
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    __int128 ans = manhattan_1d(x) + manhattan_1d(y);
    print128(ans);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}