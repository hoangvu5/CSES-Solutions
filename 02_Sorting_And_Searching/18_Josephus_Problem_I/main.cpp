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
    // If n odd, then start with 1 next round
    // If n even, then start with 2 next round
    int n; cin >> n;
    set<int> se;
    for (int i = 1; i <= n; i++) se.insert(i);
    int prv_si = 0, prv_start = 0;
    while (!se.empty()) {
        int si = se.size(), start;
        auto it = se.begin();
        if (prv_si % 2 == prv_start % 2) {
            it++;
            start = 2;
        } else start = 1;
        while (it != se.end()) {
            cout << *it << ' ';
            it = se.erase(it);
            if (it != se.end()) it++;
        }
        prv_si = si, prv_start = start;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}