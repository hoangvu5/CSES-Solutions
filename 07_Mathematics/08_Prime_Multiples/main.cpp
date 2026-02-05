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
    ll n; int k; cin >> n >> k;
    int K = 1 << k;
    vector<ll> arr(k);
    ll ans = 0;
    for (int i = 0; i < k; i++) cin >> arr[i];
    for (int mask = 1; mask < K; mask++) {
        int bits = __builtin_popcount(mask);
        ll num = 1;
        for (int i = 0; i < k; i++) {
            if ((mask >> i) & 1) {
                if (num >= n / arr[i] + 1) {
                    num = LLONG_MAX;
                    break;
                }
                num *= arr[i];
            }
        }
        num = n / num;
        ans = ans + ((bits & 1) ? num : -num); 
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}