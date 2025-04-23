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
typedef pair<double, double> pdd;
typedef pair<double, int> pdi;
typedef pair<int, double> pid;
typedef pair<string, int> psi;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<pll> vpll;
typedef vector<pdd> vpdd;
typedef tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>
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
void pr(const PQ<T, vector<T>, greater<>> &v);

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
inline void pr(const unordered_set<T> &s) {
    for (const auto &t: s)pr(t);
    cout << nl;
}

template<typename T, typename U>
inline void pr(const map<T, U> &m) {
    for (const auto &[t, u]: m) {
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
inline void pr(const PQ<T, vector<T>, greater<>> &pq) {
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

inline int nextp(int n) {
    int t = n | (n - 1);
    return (t + 1) | (((~t & -~t) - 1) >> (countr_zero((ull) n) + 1));
}

vvi adj(20, vi(20));
vvi dp1(18, vi(1 << 18, inf));
vvi dp2(dp1);

inline void solve() {
    int n, m, u, v, w, t = 1;
    while (cin >> n >> m) {
        rep(i, 0, n)rep(j, i + 1, n)adj[i][j] = adj[j][i] = inf;
        rep(i, 0, m) {
            cin >> u >> v >> w;
            u = (u - 1 + n) % n;
            v = (v - 1 + n) % n;
            adj[u][v] = adj[v][u] = w;
        }
        rep(k, 0, n)rep(i, 0, n)rep(j, 0, n)adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
        if (n == 3) {
            cout << "Case " << t++ << ": " << (adj[2][0] + adj[1][0] << 1) << nl;
            continue;
        }
        const int l = n - 2, N = 1 << l;
        rep(i, 0, l)fill(dp1[i].begin(), dp1[i].begin() + N, inf), fill(dp2[i].begin(), dp2[i].begin() + N, inf);
        rep(i, 0, l)dp1[i][1 << i] = adj[n - 1][i];
        rep(i, 1, N)rep(j, 0, l) {
                if (!((i >> j) & 1))continue;
                rep(k, 0, l) {
                    if ((i >> k) & 1)continue;
                    int next = i | (1 << k);
                    dp1[k][next] = min(dp1[k][next], dp1[j][i] + adj[j][k]);
                }
            }
        rep(i, 0, l)dp2[i][1 << i] = adj[n - 2][i];
        rep(i, 1, N)rep(j, 0, l) {
                if (!((i >> j) & 1))continue;
                rep(k, 0, l) {
                    if ((i >> k) & 1)continue;
                    int next = i | (1 << k);
                    dp2[k][next] = min(dp2[k][next], dp2[j][i] + adj[j][k]);
                }
            }
        int h = l >> 1, res = INT_MAX, all = N - 1;
        for (int i = (1 << h) - 1; i < N; i = nextp(i)) {
            int a = inf, b = inf;
            for (uint mask = i; mask; mask -= lsb(mask)) {
                int k = countr_zero(mask);
                a = min(a, dp1[k][i] + dp2[k][all ^ i | (1 << k)]);
                b = min(b, dp2[k][i | (1 << k)] + dp1[k][all ^ i | (1 << k)]);
            }
            res = min(res, a + b);
        }
        cout << "Case " << t++ << ": " << res << nl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(10);
    int cases = 1;
//    cin >> cases;
    while (cases--) solve();
    int cnt = 0;
    return 0;
}