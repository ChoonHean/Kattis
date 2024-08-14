#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pdd> vpdd;
const int inf = 1e9;
const int mod = 1e9 + 7;
#define all(a) a.begin(),a.end()
#define read(n) vi arr(n);for(int i=0;i<n;i++)cin>>arr[i]
#define readarr(n, arr) for(int i=0;i<n;i++)cin>>arr[i]
#define rep(a, n) for(int i=a;i<n;i++)
#define nl "\n"
#define sz(v) ((int)v.size())
#define pb push_back
#define clz(i) __builtin_clz(i)
#define ctz(i) __builtin_ctz(i)
#define popcount(i) __builtin_popcount(i)
#define lsb(i) i&-i

template<typename T>
inline void pr(T t) { cout << t << ' '; }

template<typename T>
inline void pnl(T t) {
    pr(t);
    cout << nl;
}

template<typename T, typename U>
inline void pr(pair<T, U> pa) {
    cout << '(';
    pr(pa.first);
    cout << ',';
    pr(pa.second);
    cout << ") ";
}

template<typename T>
inline void pr(vector<T> v) {
    for (auto i: v) pr(i);
    cout << nl;
}

template<typename T>
inline void pr(set<T> s) {
    for (auto t: s)pr(t);
    cout << nl;
}

template<typename T>
inline void pr(unordered_set<T> s) {
    for (auto t: s)pr(t);
    cout << nl;
}

template<typename T, typename U>
inline void pr(map<T, U> m) {
    for (auto t: m)pr(t);
    cout << nl;
}

template<typename T, typename U>
inline void pr(unordered_map<T, U> m) {
    for (auto t: m)pr(t);
    cout << nl;
}

template<typename T>
inline void pr(queue<T> q) {
    queue<T> copy(q);
    while (!copy.empty()) {
        pr(copy.front());
        copy.pop();
    }
    cout << nl;
}

template<typename T>
inline void pr(stack<T> s) {
    stack<T> copy(s);
    while (!copy.empty()) {
        pr(copy.top());
        copy.pop();
    }
    cout << nl;
}

const int N = 51;
vector<vl> ncr(N, vl(N, 1));
vd pw(N);

inline void solve() {
    int n, a, b, w;
    cin >> n >> a >> b >> w;
    int needed = (n >> 1) + 1, open = n - a - b;
    double res = 0;
    if (a >= needed) {
        pnl("GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!");
        return;
    }
    rep(needed, open + a + 1)res += ncr[open][i - a] * pw[open];
    if (res == 0)pnl("RECOUNT!");
    else if (res * 100 > w)pnl("GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!");
    else pnl("PATIENCE, EVERYONE!");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    rep(2, N)for (int j = 1; j < i; j++)ncr[i][j] = ncr[i - 1][j] + ncr[i - 1][j - 1];
    pw[1] = 0.5;
    rep(2, N)pw[i] = pw[i - 1] / 2;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}