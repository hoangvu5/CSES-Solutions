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
    int n, k; cin >> n >> k;
    vector<int> moves(k);
    for (int i = 0; i < k; i++) cin >> moves[i];
    sort(moves.begin(), moves.end());
    vector<bool> dp(n + 1);
    dp[0] = false;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k && i - moves[j] >= 0; j++) {
            if (dp[i - moves[j]] == false) {
                dp[i] = true;
                break;
            }
        }
        cout << (dp[i] ? 'W' : 'L');
    }
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}