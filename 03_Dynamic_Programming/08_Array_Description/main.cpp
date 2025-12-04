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

const int mod = 1e9 + 7;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    vector<vector<int>> dp(n, vector<int>(m + 2, 0));
    if (x[0] == 0) fill(dp[0].begin() + 1, dp[0].begin() + m + 1, 1);
    else dp[0][x[0]] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = -1; j <= 1; j++) {
            if (x[i] == 0) for (int k = 1; k <= m; k++)
                dp[i][k] = (dp[i][k] + dp[i - 1][k + j]) % mod;
            else
                dp[i][x[i]] = (dp[i][x[i]] + dp[i - 1][x[i] + j]) % mod;
        }
    }

    int ans = 0;
    for (int i = 1; i <= m; i++) {
        ans = (ans + dp[n - 1][i]) % mod;
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}