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
    int n = 5; cout << n << endl;
    string str = "RRBRB";
    int ans = 1;

    string type; int num;
    for (int i = 0; i < 20; i++) {
        cin >> type >> num;
        if (type == "?") {
            cout << str[num - 1] << endl;
        } else {
            if (check(ans, num)) {
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
    cin.tie(0)->sync_with_stdio(0);
    solve();
}