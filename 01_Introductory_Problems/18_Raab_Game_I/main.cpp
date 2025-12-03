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
    int n, a, b; cin >> n >> a >> b;
    if (a == 0 && b == 0) {
        cout << "YES\n";
        for (int i = 1; i <= n; i++) cout << i << ' '; cout << '\n';
        for (int i = 1; i <= n; i++) cout << i << ' '; cout << '\n';
        return;
    }
    if (a == 0 || b == 0 || a + b > n) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    int tie = n - a - b;
    for (int i = 1; i <= n; i++) cout << i << ' '; cout << '\n';
    for (int i = 1; i <= tie; i++) cout << i << ' ';
    for (int i = tie + 1 + a; i <= n; i++) cout << i << ' ';
    for (int i = tie + 1; i <= tie + a; i++) cout << i << ' ';
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
}