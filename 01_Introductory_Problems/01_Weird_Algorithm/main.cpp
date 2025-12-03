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
    ll n; cin >> n;
    while (n != 1) {
        cout << n << ' ';
        if (n % 2 == 0) n /= 2;
        else n = 3 * n + 1;
    }
    cout << n << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}