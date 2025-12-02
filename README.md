# CSES Problem Set C++ Solutions

This repository contains accepted C++ Solutions for CSES Problems. WIP.

## Snippets

Compile command:

```bash
g++ -O2 -Wall -Wconversion -Wfatal-errors -fsanitize=address -g -std=c++17 -fsanitize=undefined,address main.cpp -o main && ./main < input.txt > output.txt
```

Code template:
```cpp
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
    
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
```

Interactive judge template:
```cpp
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

bool check(auto &a, auto &b) {
    return a == b;
}

void solve() {
    string type;
    for (int i = 0; i < 10000; i++) {
        cin >> type;
        if (type == "?") {
            
        } else {
            if (check()) {
                cout << "AC" << endl;
            } else {
                cout << "WA" << endl;
            }
            return;
        }
    }

    cin >> type;
    if (type != "!") {
        cout << "WA" << endl;
    } else {
        if (check()) {
            cout << "AC" << endl;
        } else {
            cout << "WA" << endl;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
```