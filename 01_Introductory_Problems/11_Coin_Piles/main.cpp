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
    int t; cin >> t;
    int a, b;
    for (int i = 0; i < t; i++) {
        cin >> a >> b;
        if (a < b) swap(a, b);
        cout << (((a + b) % 3 != 0 || 2 * b < a) ? "NO\n" : "YES\n");
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}