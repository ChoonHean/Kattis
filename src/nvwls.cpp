#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<pll> vpll;
typedef vector<pdd> vpdd;
typedef tree<pair<int, int>, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>
        ordered_set;
const int inf = 1e9;
const ll llinf = 4e18;
const int mod = 1e9 + 7;
const double EPS = 1e-9;
#define all(a) a.begin(),a.end()
#define read(n) vi arr(n);for(int&_:arr)cin>>_
#define readarr(arr) for(auto&_:arr)cin>>_
#define readpair(arr) for(auto&[_,__]:arr)cin>>_>>__
#define rep(i, a, n) for(int i=a;i<n;i++)
#define repr(i, a, n) for(int i=a;i>=n;i--)
#define nl "\n"
#define sz(v) ((int)v.size())
#define PQ priority_queue
#define hmap unordered_map
#define hset unordered_set
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define clz(i) __builtin_clz(i)
#define ctz(i) __builtin_ctz(i)
#define popcount(i) __builtin_popcount(i)
#define lsb(i) (i&-i)
mt19937_64 rnd(time(0));


template<typename T>
inline void pr(const T &t) { cout << t << ' '; }

template<typename T, typename U>
inline void pr(const pair<T, U> &pa) {
    cout << '(';
    pr(pa.first);
    cout << ',';
    pr(pa.second);
    cout << ") ";
}

template<typename... Args>
inline void pr(const tuple<Args...> &tup) {
    apply([](const auto &... args) {
        pr('[');
        (pr(args), ...);
        pr(']');
    }, tup);
}

template<typename T>
inline void pr(const vector<T> &v) {
    for (auto i: v) pr(i);
    cout << nl;
}

template<typename T>
inline void pr(const set<T> &s) {
    for (auto t: s)pr(t);
    cout << nl;
}

template<typename T>
inline void pr(const unordered_set<T> &s) {
    for (auto t: s)pr(t);
    cout << nl;
}

template<typename T, typename U>
inline void pr(const map<T, U> &m) {
    for (auto [t, u]: m) {
        cout << '(';
        pr(t);
        pr('-');
        pr(u);
        pr(')');
    }
    cout << nl;
}

template<typename T, typename U>
inline void pr(const unordered_map<T, U> &m) {
    for (auto [t, u]: m) {
        cout << '(';
        pr(t);
        pr('-');
        pr(u);
        pr(')');
    }
    cout << nl;
}

template<typename T>
inline void pr(const queue<T> &q) {
    queue<T> copy(q);
    while (!copy.empty()) {
        pr(copy.front());
        copy.pop();
    }
    cout << nl;
}

template<typename T>
inline void pr(const stack<T> &s) {
    stack<T> copy(s);
    while (!copy.empty()) {
        pr(copy.top());
        copy.pop();
    }
    cout << nl;
}

template<typename T>
inline void pr(const deque<T> &q) {
    deque<T> copy(q);
    while (!copy.empty()) {
        pr(copy.top());
        copy.pop();
    }
    cout << nl;
}

template<typename T>
inline void pr(const PQ<T> &pq) {
    PQ<T> copy(pq);
    vector<T> arr;
    while (!copy.empty()) {
        arr.pb(copy.top());
        copy.pop();
    }
    pr(arr);
    cout << nl;
}

template<typename T>
inline void pr(const PQ<T, vector<T>, greater<T>> &pq) {
    auto copy(pq);
    vector<T> arr;
    while (!copy.empty()) {
        arr.pb(copy.top());
        copy.pop();
    }
    pr(arr);
    cout << nl;
}

template<typename T>
inline void pnl(const T &t) {
    pr(t);
    cout << nl;
}

template<typename... Args>
void pr(const Args &... args) {
    (pr(args), ...);
    cout << nl;
}

inline bool vowel(char c) { return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'; }

const int p = 131;

inline void computePower(vi &power) {
    power[0] = 1;                                    // compute p^i % M
    for (int i = 1; i < (int) power.size(); ++i)                    // O(n)
        power[i] = ((ll) power[i - 1] * p) % mod;
}

inline void computeRollingHash(string &s, vi &h, vi &power) {                      // Overall: O(n)
    h[0] = 0;
    for (int i = 0; i < (int) h.size(); ++i) {                  // O(n)
        if (i != 0) h[i] = h[i - 1];                   // rolling hash
        h[i] = (((ll) h[i] * p) % mod + s[i]) % mod;
    }
}

inline int hash_fast(int L, int R, vi &h, vi &power) {                    // O(1) hash of any substr
    if (L == 0) return h[R];                       // h is the prefix hashes
    int ans = 0;
    ans = (h[R] - (ll) h[L - 1] * power[R - L + 1]) % mod;           // compute differences
    return (ans + mod) % mod;
}

inline void solve() {
    int n;
    string s;
    cin >> n;
    hmap<string, string> orig(n);
    set<int> l;
    rep(i, 0, n) {
        cin >> s;
        string r;
        rep(j, 0, sz(s))if (!vowel(s[j]))r.pb(s[j]);
        if (orig.contains(r)) {
            int prev = sz(orig[r]);
            if (sz(s) > prev)orig[r] = s;
        } else orig[r] = s;
        l.insert(sz(r));
    }
    cin >> s;
    n = sz(s);
    vi power(n), h(n);
    computePower(power);
    computeRollingHash(s, h, power);
    vpii have{{INT_MAX, 0}};
    for (const auto &[a, b]: orig) {
        ll cur = 0;
        if (sz(a) > n)continue;
        rep(i, 0, sz(a))cur = (cur * p) % mod + a[i];
        have.pb({cur, sz(b) - sz(a)});
    }
    sort(all(have));
    vi lens;
    vpii dp(n, {-2, -2});
    for (const int &i: l) {
        lens.pb(i);
        int cur = hash_fast(0, i - 1, h, power);
        auto &[val, cnt] = *lb(all(have), pair(cur, 0));
        if (val == cur)dp[i - 1] = {cnt, -1};
    }
    rep(i, 1, n) {
        for (const int &j: lens) {
            if (j > i)break;
            if (dp[i - j].second == -2)continue;
            int cur = hash_fast(i - j + 1, i, h, power);
            auto &[val, cnt] = *lb(all(have), pair(cur, 0));
            if (val == cur)dp[i] = max(dp[i], {dp[i - j].first + cnt, i - j});
        }
    }
    vi res{n};
    int cur = dp.back().second;
    while (cur != -1)res.pb(cur), cur = dp[cur].second;
    res.pb(-1);
    reverse(all(res));
    rep(i, 1, sz(res))pr(orig[s.substr(res[i - 1] + 1, res[i] - res[i - 1])]);
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(10);
    int cases = 1;
//    cin >> cases;
    while (cases--) solve();
    return 0;
}