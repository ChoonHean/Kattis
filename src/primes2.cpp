#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <cmath>

using namespace std;
using namespace __gnu_pbds;
typedef unsigned int uint;
typedef unsigned long long ull;
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
typedef tuple<int, int, int> ti;
typedef vector<ti> vti;
typedef pair<double, double> pdd;
typedef pair<double, int> pdi;
typedef pair<int, double> pid;
typedef vector<pid> vpid;
typedef vector<vpid> vvpid;
typedef pair<string, int> psi;
typedef pair<int, ll> pil;
typedef vector<pil> vpil;
typedef vector<vpil> vvpil;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<vvpii> vvvpii;
typedef vector<pll> vpll;
typedef vector<pdd> vpdd;
typedef tree<pii, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>
        ordered_set;
const int inf = 1e8;
const ll llinf = 4e18;
const int mod = 1e9 + 7;
const double eps = 1e-9;
#define all(a) a.begin(),a.end()
#define read(n) vi a(n);for(int&_:a)cin>>_
#define reada(arr) for(auto&_:arr)cin>>_
#define readpair(arr) for(auto&[_,__]:arr)cin>>_>>__
#define readtup(arr) for(auto&[_,__,___]:arr)cin>>_>>__>>___
#define read2d(arr) for(auto&_:arr)reada(_)
#define rep(i, a, n) for(int i=a;i<n;++i)
#define repr(i, a, n) for(int i=a;i>=n;--i)
#define nl "\n"
#define sz(v) ((int)v.size())
#define PQ priority_queue
#define hmap unordered_map
#define hset unordered_set
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define lsb(i) (i&-i)
mt19937_64 rnd(time(0));

template<typename T>
inline bool chmin(T &a, T &b) {
    if (a > b) {
        swap(a, b);
        return true;
    } else return false;
}

template<typename T>
inline bool chmax(T &a, T &b) {
    if (a < b) {
        swap(a, b);
        return true;
    } else return false;
}

template<typename T>
inline T ceildiv(T a, T b) {
    return (a + b - 1) / b;
}

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
    for (const auto &i: v) pr(i);
    cout << nl;
}

template<typename T>
inline void pr(const set<T> &s) {
    for (const auto &t: s)pr(t);
    cout << nl;
}

template<typename T>
inline void pr(const multiset<T> &s) {
    for (const auto &t: s)pr(t);
    cout << nl;
}

template<typename T>
inline void pr(const ordered_set &s) {
    for (const auto &t: s)pr(t);
    cout << nl;
}

template<typename T, typename H>
inline void pr(const unordered_set<T, H> &s) {
    for (const auto &t: s)pr(t);
    cout << nl;
}

template<typename T, typename U, typename H>
inline void pr(const map<T, U, H> &m) {
    for (const auto &[t, u]: m) {
        cout << '(';
        pr(t);
        pr('-');
        pr(u);
        pr(')');
    }
    cout << nl;
}

template<typename T, typename U, typename H>
inline void pr(const unordered_map<T, U, H> &m) {
    for (const auto &[t, u]: m) {
        cout << '(';
        pr(t);
        pr('-');
        pr(u);
        pr(')');
    }
    cout << nl;
}

template<typename T>
inline void pr(const queue<T> &q1) {
    queue<T> copy(q1);
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
inline void pr(const deque<T> &q1) {
    deque<T> copy(q1);
    while (!copy.empty()) {
        pr(copy.top());
        copy.pop();
    }
    cout << nl;
}

template<typename T, typename C>
inline void pr(const PQ<T, vector<T>, C> &pq1) {
    auto copy(pq1);
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

inline ll binpow2(ll n, ll p, ll m) {
    __int128 res = 1, a = n;
    while (p) {
        if (p & 1)res = (res * a) % m;
        a = (a * a) % m;
        p >>= 1;
    }
    return res;
}

inline bool is_composite(ll n, ll a, ll d, int s) {
    __int128 x = binpow2(a, d, n);
    if (x == 1 || x == n - 1)return false;
    rep(i, 0, s) {
        x = (x * x) % n;
        if (x == n - 1)return false;
    }
    return true;
}

inline bool miller_rabin(ll n) {
    if (n < 2)return false;
    vi tests{2, 3, 5, 7};
    if (n >= 3215031751LL) tests = {2, 3, 5, 7, 11};
    ll d = n - 1;
    int s = 0;
    while (!(d & 1))d >>= 1, s++;
    for (const int &a: tests) {
        if (a > n - 1)break;
        if (is_composite(n, a, d, s))return false;
    }
    return true;
}


inline void solve() {
    string s;
    cin >> s;
    char mx = 0;
    for (const char &c: s)mx = max(mx, c);
    int n = 0, d = 0;
    if (mx < '2')n += miller_rabin(stoll(s, nullptr, 2)), d++;
    if (mx < '8')n += miller_rabin(stoll(s, nullptr, 8)), d++;
    if (mx < 'A')n += miller_rabin(stoll(s, nullptr, 10)), d++;
    n += miller_rabin(stoll(s, nullptr, 16)), d++;
    int g = gcd(n, d);
    printf("%d/%d\n", n / g, d / g);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(10);
    int cases = 1;
    cin >> cases;
    while (cases--)solve();
    return 0;
}