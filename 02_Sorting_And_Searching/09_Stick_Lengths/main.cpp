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
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int m1 = a[(n - 1) / 2], m2 = a[n / 2];
    ll s1 = 0, s2 = 0;
    for (int i = 0; i < n; i++) {
        s1 += abs(a[i] - m1);
        s2 += abs(a[i] - m2);
    }
    cout << min(s1, s2) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}