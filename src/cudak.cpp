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
//const int inf = 1e9;
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
#define LSOne(i) (i&-i)

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

ll l, r;
int sum, n;
vvl dp;
vl pow10;

ll f(int i, ll val, int s) {
    if (s > sum)return 0;
    if (i == n)return s == sum;
    if (val == r / pow10[i]) {
        ll res = 0;
        for (int j = 0; j <= (r / (pow10[i] / 10)) % 10; j++)res += f(i + 1, val * 10 + j, s + j);
        return res;
    }
    if (dp[i][s] != -1)return dp[i][s];
    ll res = 0;
    for (int j = 0; j < 10; j++)res += f(i + 1, val * 10 + j, s + j);
    return dp[i][s] = res;
}

inline void solve() {
    cin >> l >> r >> sum;
    string s = to_string(r);
    n = sz(s);
    dp.assign(n, vl(sum + 1, -1));
    pow10.resize(n + 1);
    pow10.back() = 1;
    for (int i = n - 1; i >= 0; i--)pow10[i] = pow10[i + 1] * 10;
    ll res = f(0, 0, 0);
    ll lo = l, hi = r;
    r = l - 1;
    res -= f(0, 0, 0);
    pnl(res);
    while (lo < hi) {
        ll mid = r = lo + hi + 1 >> 1;
        ll cnt = f(0, 0, 0);
        r = lo;
        cnt -= f(0, 0, 0);
        if (cnt)hi = mid - 1;
        else lo = mid;
    }
    pnl(lo + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}