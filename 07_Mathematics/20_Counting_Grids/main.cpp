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

int expo(int a, int b, int m) {
    int ans = 1, cur = a;
    while (b) {
        if (b & 1) ans = 1ll * ans * cur % m;
        cur = 1ll * cur * cur % m;
        b /= 2;
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    int ans = 0;
    // 360: 2^(n^2) % M
    ans = (ans + expo(2, 1ll * n * n % (M - 1), M)) % M;
    // 180: 2^(((n^2+1)/2)) % M
    ans = (ans + expo(2, (1ll * n * n + 1) / 2 % (M - 1), M)) % M;
    // 90 and 270: 2^(tot+1)
    // Orbit size 4
    // If n odd: 1 + (n^2-1)/4
    // If n even: n^2/4
    if (n & 1)
        ans = (ans + expo(2, ((1ll * n * n - 1) / 4 + 2) % (M - 1), M));
    else
        ans = (ans + expo(2, (1ll * n * n / 4 + 1) % (M - 1), M)) % M;
    // Divide by 4 rotations
    ans = 1ll * ans * expo(4, M - 2, M) % M;
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}