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
    int n, t; cin >> n >> t;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    ll l = 0, r = 1e18;
    while (l < r) {
        ll m = l + (r - l) / 2;
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            sum += m / arr[i];
            if (sum >= t) {
                r = m;
                break;
            }
        }
        if (sum < t) l = m + 1;
    }
    cout << l << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}