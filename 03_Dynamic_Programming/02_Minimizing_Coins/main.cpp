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
    vector<int> c(n), dp(x + 1, INT_MAX);
    for (int i = 0; i < n; i++) cin >> c[i];
    
    dp[0] = 0;
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i - c[j] >= 0 && dp[i - c[j]] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - c[j]] + 1);
            }
        }
    }
    if (dp[x] == INT_MAX) cout << -1 << '\n';
    else cout << dp[x] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}