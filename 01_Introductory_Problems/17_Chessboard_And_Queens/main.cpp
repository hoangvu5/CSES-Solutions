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

int n = 8, ans = 0;
string s;
vector<bool> vrt, ddo, dpu;
vector<vector<bool>> rsvp;

void recurse(int y) {
    if (y == n) {
        ans++;
        return;
    }
    for (int x = 0; x < n; x++) {
        int i = n - 1 - y + x, j = x + y;
        if (!vrt[x] && !ddo[i] && !dpu[j] && !rsvp[x][y]) {
            vrt[x] = ddo[i] = dpu[j] = true;
            recurse(y + 1);
            vrt[x] = ddo[i] = dpu[j] = false;

        }
    }
}

void solve() {
    vrt.assign(n, false);
    ddo.assign(2 * n - 1, false);
    dpu.assign(2 * n - 1, false);
    rsvp.assign(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == '*') rsvp[i][j] = true;
        }
    }
    recurse(0);
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}