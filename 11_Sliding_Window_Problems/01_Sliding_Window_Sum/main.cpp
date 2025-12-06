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

int arr[10000001];

void solve() {
    int n, k; cin >> n >> k;
    int x, a, b, c; cin >> x >> a >> b >> c;
    arr[1] = x;
    for (int i = 2; i <= n; i++) {
        x = ((1ll * x * a) % c + b) % c;
        arr[i] = x;
    }
    ll sum = 0;
    ll ans = 0;
    for (int i = 1; i < k; i++) {
        sum += arr[i];
    }
    for (int i = k; i <= n; i++) {
        sum += arr[i];
        ans ^= sum;
        sum -= arr[i - k + 1];
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}