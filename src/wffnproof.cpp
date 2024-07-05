#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
const int inf = 1e9;
const int mod = 1e9 + 7;
#define all(a) a.begin(),a.end()
#define read(n) vi arr(n);for(int i=0;i<n;i++)cin>>arr[i]
#define readarr(n, arr) for(int i=0;i<n;i++)cin>>arr[i]
#define forloop(a, n) for(int i=a;i<n;i++)
#define nl "\n"

template<typename T>
inline void print(T it) {
    for (auto i = it.begin(); i != it.end(); i++) {
        cout << *i << " ";
    }
    cout << nl;
}

template<typename T>
inline void print_p(T v) {
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << "(" << (*it).first << "," << (*it).second << ") ";
    }
    cout << nl;
}

bool b = true;

inline void solve() {
    string s;
    cin >> s;
    if (s == "0") {
        b = false;
        return;
    }
    vc operators, operands;
    int n = 0;
    for (char c: s) {
        if (isupper(c)) {
            if (c == 'N')n++;
            else operators.push_back(c);
        } else operands.push_back(c);
    }
    if (operands.size() == 0) {
        cout << "no WFF possible" << nl;
        return;
    }
    string res = string(n, 'N') + operands.back();
    operands.pop_back();
    while (!operands.empty() && !operators.empty()) {
        res.insert(0, 1, operands.back());
        res.insert(0, 1, operators.back());
        operands.pop_back();
        operators.pop_back();
    }
    cout << res << nl;
}

int main() {
    int t = 1;
    //cin >> t;
    while (b) {
        solve();
    }
    return 0;
}