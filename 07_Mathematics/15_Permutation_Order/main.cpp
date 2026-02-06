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

const int m = 21;
ll fact[m];

void solve() {
    fact[0] = 1;
    for (int i = 1; i < m; i++) {
        fact[i] = fact[i-1] * i;
    }

    int t; cin >> t;
    int q, n;
    while (t--) {
        cin >> q >> n;
        vector<int> p(n), nums(n);
        iota(nums.begin(), nums.end(), 1);
        if (q == 1) {
            // Find p(n, k)
            ll k; cin >> k; k--;
            for (int i = n - 1; i >= 0; i--) {
                int idx = k / fact[i];
                k -= idx * fact[i];
                cout << nums[idx] << ' ';
                nums.erase(nums.begin() + idx);
            }
            cout << '\n';
        } else {
            // Find k
            ll k = 1;
            for (int i = 0; i < n; i++) {
                cin >> p[i];
                int idx = 0;
                while (idx < n && nums[idx] < p[i]) idx++;
                nums.erase(nums.begin() + idx);
                k += idx * fact[n - i - 1];
            }
            cout << k << '\n';
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}