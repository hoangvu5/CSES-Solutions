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
    int m = 1e9 + 7;
    int c = 1, e = 2;
    while (n) {
        if (n & 1) c = 1ll * c * e % m;
        e = 1ll * e * e % m;
        n /= 2;
    }
    cout << c << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}