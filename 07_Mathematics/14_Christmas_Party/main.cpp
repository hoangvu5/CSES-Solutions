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

const int M = 1e9 + 7;

void solve() {
    int n; cin >> n;
    if (n == 1) {
        cout << 0 << '\n';
        return;
    }
    int prv = 1, cur = 0, nxt = 0;
    for (int i = 2; i <= n; i++) {
        nxt = 1ll * (i - 1) * (prv + cur) % M;
        prv = cur;
        cur = nxt;
    }
    cout << nxt << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}