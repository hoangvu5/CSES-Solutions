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
    stack<int> st;
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        if (!st.empty()) ans[i] = st.top() + 1;
        st.push(i);
        cout << ans[i] << ' ';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}