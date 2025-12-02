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

// R B R
// B R R B R
// B R B B R B R

// Idea: Eliminate the side with possibly none if being 
// put optimally

char opp(char x) {
    return ((x == 'B') ? 'R' : 'B');
}

void solve() {
    int n; cin >> n;
    char cl, cr;
    cout << "? 1" << endl; cin >> cl;
    cout << "? " << n << endl; cin >> cr;

    if (cl == cr) {
        cout << "! " << n << endl;
        return;
    }

    int lo = 1, hi = n - 1;
    while (lo <= hi) {
        int mi = lo + (hi - lo + 1) / 2;
        // Handle edge cases
        if (hi - lo == 0) {
            cout << "! " << lo << endl;
            return;
        }
        cout << "? " << mi << endl;
        char res; cin >> res;
        if (hi - lo == 1) {
            if (cl == res) {
                cout << "! " << lo << endl;
            } else {
                cout << "! " << mi << endl;
            }
            return;
        }
        
        // Calculate optimal letter if left side doesn't contain
        char opt = ((mi - lo) % 2 == 1 ? opp(cl) : cl);
        if (res == opt) {
            lo = mi;
            cl = res;
        } else {
            hi = mi - 1;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}