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
    int n = 3, k = 1;
    int ans = 9;
    vector<int> f = {9, 4, 3};
    vector<int> s = {8, 6, 1};
    // int n = 3, k = 4;
    // int ans = 6;
    // vector<int> f = {9, 8, 7};
    // vector<int> s = {6, 5, 4};
    cout << n << ' ' << k << endl;

    string type; int num;
    for (int i = 0; i < 100; i++) {
        cin >> type >> num;
        if (type == "F") {
            cout << f[num - 1] << endl;
        } else if (type == "S") {
            cout << s[num - 1] << endl;
        } else {
            if (check(num, ans)) {
                cout << "AC" << endl;
            } else {
                cout << "WA" << endl;
            }
            return;
        }
    }

    cin >> type >> num;
    if (type != "!") {
        cout << "WA" << endl;
    } else {
        if (check(ans, num)) {
            cout << "AC" << endl;
        } else {
            cout << "WA" << endl;
        }
    }
}

int main() {
    solve();
}