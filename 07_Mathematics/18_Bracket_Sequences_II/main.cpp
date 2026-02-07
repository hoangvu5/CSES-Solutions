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
const int m = 3e6 + 1;
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
    int n; cin >> n;
    string s; cin >> s;
    if (n % 2 == 1) {
        cout << 0;
        return;
    }

    int len = s.size();
    int open = 0, bal = 0;
    for (int i = 0; i < len; i++) {
        bal += (s[i] == '(' ? 1 : -1);
        open += (s[i] == '(');
        if (bal < 0) {
            cout << 0;
            return;
        }
    }
    if (open > n) {
        cout << 0;
        return;
    }

    fact[0] = 1;
    for (int i = 1; i < m; i++) {
        fact[i] = 1ll * fact[i-1] * i % M;
    }

    inv[m-1] = expo(fact[m-1], M - 2);
    for (int i = m - 2; i >= 0; i--) {
        inv[i] = 1ll * inv[i+1] * (i + 1) % M;
    }

    int K = bal;
    int N = n / 2 - open;
    // Calculate K-th convolution of Nth Catalan number
    // = (K + 1) * C(2N + K, N) / (N + K + 1)
    cout << 1ll * (K + 1) * C(2 * N + K, N) % M * expo(N + K + 1, M - 2) % M;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}