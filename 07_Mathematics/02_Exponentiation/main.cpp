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
        int a, b; cin >> a >> b;
        cout << bin_exp(a, b, M) << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}