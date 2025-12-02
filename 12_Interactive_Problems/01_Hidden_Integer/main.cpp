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
    int lo = 1, hi = 1e9;
    string check;
    while (lo < hi) {
        int mi = lo + (hi - lo) / 2;
        cout << "? " << mi << endl;
        cin >> check;
        if (check == "YES") {
            lo = mi + 1;
        } else {
            hi = mi;
        }
    }
    cout << "! " << lo << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}