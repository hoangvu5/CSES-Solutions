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
    int x = 696060;
    string type; int y;
    for (int i = 0; i < 30; i++) {
        cin >> type >> y;
        if (type == "?") {
            if (y < x) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            if (x == y) {
                cout << "AC" << endl;
            } else {
                cout << "WA" << endl;
            }
            return;
        }
    }
    
    cin >> type >> y;
    if (type == "?") {
        cout << "WA" << endl;
    } else {
        if (x == y) {
            cout << "AC" << endl;
        } else {
            cout << "WA" << endl;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
