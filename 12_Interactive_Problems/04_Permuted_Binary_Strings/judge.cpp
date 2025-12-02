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

bool check(auto &a, auto &b) {
    return a == b;
}

void solve() {
    int n = 5; 
    vector<int> perm = {1, 3, 2, 5, 4};
    cout << n << endl;
    string type;
    string bits;
    for (int i = 0; i < 10; i++) {
        cin >> type;
        if (type == "?") {
            cin >> bits;
            string res(n, ' ');
            for (int i = 0; i < n; i++) {
                res[perm[i] - 1] = bits[i];
            }
            cout << res << endl;
        } else {
            vector<int> res(n);
            for (int i = 0; i < n; i++) cin >> res[i];
            if (check(res, perm)) {
                cout << "AC" << endl;
            } else {
                cout << "WA" << endl;
            }
            return;
        }
    }

    cin >> type;
    if (type != "!") {
        cout << "WA" << endl;
    } else {
        vector<int> res(n);
        for (int i = 0; i < n; i++) cin >> res[i];
        if (check(res, perm)) {
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