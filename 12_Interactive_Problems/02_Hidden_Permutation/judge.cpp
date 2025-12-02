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

bool check(vector<int> &a, vector<int> &b) {
    if (a.size() != b.size()) return false;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

void solve() {
    int n = 5;
    vector<int> perm = {5, 3, 4, 1, 2};
    cout << n << endl;

    string type; 
    for (int i = 0; i < 10000; i++) {
        cin >> type;
        if (type == "?") {
            int i, j; cin >> i >> j;
            i--; j--;
            if (perm[i] < perm[j]) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            vector<int> ans(n);
            for (int i = 0; i < n; i++) cin >> ans[i];
            if (check(perm, ans)) {
                cout << "AC" << endl;
            } else {
                cout << "WA" << endl;
            }
            return;
        }
    }

    cin >> type;
    if (type == "?") {
        cout << "WA" << endl;
    } else {
        vector<int> ans(n);
        for (int i = 0; i < n; i++) cin >> ans[i];
        if (check(perm, ans)) {
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