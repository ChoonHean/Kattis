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
inline void pr(const ordered_set &s) {
    for (const auto &t: s)pr(t);
    cout << nl;
}

template<typename T>
inline void pr(const unordered_set<T> &s) {
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
    int n, m;
    while (cin >> n >> m) {
        if (!n)break;
        vs a(n);
        reada(a);
        auto f = [&](char c, int i) -> bool {
            if (isdigit(c))return ((c - '0') >> i) & 1;
            return ((c - 'A' + 10) >> i) & 1;
        };//top 3, right 2, bottom 1, left 0
        vpii out;
        rep(j, 0, m) {
            if (!f(a[0][j], 3))out.eb(0, j);
            if (!f(a[n - 1][j], 1))out.eb(n - 1, j);
        }
        rep(i, 0, n) {
            if (!f(a[i][0], 0))out.eb(i, 0);
            if (!f(a[i][m - 1], 2))out.eb(i, m - 1);
        }
        vvvpii adj(n, vvpii(m));
        rep(i, 0, n)
            rep(j, 0, m) {
                if (i < n - 1 && !(f(a[i][j], 1) | f(a[i + 1][j], 3))) {
                    if (pair(i + 1, j) != out[0])adj[i][j].eb(i + 1, j);
                    if (pair(i, j) != out[0])adj[i + 1][j].eb(i, j);
                }
                if (j < m - 1 && !(f(a[i][j], 2) | f(a[i][j + 1], 0))) {
                    if (pair(i, j + 1) != out[0])adj[i][j].eb(i, j + 1);
                    if (pair(i, j) != out[0])adj[i][j + 1].eb(i, j);
                }
            }
        vvpii p(n, vpii(m, {-1, -1}));
        bool multi = 0;
        queue<pii> q({out[0]});
        p[out[0].first][out[0].second] = out[0];
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (const auto &[x, y]: adj[i][j]) {
                if (p[x][y].first != -1) {
                    if (pair(x, y) != p[i][j])multi = 1;
                } else q.push({x, y}), p[x][y] = {i, j};
            }
        }
        if (p[out[1].first][out[1].second].first == -1)pnl("NO SOLUTION");
        else {
            bool unreach = 0;
            rep(i, 0, n)rep(j, 0, m)if (p[i][j].first == -1)unreach = 1;
            if (unreach)pnl("UNREACHABLE CELL");
            else if (multi)pnl("MULTIPLE PATHS");
            else pnl("MAZE OK");
        }
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
    return 0;
}