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
const int m = 2e6;
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

int C(int a, int b) {
    return 1ll * fact[a] * inv[b] % M * inv[a - b] % M;
}

void solve() {
    fact[0] = 1;
    for (int i = 1; i < m; i++) {
        fact[i] = 1ll * fact[i-1] * i % M;
    }

    inv[m-1] = expo(fact[m-1], M - 2);
    for (int i = m - 2; i >= 0; i--) {
        inv[i] = 1ll * inv[i+1] * (i + 1) % M;
    }

    int n, m; cin >> n >> m;
    cout << C(m + n - 1, n - 1) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}