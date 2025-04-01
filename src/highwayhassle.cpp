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

vvpii adj;
vpii arr(120);
hmap<int, int> cost;
vector<map<ll, int>> visited;
vvi dist(1000);

inline void solve() {
    int n, m, s, t, u, v, w, src, dst;
    cin >> n >> m >> s >> t;
    adj.assign(n, vpii());
    rep(i, 0, m) {
        cin >> u >> v >> w;
        adj[--u].eb(--v, w);
        adj[v].eb(u, w);
    }
    cost.clear();
    rep(i, 0, s) {
        cin >> u >> w;
        u--;
        arr[i] = {u, w};
        cost[u] = w;
    }
    cin >> src >> dst;
    src--, dst--;
    rep(i, 0, s) {
        auto &cur = dist[arr[i].first];
        cur.assign(n, inf);
        cur[arr[i].first] = 0;
        set<pii> pq;
        pq.emplace(0, arr[i].first);
        while (!pq.empty()) {
            auto [d, u] = *pq.begin();
            pq.erase(pq.begin());
            for (const auto &[v, w]: adj[u]) {
                int next = w + d;
                if (next < cur[v]) {
                    pq.erase({cur[v], v});
                    pq.emplace(cur[v] = next, v);
                }
            }
        }
    }
    ll res = llinf;
    visited.assign(n, map<ll, int>());
    typedef tuple<ll, int, int> tup;
    set<tup> pq;
    pq.emplace(0, src, 0);
    while (!pq.empty()) {
        auto [c, u, f] = *pq.begin();
        if (c >= res)break;
        pq.erase(pq.begin());
        auto &cur = dist[u];
        int curcost = cost[u];
        if (cur[dst] <= t)res = min(res, c + max(0, cur[dst] - f) * curcost);
        ll fulltank = c + (t - f) * curcost;
        for (const auto &[v, a]: arr) {
            if (u == v)continue;
            if (cur[v] <= t) {
                int need = max(0, cur[v] - f);
                ll next = need * curcost + c;
                int left = f + need - cur[v];
                auto it = visited[v].upper_bound(next);
                if (it == visited[v].begin()) {
                    visited[v][next] = left;
                    pq.emplace(next, v, left);
                } else if (left > (--it)->second) {
                    it = visited[v].insert_or_assign(it, next, left);
                    pq.emplace(next, v, left);
                    it++;
                    while (it != visited[v].end()) {
                        if (it->second <= left) {
                            pq.erase({it->first, v, it->second});
                            it++;
                        } else break;
                    }
                }
                left = t - cur[v];
                next = fulltank;
                it = visited[v].upper_bound(next);
                if (it == visited[v].begin()) {
                    visited[v][next] = left;
                    pq.emplace(next, v, left);
                } else if (left > (--it)->second) {
                    it = visited[v].insert_or_assign(it, next, left);
                    pq.emplace(next, v, left);
                    it++;
                    while (it != visited[v].end()) {
                        if (it->second <= left) {
                            pq.erase({it->first, v, it->second});
                            it++;
                        } else break;
                    }
                }
            }
        }
    }
    pnl(res);
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