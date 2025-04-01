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

const int p1 = 31, p2 = 17, mod2 = 998244353;

inline void computeRollingHash(string &s, vi &h, vi &power, int p) {                      // Overall: O(n)
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
    cin >> n;
    vi power1{1}, power2{1};
    vvi hash1(n), hash2(n);
    vs arr(n);
    set<pii> dict;
    rep(i, 0, n) {
        cin >> arr[i];
        string &s = arr[i];
        hash1[i].resize(sz(s));
        hash2[i].resize(sz(s));
        while (sz(power1) < sz(s))
            power1.pb(((ll) power1.back() * p1) % mod), power2.pb(((ll) power2.back() * p2) % mod);
        computeRollingHash(s, hash1[i], power1, p1);
        computeRollingHash(s, hash2[i], power2, p2);
        dict.emplace(hash1[i].back(), hash2[i].back());
    }
    vs res;
    rep(k, 0, n) {
        const string &s = arr[k];
        int m = sz(s);
        rep(i, 0, m) {
            int test = i ? ((ll) hash1[k][i - 1] * power1[m - 1 - i]) % mod : 0;
            if (i < m - 1)test = ((ll) test + hash_fast(i + 1, m - 1, hash1[k], power1)) % mod;
            int test2 = i ? ((ll) hash2[k][i - 1] * power2[m - 1 - i]) % mod : 0;
            if (i < m - 1)test2 = ((ll) test2 + hash_fast(i + 1, m - 1, hash2[k], power2)) % mod;
            if (dict.contains({test, test2})) {
                res.pb(s);
                break;
            }
        }
    }
    if (sz(res))pr(res);
    else pr("NO TYPOS");
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