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
    int t; cin >> t;
    ll y, x, k;
    ll start, ans;
    for (int i = 0; i < t; i++) {
        cin >> y >> x;
        k = max(y, x);
        start = (k - 1) * (k - 1) + 1;
        if (k % 2 != 0) {
            ans = k - 1 - y + x;
        } else {
            ans = k - 1 - x + y;
        }
        cout << ans + start << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}