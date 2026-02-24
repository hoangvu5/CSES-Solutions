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
    int n; ll x; cin >> n >> x;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    unordered_map<ll, pair<int, int>> ma;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ll sum = arr[i] + arr[j];
            ll need = x - sum;
            if (ma.count(need)) {
                auto &[k, l] = ma[need];
                if (k != i && k != j && l != i && l != j) {
                    cout << i+1 << ' ' << j+1 << ' ' << k+1 << ' ' << l+1 << '\n';
                    return;
                }
            }
        }
        for (int j = 0; j < i; j++) {
            ma[arr[i] + arr[j]] = {j, i};
        }
    }
    cout << "IMPOSSIBLE\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}