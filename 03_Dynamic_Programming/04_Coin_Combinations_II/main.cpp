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

const int m = 1e9 + 7;

void solve() {
    int n, x; cin >> n >> x;
    vector<int> c(n), dp(x + 1, 0);
    for (int i = 0; i < n; i++) cin >> c[i];

    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= x; j++) {
            if (j - c[i] >= 0) {
                dp[j] = (dp[j] + dp[j - c[i]]) % m;
            }
        }
    }
    cout << dp[x] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}