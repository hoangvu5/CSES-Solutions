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
    int m = 0;
    set<pair<int, int>> filled; // {end, room num}
    set<int> blank;
    vector<array<int, 3>> arr(n);
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1];
        arr[i][2] = i;
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        auto &[st, en, id] = arr[i];
        while (!filled.empty() && filled.begin()->first < st) {
            blank.insert(filled.begin()->second);
            filled.erase(filled.begin());
        }
        if (blank.empty()) blank.insert(++m);
        int num = *blank.begin();
        blank.erase(blank.begin());
        filled.insert({en, num});
        ans[id] = num;
    }
    cout << m << '\n';
    for (int i = 0; i < n; i++) cout << ans[i] << ' ';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}