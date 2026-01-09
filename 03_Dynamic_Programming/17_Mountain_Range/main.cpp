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
    vector<int> arr(n);
    vector<pair<int, int>> pai;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        pai.push_back({arr[i], i});
    }
    sort(pai.begin(), pai.end(), greater<>());
    set<int> ser;
    set<int, greater<int>> sel;
    vector<int> dp(n, 0);
    queue<int> qu;
    for (int i = 0; i < n; i++) {
        auto [val, idx] = pai[i];
        while (!qu.empty() && arr[qu.front()] > val) {
            sel.insert(qu.front());
            ser.insert(qu.front());
            qu.pop();
        }
        set<int>::iterator l, r;
        l = sel.lower_bound(idx);
        r = ser.lower_bound(idx);
        int il = (l == sel.end() ? 0 : dp[*l]);
        int ir = (r == ser.end() ? 0 : dp[*r]);
        dp[idx] = max(il, ir) + 1;
        qu.push(idx);
    }
    cout << *max_element(dp.begin(), dp.end());
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}