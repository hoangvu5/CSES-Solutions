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
    int n, x; cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    // dp[mask] = {min num of rides, weight of last ride}
    vector<pair<int, int>> dp((1 << n), {INT_MAX, 0});
    dp[0] = {1, 0};
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if ((mask >> i) & 1) {
                int sub = mask ^ (1 << i);
                auto [num, wei] = dp[sub];
                if (wei + arr[i] <= x) {
                    wei += arr[i];
                } else {
                    wei = arr[i];
                    num++;
                }
                dp[mask] = min(dp[mask], {num, wei});
            }
        }
    }
    cout << dp[(1 << n) - 1].first << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}