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
int bin_exp(int a, int b, int m) {
    int cur = a, ans = 1;
    while (b) {
        if (b & 1) ans = 1ll * ans * cur % m;
        cur = 1ll * cur * cur % m;
        b /= 2;
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    while (n--) {
        int a, b, c, p, r; cin >> a >> b >> c;
        if (b == 0 || c == 0)
            p = (c == 0) ? 1 : 0;
        else
            // Calculate exponent modulo Euler's totient function of M
            // = M - 1 because M is prime
            p = bin_exp(b, c, M - 1);
        
        if (a == 0 || p == 0)
            r = (p == 0) ? 1 : 0;
        else
            r = bin_exp(a, p, M);
        cout << r << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}