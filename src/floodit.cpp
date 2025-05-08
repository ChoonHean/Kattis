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

template<typename T>
inline void pr(const PQ<T> &pq1) {
    PQ<T> copy(pq1);
    vector<T> arr;
    while (!copy.empty()) {
        arr.pb(copy.top());
        copy.pop();
    }
    pr(arr);
    cout << nl;
}

template<typename T>
inline void pr(const PQ<T, vector<T>, greater<>> &pq1) {
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
    int n;
    cin >> n;
    vvi a(n);
    string s;
    rep(i, 0, n) {
        cin >> s;
        for (const char &c: s)a[i].pb(c - '1');
    }
    vi res(6);
    queue<pii> q1({{0, 0}}), q2;
    vvb visit(n, vb(n));
    visit[0][0] = 1;
    int b = a[0][0];
    while (!q1.empty()) {
        auto [x, y] = q1.front();
        q1.pop();
        if (x && a[x - 1][y] == b && !visit[x - 1][y])visit[x - 1][y] = 1, q1.emplace(x - 1, y), a[x - 1][y] = 6;
        if (x < n - 1 && a[x + 1][y] == b && !visit[x + 1][y])
            visit[x + 1][y] = 1, q1.emplace(x + 1, y), a[x + 1][y] = 6;
        if (y && a[x][y - 1] == b && !visit[x][y - 1])visit[x][y - 1] = 1, q1.emplace(x, y - 1), a[x][y - 1] = 6;
        if (y < n - 1 && a[x][y + 1] == b && !visit[x][y + 1])
            visit[x][y + 1] = 1, q1.emplace(x, y + 1), a[x][y + 1] = 6;
    }
    a[0][0] = 6;
    while (true) {
        vi cnts(6);
        q1.emplace(0, 0);
        visit.assign(n, vb(n));
        visit[0][0] = 1;
        while (!q1.empty()) {
            auto [x, y] = q1.front();
            q1.pop();
            for (auto [nx, ny]: {pair(x - 1, y), pair(x + 1, y), pair(x, y - 1), pair(x, y + 1)}) {
                if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
                if (visit[nx][ny])continue;
                if (a[nx][ny] == 6)q1.emplace(nx, ny);
                else q2.emplace(nx, ny);
                visit[nx][ny] = 1;
            }
        }
        while (!q2.empty()) {
            auto [x, y] = q2.front();
            q2.pop();
            cnts[a[x][y]]++;
            q1.emplace(x, y);
            for (auto [nx, ny]: {pair(x - 1, y), pair(x + 1, y), pair(x, y - 1), pair(x, y + 1)}) {
                if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
                if (visit[nx][ny])continue;
                if (a[nx][ny] == a[x][y])q2.emplace(nx, ny), visit[nx][ny] = 1;
            }
        }
        int mx = 0, idx = 0;
        rep(i, 0, 6)if (cnts[i] > mx)mx = cnts[i], idx = i;
        if (!mx)break;
        res[idx]++;
        while (!q1.empty()) {
            auto [x, y] = q1.front();
            q1.pop();
            if (a[x][y] == idx)a[x][y] = 6;
        }
    }
    pnl(accumulate(all(res), 0));
    pr(res);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(10);
    int cases = 1;
    cin >> cases;
    while (cases--) solve();
    return 0;
}