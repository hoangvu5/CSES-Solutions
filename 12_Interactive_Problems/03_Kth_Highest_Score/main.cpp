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

// Strategy:
// Binary search contribution of Finland from 0 to k
// Compare F[x] and S[k - x]
// If x == 0, ignore F[0]
// If x == k, ignore S[0]

int askFinland(int x) {
    cout << "F " << x << endl;
    int val; cin >> val;
    return val;
}

int askSweden(int y) {
    cout << "S " << y << endl;
    int val; cin >> val;
    return val;
}

void solve() {
    int n, k; cin >> n >> k;
    
    int lo = max(0, k - n), hi = min(k, n);
    while (lo <= hi) {
        int x = (lo + hi) / 2;
        int y = k - x;
        
        int Fx = ((x == 0) ? INT_MAX : askFinland(x));
        int Fx1 = ((x == n) ? INT_MIN : askFinland(x + 1));
        int Sy = ((y == 0) ? INT_MAX : askSweden(y));
        int Sy1 = ((y == n) ? INT_MIN : askSweden(y + 1));

        if (Fx >= Sy1 && Sy >= Fx1) {
            cout << "! " << min(Fx, Sy) << endl;
            return;
        }
        
        if (Fx >= Sy1) {
            lo = x + 1; // More Finland
        } else {
            hi = x - 1; // Less Finland
        }
    }
}

int main() {
    solve();
}