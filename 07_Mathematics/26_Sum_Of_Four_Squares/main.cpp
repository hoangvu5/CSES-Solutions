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
    // Every non-negative integers can be represented
    // as sum of four square non-negative integers
    // Method 1: Brute-force in O(n^3/2)
    // Method 2: 4SUM + meet-in-the-middle in O(nlog(sqrtn))
    // Method 3: Legendre's 3-square theorem (n is sum of 3 sq. iff n != 4^t(8u+7))
    int t; cin >> t;
    vector<int> q(t);
    int lim = 0;
    for (int i = 0; i < t; i++) {
        cin >> q[i];
        lim = max(lim, q[i]);
    }
    vector<pair<int, int>> ma(lim + 1, {-1, -1});
    for (int i = 0; i * i <= lim; i++) {
        for (int j = 0; i * i + j * j <= lim; j++) {
            ma[i * i + j * j] = {i, j};
        }
    }
    for (int i = 0; i < t; i++) {
        int n = q[i];
        for (int j = 0; j <= n / 2; j++) {
            auto a = ma[j];
            auto b = ma[n - j];
            if (a.first != -1 && b.first != -1) {
                cout << a.first << ' '
                     << a.second << ' '
                     << b.first << ' '
                     << b.second << '\n';
                break;
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}