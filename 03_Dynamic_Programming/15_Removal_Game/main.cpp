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

ll dp[2][5000][5000];
int a[5000];

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) dp[0][i][i] = a[i], dp[1][i][i] = 0ll;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j + i < n; j++) {
            dp[0][j][j+i] = max(a[j]+dp[1][j+1][j+i], a[j+i]+dp[1][j][j+i-1]);
            dp[1][j][j+i] = min(dp[0][j+1][j+i], dp[0][j][j+i-1]);
        }
    }
    cout << dp[0][0][n-1] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}