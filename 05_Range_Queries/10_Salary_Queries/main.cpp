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

#include <bits/extc++.h> /** keep-include */
using namespace __gnu_pbds;

template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> arr(n + 1);
    Tree<pii> tree;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        tree.insert({arr[i], i});
    }
    while (q--) {
        char type; cin >> type;
        if (type == '?') {
            int a, b; cin >> a >> b;
            cout << tree.order_of_key({b + 1, 0}) - tree.order_of_key({a, 0}) << '\n';
        } else {
            int k, x; cin >> k >> x;
            tree.erase(tree.find({arr[k], k}));
            arr[k] = x;
            tree.insert({arr[k], k});
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}