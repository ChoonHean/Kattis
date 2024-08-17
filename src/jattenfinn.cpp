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

int n;
vi arr;
vector<map<int, pii>> dp;

pii f(int left, int right) {
    if (dp[left].contains(right))return dp[left][right];
    auto it = dp[left].upper_bound(right);
    if (it != dp[left].begin()) {
        it--;
        if (it->second.second >= right)return dp[left][right] = it->second;
    }
    int wt = (right - left + 1) * 500;
    if (left > 0 && right < n - 1) {
        if (arr[left - 1] >= wt) {
            if (arr[right + 1] >= wt)return dp[left][right] = pair(left, right);
            else return dp[left][right] = f(left, right + 1);
        } else if (arr[right + 1] >= wt) {
            return dp[left][right] = f(left - 1, right);
        } else return dp[left][right] = f(left - 1, right + 1);
    } else if (left == 0) {
        if (right == n - 1)return dp[left][right] = pair(left, right);
        if (arr[right + 1] < wt)return dp[left][right] = f(left, right + 1);
        else return dp[left][right] = pair(left, right);
    } else {
        if (arr[left - 1] >= wt)return dp[left][right] = pair(left, right);
        else return dp[left][right] = f(left - 1, right);
    }
}

inline void solve() {
    cin >> n;
    arr.resize(n);
    readarr(n, arr);
    rep(0, n)arr[i] -= 1000;
    dp.resize(n);
    int res = 0, pillar = 0;
    rep(0, n) {
        auto [x, y] = f(i, i);
        if ((y - x + 1) > res) {
            res = y - x + 1;
            pillar = i;
        }
    }
    cout << res << ' ' << pillar;
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