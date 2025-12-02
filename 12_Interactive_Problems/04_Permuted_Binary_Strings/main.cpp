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

vector<int> arr;
vector<vector<bool>> ind;

void solve() {
    int n; cin >> n;
    arr.resize(n);
    ind.assign(n, vector<bool>(n, true));

    string check;
    int len = (int)ceil(log2(n));
    for (int i = 0; i < len; i++) {
        string query(n, '0');
        for (int j = 0; j < n; j++) {
            if ((j & (1 << i)) != 0) {
                query[j] = '1';
            }
        }
        cout << "? " << query << endl;

        string res; cin >> res;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (res[i] != query[j]) {
                    ind[i][j] = false;
                }
            }
        }
    }

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (ind[i][j]) {
                ans[i] = j + 1;
                break;
            }
        }
    }

    cout << '!';
    for (int i = 0; i < n; i++) cout << ' ' << ans[i];
    cout << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}