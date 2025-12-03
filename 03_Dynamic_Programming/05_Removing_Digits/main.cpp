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
    int n; cin >> n;
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int x = i;
        while (x) {
            int d = x % 10;
            if (i - d >= 0 && dp[i - d] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - d] + 1);
            }
            x /= 10;
        }
    }
    cout << dp[n] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}