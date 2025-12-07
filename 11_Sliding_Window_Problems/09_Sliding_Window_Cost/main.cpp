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

multiset<int> fi, se;
ll fisum, sesum;
vector<int> arr;

void del(int x) {
    if (x <= *fi.rbegin()) {
        fi.erase(fi.find(x));
        fisum -= x;
    } else {
        se.erase(se.find(x));
        sesum -= x;
    }
    if (fi.size() < se.size()) {
        fi.insert(*se.begin());
        fisum += *se.begin();
        sesum -= *se.begin();
        se.erase(se.begin());
    }
}

void ins(int x) {
    if (fi.empty() || x > *fi.rbegin()) {
        se.insert(x);
        sesum += x;
    } else {
        fi.insert(x);
        fisum += x;
    }
    if (se.size() > fi.size()) {
        fi.insert(*se.begin());
        fisum += *se.begin();
        sesum -= *se.begin();
        se.erase(se.begin());
    } else if (fi.size() > se.size() + 1) {
        se.insert(*fi.rbegin());
        sesum += *fi.rbegin();
        fisum -= *fi.rbegin();
        fi.erase(--fi.end());
    }
}

ll cost() {
    ll med = *fi.rbegin();
    return fi.size() * med - fisum + sesum - se.size() * med;
}

void solve() {
    int n, k; cin >> n >> k;
    arr.assign(n, 0);
    fisum = sesum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        ins(arr[i]);
        if (i - k + 1 >= 0) {
            cout << cost() << ' ';
            del(arr[i - k + 1]);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}