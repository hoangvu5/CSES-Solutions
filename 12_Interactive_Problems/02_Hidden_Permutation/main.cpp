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

int n;
vector<int> ind;
string check;

void merge(int lo, int hi) { // [lo, mi] and (mi, hi]
    if (lo == hi) return;
    int mi = lo + (hi - lo) / 2;
    merge(lo, mi);
    merge(mi + 1, hi);

    vector<int> tmp;
    int i = lo, j = mi + 1;
    while (i <= mi && j <= hi) {
        cout << "? " << ind[i] << ' ' << ind[j] << endl;
        cin >> check;
        if (check == "YES") tmp.push_back(ind[i++]);
        else tmp.push_back(ind[j++]);
    }
    while (i <= mi) tmp.push_back(ind[i++]);
    while (j <= hi) tmp.push_back(ind[j++]);

    for (int i = lo; i <= hi; i++) {
        ind[i] = tmp[i - lo];
    }
}

void solve() {
    cin >> n; ind.resize(n);
    iota(ind.begin(), ind.end(), 1);
    merge(0, n - 1);

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[ind[i] - 1] = i + 1;
    }

    cout << '!';
    for (int i = 0; i < n; i++) {
        cout << ' ' << ans[i];
    }
    cout << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}