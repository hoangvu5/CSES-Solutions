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

#include <bits/extc++.h>
using namespace __gnu_pbds;

template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

void solve() {
    int n, k; cin >> n >> k;
    Tree<int> t;
    for (int i = 1; i <= n; i++) t.insert(i);
    int idx = k;
    while (t.size()) {
        idx %= t.size();
        int x = *t.find_by_order(idx);
        t.erase(x);
        cout << x << ' ';
        idx += k;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}