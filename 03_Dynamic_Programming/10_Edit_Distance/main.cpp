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
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();
    // Add, replace, remove
    // dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 1], dp[i - 1][j])
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int j = 0; j <= m; j++) dp[0][j] = j;
    s = "*" + s; t = "*" + t;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i] == t[j]) dp[i][j] = dp[i - 1][j - 1];
            else {
                int cur = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                if (cur != INT_MAX) dp[i][j] = cur + 1;
            }
        }
    }
    cout << dp[n][m] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}