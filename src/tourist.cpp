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

struct min_cost_max_flow {
    typedef tuple<int, ll, ll, ll> edge;
    int V;
    ll total_cost;
    vector<edge> EL;
    vector<vi> AL;
    vl d;
    vi last, vis;

    bool SPFA(int s, int t) { // SPFA to find augmenting path in residual graph
        d.assign(V, llinf);
        d[s] = 0;
        vis[s] = 1;
        queue<int> q({s});
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            vis[u] = 0;
            for (auto &idx: AL[u]) {                  // explore neighbors of u
                auto &[v, cap, flow, cost] = EL[idx];          // stored in EL[idx]
                if ((cap - flow > 0) && (d[v] > d[u] + cost)) {      // positive residual edge
                    d[v] = d[u] + cost;
                    if (!vis[v]) q.push(v), vis[v] = 1;
                }
            }
        }
        return d[t] != llinf;                           // has an augmenting path
    }

    ll DFS(int u, int t, ll f = llinf) {             // traverse from s->t
        if ((u == t) || (f == 0)) return f;
        vis[u] = 1;
        for (int &i = last[u]; i < (int) AL[u].size(); ++i) { // from last edge
            auto &[v, cap, flow, cost] = EL[AL[u][i]];
            if (!vis[v] && d[v] == d[u] + cost) {                      // in current layer graph
                if (ll pushed = DFS(v, t, min(f, cap - flow))) {
                    total_cost += pushed * cost;
                    flow += pushed;
                    auto &[rv, rcap, rflow, rcost] = EL[AL[u][i] ^ 1]; // back edge
                    rflow -= pushed;
                    vis[u] = 0;
                    return pushed;
                }
            }
        }
        vis[u] = 0;
        return 0;
    }

    min_cost_max_flow(int initialV) : V(initialV), total_cost(0) {
        EL.clear();
        AL.assign(V, vi());
        vis.assign(V, 0);
    }

    // if you are adding a bidirectional edge u<->v with weight w into your
    // flow graph, set directed = false (default value is directed = true)
    void add_edge(int u, int v, ll w, ll c, bool directed = true) {
        if (u == v) return;                          // safeguard: no self loop
        EL.emplace_back(v, w, 0, c);                 // u->v, cap w, flow 0, cost c
        AL[u].push_back(EL.size() - 1);                // remember this index
        EL.emplace_back(u, 0, 0, -c);                // back edge
        AL[v].push_back(EL.size() - 1);                // remember this index
        if (!directed) add_edge(v, u, w, c);         // add again in reverse
    }

    pair<ll, ll> mcmf(int s, int t) {
        ll mf = 0;                                   // mf stands for max_flow
        while (SPFA(s, t)) {                          // an O(V^2*E) algorithm
            last.assign(V, 0);                         // important speedup
            while (ll f = DFS(s, t))                   // exhaust blocking flow
                mf += f;
        }
        return {mf, total_cost};
    }
};

inline void solve() {
    int w, h;
    cin >> w >> h;
    vs a(h);
    reada(a);
    int N = w * h;
    min_cost_max_flow mf(2 * N + 2);
    rep(i, 0, h)
        rep(j, 0, w) {
            if (a[i][j] == '*') {
                mf.add_edge(i * w + j, N + i * w + j, 1, -1);
                mf.add_edge(i * w + j, N + i * w + j, 1, 0);
                if (i < h - 1)mf.add_edge(N + i * w + j, (i + 1) * w + j, 2, 0);
                if (j < w - 1)mf.add_edge(N + i * w + j, i * w + j + 1, 2, 0);
            } else if (a[i][j] == '.') {
                if (i < h - 1)mf.add_edge(i * w + j, (i + 1) * w + j, 2, 0);
                if (j < w - 1)mf.add_edge(i * w + j, i * w + j + 1, 2, 0);
            }
        }
    mf.add_edge(2 * N, 0, 2, 0);
    pnl(-mf.mcmf(2 * N, a.back().back() == '*' ? 2 * N - 1 : N - 1).second);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(10);
    int cases = 1;
    cin >> cases;
    while (cases--) solve();
    int cnt = 0;
    return 0;
}