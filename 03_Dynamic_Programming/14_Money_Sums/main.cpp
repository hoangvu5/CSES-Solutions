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
    vector<int> c(n + 1, 0), p(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        p[i] = p[i - 1] + c[i];
    }
    int m = p[n];
    vector<bool> dp(m + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int x = p[i]; x >= c[i]; x--) {
            dp[x] = dp[x] || dp[x - c[i]];
        }
    }
    cout << accumulate(dp.begin(), dp.end(), 0) - 1 << '\n';
    for (int i = 1; i <= m; i++) {
        if (dp[i]) cout << i << ' ';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}