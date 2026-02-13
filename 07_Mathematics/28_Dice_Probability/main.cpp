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
    int n, a, b; cin >> n >> a >> b;
    vector<double> prob(6 * n + 1, 0);
    prob[0] = 1;
    for (int cnt = 1; cnt <= n; cnt++) {
        for (int i = 6 * cnt; i >= cnt; i--) {
            prob[i] = 0;
            for (int j = i - 1; j >= max(0, i - 6); j--) {
                prob[i] += prob[j] / 6;
            }
        }
        for (int i = cnt - 1; i >= 0; i--) prob[i] = 0;
    }
    double sum = 0;
    for (int i = a; i <= b; i++) {
        sum += prob[i];
    }
    cout << fixed << setprecision(6) << accumulate(prob.begin() + a, prob.begin() + b + 1, 0.0) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}