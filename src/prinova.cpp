#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


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

inline void solve() {
    int n, l, r;
    cin >> n;
    read(n);
    cin >> l >> r;
    sort(all(a));
    int res = 0, mx = -1;
    if (l & 1) {
        int mn = inf;
        rep(i, 0, n)mn = min(mn, abs(a[i] - l));
        mx = mn;
        res = l;
    } else {
        int mn = inf;
        rep(i, 0, n)mn = min(mn, abs(a[i] - l - 1));
        mx = mn;
        res = l + 1;
    }
    if (r & 1) {
        int mn = inf;
        rep(i, 0, n)mn = min(mn, abs(a[i] - r));
        if (mn > mx)mx = mn, res = r;
    } else {
        int mn = inf;
        rep(i, 0, n)mn = min(mn, abs(a[i] - r + 1));
        if (mn > mx)mx = mn, res = r - 1;
    }
    rep(i, 1, n) {
        if (a[i] + a[i - 1] >> 1 & 1) {
            int j = a[i] + a[i - 1] >> 1;
            if (j < l || j > r)continue;
            if (a[i] - j > mx)mx = a[i] - j, res = j;
        } else {
            int j = (a[i] + a[i - 1] >> 1) - 1;
            if (l <= j && j <= r) {
                if (j - a[i - 1] > mx)mx = l - a[i - 1], res = j;
            }
            j += 2;
            if (j < l || j > r)continue;
            if (a[i] - j > mx)mx = a[i] - j, res = j;
        }
    }
    cout << res;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(2);
    int cases = 1;
//    cin >> cases;
    while (cases--) solve();
    return 0;
}