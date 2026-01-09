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
    int n; cin >> n;
    vector<int> lis;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        int lo = 0, hi = lis.size();
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            if (mi == lis.size() || lis[mi] >= x) hi = mi;
            else lo = mi + 1;
        }
        if (lo == lis.size()) lis.push_back(x);
        else lis[lo] = x;
    }
    cout << lis.size() << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}