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
#define rep(a, n) for(int i=a;i<n;i++)
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

bool _ = true;
int r, c;
vs grid(10);
vector<vector<vi>> dp;

int f(int x, int y, int prev) {
    if (dp[x][y][prev] != -1)return dp[x][y][prev];
    if (grid[x][y] == '#')return dp[x][y][prev] = 0;
    int res = 0;
    if (y < c - 1)res += f(x, y + 1, 2);
    if (prev == 0) {
        if (x > 0)res += f(x - 1, y, 0);
    } else if (prev == 1) {
        if (x < r - 1)res += f(x + 1, y, 1);
    } else {
        if (x > 0)res += f(x - 1, y, 0);
        if (x < r - 1)res += f(x + 1, y, 1);
    }
    return dp[x][y][prev] = res;
}

inline void solve() {
    cin >> r >> c;
    if ((r | c) == 0) {
        _ = false;
        return;
    }
    rep(0, r)cin >> grid[i];
    dp.assign(r, vector<vi>(c, vi(3, -1)));
    dp[0][c - 1].assign(3, 1);
    pnl(f(r - 1, 0, 2));
}

int main() {
    int t = 1;
    //cin >> t;
    while (_) {
        solve();
    }
    return 0;
}