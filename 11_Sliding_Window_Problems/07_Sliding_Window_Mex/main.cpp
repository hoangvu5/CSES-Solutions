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
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    set<int> se; // Save numbers not in window
    map<int, int> ma;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i <= k; i++) se.insert(i);
    for (int i = 0; i < n; i++) {
        if (++ma[arr[i]] == 1) se.erase(arr[i]);
        if (i - k + 1 >= 0) {
            cout << *se.begin() << ' ';
            if (--ma[arr[i - k + 1]] == 0) 
                se.insert(arr[i - k + 1]);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}