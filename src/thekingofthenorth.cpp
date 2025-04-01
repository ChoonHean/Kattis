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
inline void pr(T t) { cout << t << ' '; }

template<typename T, typename U>
inline void pr(pair<T, U> pa) {
    cout << '(';
    pr(pa.first);
    cout << ',';
    pr(pa.second);
    cout << ") ";
}

template<typename... Args>
inline void pr(tuple<Args...> tup) {
    apply([](const auto &... args) {
        pr('[');
        (pr(args), ...);
        pr(']');
    }, tup);
}

template<typename T>
inline void pr(vector<T> v) {
    for (auto i: v) pr(i);
    cout << nl;
}

template<typename T>
inline void pr(set<T> s) {
    for (auto t: s)pr(t);
    cout << nl;
}

template<typename T>
inline void pr(unordered_set<T> s) {
    for (auto t: s)pr(t);
    cout << nl;
}

template<typename T, typename U>
inline void pr(map<T, U> m) {
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
inline void pr(unordered_map<T, U> m) {
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
inline void pr(queue<T> q) {
    queue<T> copy(q);
    while (!copy.empty()) {
        pr(copy.front());
        copy.pop();
    }
    cout << nl;
}

template<typename T>
inline void pr(stack<T> s) {
    stack<T> copy(s);
    while (!copy.empty()) {
        pr(copy.top());
        copy.pop();
    }
    cout << nl;
}

template<typename T>
inline void pr(deque<T> q) {
    deque<T> copy(q);
    while (!copy.empty()) {
        pr(copy.top());
        copy.pop();
    }
    cout << nl;
}

template<typename T>
inline void pr(PQ<T> pq) {
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
inline void pr(PQ<T, vector<T>, greater<T>> pq) {
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
inline void pnl(T t) {
    pr(t);
    cout << nl;
}

template<typename... Args>
void pr(Args... args) {
    (pr(args), ...);
    cout << nl;
}

struct max_flow {
    typedef tuple<int, ll, ll> edge;
public:
    int V;
    vector<edge> EL;
    vector<vi> AL;
    vi d, last;
    vector<pii> p;

    bool BFS(int s, int t) {                       // find augmenting path
        d.assign(V, -1);
        d[s] = 0;
        queue<int> q({s});
        p.assign(V, {-1, -1});                       // record BFS sp tree
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (u == t) break;                         // stop as sink t reached
            for (auto &idx: AL[u]) {                  // explore neighbors of u
                auto &[v, cap, flow] = EL[idx];          // stored in EL[idx]
                if ((cap - flow > 0) && (d[v] == -1))      // positive residual edge
                    d[v] = d[u] + 1, q.push(v), p[v] = {u, idx}; // 3 lines in one!
            }
        }
        return d[t] != -1;                           // has an augmenting path
    }

    ll send_one_flow(int s, int t, ll f = llinf) {   // send one flow from s->t
        if (s == t) return f;                        // bottleneck edge f found
        auto &[u, idx] = p[t];
        auto &cap = get<1>(EL[idx]), &flow = get<2>(EL[idx]);
        ll pushed = send_one_flow(s, u, min(f, cap - flow));
        flow += pushed;
        auto &rflow = get<2>(EL[idx ^ 1]);             // back edge
        rflow -= pushed;                             // back flow
        return pushed;
    }

    ll DFS(int u, int t, ll f = llinf) {             // traverse from s->t
        if ((u == t) || (f == 0)) return f;
        for (int &i = last[u]; i < (int) AL[u].size(); ++i) { // from last edge
            auto &[v, cap, flow] = EL[AL[u][i]];
            if (d[v] != d[u] + 1) continue;              // not part of layer graph
            if (ll pushed = DFS(v, t, min(f, cap - flow))) {
                flow += pushed;
                auto &rflow = get<2>(EL[AL[u][i] ^ 1]);     // back edge
                rflow -= pushed;
                return pushed;
            }
        }
        return 0;
    }

    max_flow(int initialV) : V(initialV) {
        EL.clear();
        AL.assign(V, vi());
    }

    // if you are adding a bidirectional edge u<->v with weight w into your
    // flow graph, set directed = false (default value is directed = true)
    void add_edge(int u, int v, ll w, bool directed = true) {
        if (u == v) return;                          // safeguard: no self loop
        EL.emplace_back(v, w, 0);                    // u->v, cap w, flow 0
        AL[u].push_back(EL.size() - 1);                // remember this index
        EL.emplace_back(u, directed ? 0 : w, 0);     // back edge
        AL[v].push_back(EL.size() - 1);                // remember this index
    }

    ll edmonds_karp(int s, int t) {
        ll mf = 0;                                   // mf stands for max_flow
        while (BFS(s, t)) {                          // an O(V*E^2) algorithm
            ll f = send_one_flow(s, t);                // find and send 1 flow f
            if (f == 0) break;                         // if f == 0, stop
            mf += f;                                   // if f > 0, add to mf
        }
        return mf;
    }

    ll dinic(int s, int t) {
        ll mf = 0;                                   // mf stands for max_flow
        while (BFS(s, t)) {                          // an O(V^2*E) algorithm
            last.assign(V, 0);                         // important speedup
            while (ll f = DFS(s, t))                   // exhaust blocking flow
                mf += f;
        }
        return mf;
    }

    void print() {
        for (int i = 0; i < V; i++) {
            cout << i << ' ';
            for (int &j: AL[i])if (!(j & 1))pr(EL[j]);
            cout << nl;
        }
    }
};

inline void solve() {
    int r, c, x, y;
    cin >> r >> c;
    int n = r * c;
    vvi arr(r, vi(c));
    for (auto &v: arr)readarr(v);
    cin >> x >> y;
    max_flow mf(n * 2 + 1);
    rep(i, 0, r)
        rep(j, 0, c) {
            int cur = i * c + j;
            if (i)mf.add_edge(cur + n, (i - 1) * c + j, inf);
            if (j)mf.add_edge(cur + n, i * c + j - 1, inf);
            if (i < r - 1)mf.add_edge(cur + n, (i + 1) * c + j, inf);
            if (j < c - 1)mf.add_edge(cur + n, i * c + j + 1, inf);
            mf.add_edge(cur, cur + n, arr[i][j]);
        }
    rep(i, 0, r)mf.add_edge(i * c + n, 2 * n, inf), mf.add_edge((i + 1) * c - 1 + n, 2 * n, inf);
    rep(j, 1, c - 1)mf.add_edge(j + n, 2 * n, inf), mf.add_edge((r - 1) * c + j + n, 2 * n, inf);
    cout << mf.dinic(x * c + y, 2 * n);
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