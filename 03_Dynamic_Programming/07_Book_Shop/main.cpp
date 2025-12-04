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
    vector<int> h(n), s(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < n; i++) cin >> s[i];
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - h[i - 1] >= 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - h[i - 1]] + s[i - 1]);
            }
        }
    }
    cout << dp[n][x] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}