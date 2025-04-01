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
typedef tuple<int, int, int> ti;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<pll> vpll;
typedef vector<pdd> vpdd;
typedef tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>
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
#define eb emplace_back
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

struct LCA {                              // OOP style
    vi P2, L2;
    vpii A;
    vector<vi> SpT;                                // the Sparse Table
    LCA() {}                               // default constructor

    LCA(vpii &initialA) {                    // pre-processing routine
        A = initialA;
        int n = (int) A.size();
        int L2_n = (int) log2(n) + 1;
        P2.assign(L2_n + 1, 0);
        L2.assign((1 << L2_n) + 1, 0);
        for (int i = 0; i <= L2_n; ++i) {
            P2[i] = (1 << i);                            // to speed up 2^i
            L2[(1 << i)] = i;                            // to speed up log_2(i)
        }
        for (int i = 2; i < P2[L2_n]; ++i)
            if (L2[i] == 0)
                L2[i] = L2[i - 1];                         // to fill in the blanks

        // the initialization phase
        SpT = vector<vi>(L2[n] + 1, vi(n));
        for (int j = 0; j < n; ++j)
            SpT[0][j] = j;                             // RMQ of sub array [j..j]

        // the two nested loops below have overall time complexity = O(n log n)
        for (int i = 1; P2[i] <= n; ++i)             // for all i s.t. 2^i <= n
            for (int j = 0; j + P2[i] - 1 < n; ++j) {      // for all valid j
                int x = SpT[i - 1][j];                     // [j..j+2^(i-1)-1]
                int y = SpT[i - 1][j + P2[i - 1]];             // [j+2^(i-1)..j+2^i-1]
                SpT[i][j] = A[x] <= A[y] ? x : y;
            }
    }

    pii query(int i, int j) {
        int k = L2[j - i + 1];                           // 2^k <= (j-i+1)
        int x = SpT[k][i];                           // covers [i..i+2^k-1]
        int y = SpT[k][j - P2[k] + 1];                   // covers [j-2^k+1..j]
        return A[x] <= A[y] ? A[x] : A[y];
    }
};

inline void solve() {
    int n, u, v;
    cin >> n;
    vvi adj(n);
    rep(i, 1, n) {
        cin >> u >> v;
        adj[--u].pb(--v);
        adj[v].pb(u);
    }
    vi first(n), par(n);
    vpii order(n << 1);
    int idx = 0;
    auto processlca = [&](auto &self, int i, int d) -> void {
        first[i] = idx;
        order[idx++] = {d, i};
        for (const auto &j: adj[i]) {
            if (j == par[i])continue;
            par[j] = i;
            self(self, j, d + 1);
            order[idx++] = {d, i};
        }
    };
    processlca(processlca, 0, 0);
    LCA lca(order);
    read(n);
    rep(i, 1, n) {
        u = first[arr[i - 1] - 1], v = first[arr[i] - 1];
        if (v < u)swap(u, v);
        pii l = lca.query(u, v);
        if (order[u].first + order[v].first - 2 * l.first > 3) {
            pnl(0);
            return;
        }
    }
    pnl(1);
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