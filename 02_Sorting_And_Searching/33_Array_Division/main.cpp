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
    vector<ll> arr(n);
    ll l = 0, r = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        l = max(l, arr[i]);
        r += arr[i];
    }
    while (l < r) {
        ll m = l + (r - l) / 2;
        int cnt = 1;
        ll cur = 0;
        for (int i = 0; i < n; i++) {
            if (cur + arr[i] <= m) {
                cur += arr[i];
            } else {
                cur = arr[i];
                cnt++;
            }
        }
        if (cnt > k) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    cout << l << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}