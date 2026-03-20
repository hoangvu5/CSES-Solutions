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

const int K = 30;
vector<array<int, 2>> trie;
int cnt = 0;

void insert(int x) {
    int node = 0;
    for (int i = K; i >= 0; i--) {
        int y = (x >> i) & 1;
        if (!trie[node][y]) trie[node][y] = ++cnt;
        node = trie[node][y];
    }
}

int search(int x) {
    int ans = 0, node = 0;
    for (int i = K; i >= 0; i--) {
        int y = (x >> i) & 1;
        if (trie[node][y ^ 1]) {
            node = trie[node][y ^ 1];
            ans += (1 << i);
        } else {
            node = trie[node][y];
        }
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    trie.resize((n + 1) * K);
    int cur = 0, ans = 0;
    insert(0);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        cur ^= x;
        insert(cur);
        ans = max(ans, search(cur));
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}