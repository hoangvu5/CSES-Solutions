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

double expo(double a, int b) {
    double cur = a, ans = 1;
    while (b) {
        if (b & 1) ans = ans * cur;
        cur = cur * cur;
        b /= 2;
    }
    return ans;
}

void solve() {
    // Expected max k = k * (at least k - at least k - 1)
    // ... ((3/k)^n - (2/k)^n) * 3 + ((2/k)^n - (1/k)^n) * 2 + (1/k)^n * 1 
    // k - ((k-1/k)^n - ... - (2/k)^n - (1/k)^n
    int n, k; cin >> n >> k;
    double ans = k;
    for (int i = 1; i < k; i++) {
        ans -= expo((double)i / k, n);
    }
    cout << fixed << setprecision(6) << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}