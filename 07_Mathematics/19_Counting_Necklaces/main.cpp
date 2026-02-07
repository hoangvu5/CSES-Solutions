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
const int m = 1e6 + 1;
int fact[m], inv[m];

int expo(int a, int b) {
    int ans = 1, cur = a;
    while (b) {
        if (b & 1) ans = 1ll * ans * cur % M;
        cur = 1ll * cur * cur % M;
        b /= 2;
    }
    return ans;
}

void solve() {
    int n, m; cin >> n >> m;
    // Burnside's Lemma
    // Sum of m ^ gcd(i, n) / n for i from [1, n]
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + expo(m, __gcd(i, n))) % M;
    }
    ans = 1ll * ans * expo(n, M - 2) % M;
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}