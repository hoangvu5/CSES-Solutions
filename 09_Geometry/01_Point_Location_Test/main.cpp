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

typedef ll T;
typedef complex<T> pt;
#define x real()
#define y imag()

T cross(pt p, pt q) {return p.x*q.y - p.y*q.x;}

void solve() {
    int t; cin >> t;
    while (t--) {
        ll x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        pt p1{x1, y1}, p2{x2, y2}, p3{x3, y3};
        ll ans = cross(p2 - p1, p3 - p1);
        if (ans > 0) cout << "LEFT\n";
        else if (ans < 0) cout << "RIGHT\n";
        else cout << "TOUCH\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}