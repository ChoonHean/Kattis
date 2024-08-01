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
#define range(a, n) for(int i=a;i<n;i++)
#define nl "\n"
#define sz(v) ((int)v.size())
#define pb push_back

template<typename T>
inline void p(T t) { cout << t << ' '; }

template<typename T>
inline void pnl(T t) {
    p(t);
    cout << nl;
}

template<typename T, typename U>
inline void p(pair<T, U> pa) {
    cout << '(';
    p(pa.first);
    cout << ',';
    p(pa.second);
    cout << ") ";
}

template<typename T>
inline void p(vector<T> v) {
    for (auto i: v) p(i);
    cout << nl;
}

template<typename T>
inline void p(vector<vector<T>> v) {
    for (auto row: v) p(row);
}

template<typename T>
inline void p(set<T> s) {
    for (auto t: s)p(t);
    cout << nl;
}

template<typename T>
inline void p(unordered_set<T> s) {
    for (auto t: s)p(t);
    cout << nl;
}

template<typename T, typename U>
inline void p(map<T, U> m) {
    for (auto t: m)p(t);
    cout << nl;
}

template<typename T, typename U>
inline void p(unordered_map<T, U> m) {
    for (auto t: m)p(t);
    cout << nl;
}

template<typename T>
inline void p(queue<T> q) {
    queue<T> copy(q);
    while (!copy.empty()) {
        p(copy.front());
        copy.pop();
    }
    cout << nl;
}

template<typename T>
inline void p(stack<T> s) {
    stack<T> copy(s);
    while (!copy.empty()) {
        p(copy.top());
        copy.pop();
    }
    cout << nl;
}

void solve() {
    string s, p;
    int n;
    cin >> p >> n;
    while (n--) {
        cin >> s;
        if (p[0] != '*')if (p[0] != s[0])continue;
        vector<vb> dp(sz(s), vb(sz(p)));
        dp[0][0] = 1;
        if (p[0] == '*') {
            range(1, sz(s))dp[i][0] = 1;
        }
        bool can = true;
        for (int j = 1; j < sz(p); j++) {
            if (p[j] == '*') {
                dp[0][j] = dp[0][j - 1];
            } else {
                if (p[j] == s[0]) {
                    if (!can)break;
                    dp[0][j] = dp[0][j - 1];
                    can = false;
                }
            }
        }
        range(1, sz(s)) {
            for (int j = 1; j < sz(p); j++) {
                if (p[j] == '*') {
                    dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j - 1] & (s[i] == p[j]);
                }
            }
        }
        if (dp.back().back())pnl(s);
    }
}

int main() {
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}