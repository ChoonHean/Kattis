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
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<pll> vpll;
typedef vector<pdd> vpdd;
typedef tree<ti, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>
        ordered_set;
const int inf = 1e9;
const ll llinf = 1e18;
const int mod = 1e9 + 7;
const double eps = 1e-9;
#define all(a) a.begin(),a.end()
#define read(n) vi a(n);for(int&_:a)cin>>_
#define reada(arr) for(auto&_:arr)cin>>_
#define readpair(arr) for(auto&[_,__]:arr)cin>>_>>__
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

inline void solve() {
    int n, m;
    cin >> n >> m;
    vvi a(n, vi(m));
    for (auto &v: a)reada(v);
    vi b;
    rep(i, 0, n)rep(j, 0, m)if (a[i][j] != -1)b.pb(a[i][j]);
    sort(all(b));
    if (b.empty()) {
        cout << 0;
        return;
    }
    int pt = 0, cur = sz(b);
    for (int i = 0, j = 0; i < n;) {
        int c = 0;
        for (int k = i, l = j; k < n && l >= 0; k++, l--)if (a[k][l] != -1)c++;
        for (int k = i, l = j; k < n && l >= 0; k++, l--)if (a[k][l] >= b[pt] && a[k][l] <= b[pt + c - 1])cur--;
        pt += c;
        if (j == m - 1)i++;
        else j++;
    }
    int res = cur;
    cur = sz(b);
    pt = 0;
    for (int i = n - 1, j = m - 1; j >= 0;) {
        int c = 0;
        for (int k = i, l = j; k < n && l >= 0; k++, l--)if (a[k][l] != -1)c++;
        for (int k = i, l = j; k < n && l >= 0; k++, l--)if (a[k][l] >= b[pt] && a[k][l] <= b[pt + c - 1])cur--;
        pt += c;
        if (i == 0)j--;
        else i--;
    }
    res = min(res, cur);
    pt = 0;
    cur = sz(b);
    for (int i = n - 1, j = 0; j < m;) {
        int c = 0;
        for (int k = i, l = j; k < n && l < m; k++, l++)if (a[k][l] != -1)c++;
        for (int k = i, l = j; k < n && l < m; k++, l++)if (a[k][l] >= b[pt] && a[k][l] <= b[pt + c - 1])cur--;
        pt += c;
        if (i == 0)j++;
        else i--;
    }
    res = min(res, cur);
    pt = 0;
    cur = sz(b);
    for (int i = 0, j = m - 1; i < n;) {
        int c = 0;
        for (int k = i, l = j; k < n && l < m; k++, l++)if (a[k][l] != -1)c++;
        for (int k = i, l = j; k < n && l < m; k++, l++)if (a[k][l] >= b[pt] && a[k][l] <= b[pt + c - 1])cur--;
        pt += c;
        if (j == 0)i++;
        else j--;
    }
    res = min(res, cur);
    cout << res;
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