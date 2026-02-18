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
    double ans = 0;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int k;
            if (arr[i] <= arr[j]) k = (arr[i] * (arr[i] - 1)) / 2;
            else k = (arr[j] * (arr[j] - 1)) / 2 + (arr[i] - arr[j]) * arr[j];
            ans += (double)k / (arr[i] * arr[j]);
        }
    }
    cout << fixed << setprecision(6) << ans << '\n';
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}