#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pdd> vpdd;
typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int inf = 1e9;
const int mod = 1e9 + 7;
#define all(a) a.begin(),a.end()
#define read(n) vi arr(n);for(int i=0;i<n;i++)cin>>arr[i]
#define readarr(n, arr) for(int i=0;i<n;i++)cin>>arr[i]
#define rep(a, n) for(int i=a;i<n;i++)
#define nl "\n"
#define sz(v) ((int)v.size())
#define PQ priority_queue
#define hmap unordered_map
#define hset unordered_set
#define pb push_back
#define clz(i) __builtin_clz(i)
#define ctz(i) __builtin_ctz(i)
#define popcount(i) __builtin_popcount(i)
#define lsb(i) (i&-i)
mt19937_64 rnd(time(0));


template<typename T>
inline void pr(T t) { cout << t << ' '; }

template<typename T>
inline void pnl(T t) {
    pr(t);
    cout << nl;
}

template<typename T, typename U>
inline void pr(pair<T, U> pa) {
    cout << '(';
    pr(pa.first);
    cout << ',';
    pr(pa.second);
    cout << ") ";
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

inline int euclid(int a, int b, int &x, int &y) { // pass x and y by ref
    int xx = y = 0;
    int yy = x = 1;
    while (b) { // repeats until b == 0
        int q = a / b;
        int t = b;
        b = a % b;
        a = t;
        t = xx;
        xx = x - q * xx;
        x = t;
        t = yy;
        yy = y - q * yy;
        y = t;
    }
    return a; // returns gcd(a, b)
}

inline ll binpow(ll a, int p, int m) {
    ll res = 1;
    while (p) {
        if (p & 1)res = (res * a) % m;
        a = (a * a) % m;
        p >>= 1;
    }
    return res;
}

struct UFDS {
    vi p;

    UFDS(int n) {
        p.reserve(n);
        for (int i = 0; i < n; i++)p.push_back(i);
    }

    int find(int n) {
        if (n == p[n])return n;
        return p[n] = find(p[n]);
    }

    inline bool sameset(int x, int y) { return find(x) == find(y); }

    inline void unionset(int x, int y) {
        x = find(x);
        y = find(y);
        p[y] = x;
    }
};

struct LCA {
    int n;                                         // n = (int)A.size()
    vpii A;
    vpii st;

    inline int l(int p) { return p << 1; }                 // go to left child
    inline int r(int p) { return (p << 1) + 1; }              // go to right child

    inline pii conquer(pii a, pii b) {
        if (a.first < b.first)return a;
        else return b;
    }

    void build(int p, int L, int R) {              // O(n)
        if (L == R)
            st[p] = A[L];
        else {
            int m = (L + R) / 2;
            build(l(p), L, m);
            build(r(p), m + 1, R);
            st[p] = conquer(st[l(p)], st[r(p)]);
        }
    }

    pii RMQ(int p, int L, int R, int i, int j) {   // O(log n)
        if (i > j) return {inf, inf};                        // infeasible
        if ((L >= i) && (R <= j)) return st[p];      // found the segment
        int m = (L + R) / 2;
        return conquer(RMQ(l(p), L, m, i, min(m, j)),
                       RMQ(r(p), m + 1, R, max(i, m + 1), j));
    }

    LCA(int sz) : n(sz), A(n) {
        int mx = (1 << (33 - __builtin_clz(n - 1))) + 1;
        st.resize(mx);
    }

    LCA(const vpii &initialA) : LCA((int) initialA.size()) {
        A = initialA;
        build(1, 0, n - 1);
    }

    inline int RMQ(int i, int j) { return RMQ(1, 0, n - 1, i, j).second; }
};

struct ST {
    int n;                                         // n = (int)A.size()
    vi A, st, lazy;                                // the arrays

    inline int l(int p) { return p << 1; }                 // go to left child
    inline int r(int p) { return (p << 1) + 1; }              // go to right child

    inline int conquer(int a, int b) {
        if (a == -1) return b;                       // corner case
        if (b == -1) return a;
        return min(a, b);                            // RMQ
    }

    void build(int p, int L, int R) {              // O(n)
        if (L == R)
            st[p] = A[L];                              // base case
        else {
            int m = (L + R) / 2;
            build(l(p), L, m);
            build(r(p), m + 1, R);
            st[p] = conquer(st[l(p)], st[r(p)]);
        }
    }

    inline void propagate(int p, int L, int R) {
        if (lazy[p] != -1) {                         // has a lazy flag
            st[p] = lazy[p];                           // [L..R] has same value
            if (L != R)                                // not a leaf
                lazy[l(p)] = lazy[r(p)] = lazy[p];       // propagate downwards
            else                                       // L == R, a single index
                A[L] = lazy[p];                          // time to update this
            lazy[p] = -1;                              // erase lazy flag
        }
    }

    int RMQ(int p, int L, int R, int i, int j) {   // O(log n)
        propagate(p, L, R);                          // lazy propagation
        if (i > j) return -1;                        // infeasible
        if ((L >= i) && (R <= j)) return st[p];      // found the segment
        int m = (L + R) / 2;
        return conquer(RMQ(l(p), L, m, i, min(m, j)),
                       RMQ(r(p), m + 1, R, max(i, m + 1), j));
    }

    void update(int p, int L, int R, int i, int j, int val) { // O(log n)
        propagate(p, L, R);                          // lazy propagation
        if (i > j) return;
        if ((L >= i) && (R <= j)) {                  // found the segment
            lazy[p] = val;                             // update this
            propagate(p, L, R);                        // lazy propagation
        } else {
            int m = (L + R) / 2;
            update(l(p), L, m, i, min(m, j), val);
            update(r(p), m + 1, R, max(i, m + 1), j, val);
            int lsubtree = (lazy[l(p)] != -1) ? lazy[l(p)] : st[l(p)];
            int rsubtree = (lazy[r(p)] != -1) ? lazy[r(p)] : st[r(p)];
            st[p] = conquer(lsubtree, rsubtree);
        }
    }

    ST(int sz) : n(sz), A(n) {
        int mx = (1 << (33 - __builtin_clz(n - 1))) + 1;
        st.resize(mx);
        lazy.assign(mx, -1);
    }

    ST(const vi &initialA) : ST((int) initialA.size()) {
        A = initialA;
        build(1, 0, n - 1);
    }

    inline void update(int i, int j, int val) { update(1, 0, n - 1, i, j, val); }

    inline int RMQ(int i, int j) { return RMQ(1, 0, n - 1, i, j); }
};

inline void solve() {
    int n, m, q, u, v;
    cin >> n >> m >> q;
    vector<pair<int, pii>> e(m);
    for (auto &[w, p]: e) {
        cin >> u >> v >> w;
        p.first = u - 1;
        p.second = v - 1;
    }
    sort(all(e), greater<pair<int, pii>>());
    vector<vpii> adj(n);
    UFDS ufds(n);
    for (auto &[w, p]: e) {
        if (!ufds.sameset(p.first, p.second)) {
            adj[p.first].pb({p.second, w});
            adj[p.second].pb({p.first, w});
            ufds.unionset(p.first, p.second);
        }
    }
    vi heavy(n), group(n), subtree(n, -1), roots;
    vpii par(n);
    int _;
    auto dfs = [&](auto &self, int i) -> int {
        int size = 1, mx = 0;
        subtree[i] = _;
        for (auto &[j, w]: adj[i]) {
            if (j == par[i].first)continue;
            par[j].first = i;
            par[j].second = w;
            int child = self(self, j);
            if (child > mx) {
                heavy[i] = j;
                mx = child;
            }
            size += child;
        }
        return size;
    };
    rep(0, n) {
        if (subtree[i] != -1)continue;
        _ = i;
        roots.pb(i);
        dfs(dfs, i);
    }
    auto decompose = [&](auto &self, int i, int p) -> void {
        group[i] = p;
        for (auto &[j, w]: adj[i]) {
            if (j == par[i].first)continue;
            if (j == heavy[i])self(self, j, p);
            else self(self, j, j);
        }
    };
    for (int &i: roots)decompose(decompose, i, i);
    vi first(n);
    vpii order;
    int idx;
    auto processlca = [&](auto &self, int i, int d) -> void {
        first[i] = idx++;
        order.pb({d, i});
        for (auto &[j, w]: adj[i]) {
            if (j == par[i].first)continue;
            self(self, j, d + 1);
            order.pb({d, i});
            idx++;
        }
    };
    hmap<int, hmap<int, vi>> maps;
    hmap<int, LCA> lcas;
    vi posinpath(n, -1);
    for (int &i: roots) {
        order.clear();
        idx = 0;
        processlca(processlca, i, 0);
        lcas.emplace(i, LCA(order));
        auto &mp = maps[i];
        queue<int> qq;
        qq.push(i);
        posinpath[i] = 0;
        while (!qq.empty()) {
            int j = qq.front();
            qq.pop();
            for (auto &[k, w]: adj[j]) {
                if (k == par[j].first)continue;
                qq.push(k);
                posinpath[k] = sz(mp[group[k]]);
                if (group[j] == group[k])mp[group[k]].pb(w);
            }
        }
    }
    hmap<int, hmap<int, ST>> paths;
    for (auto &i: roots) {
        auto &mp = paths[i];
        for (auto &[g, vec]: maps[i]) {
            mp.emplace(g, ST(vec));
        }
    }
    int x = 0, a, b, c;
    while (q--) {
        cin >> a >> b >> c;
        a = (a ^ x) - 1;
        b = (b ^ x) - 1;
        c ^= x;
        if (!ufds.sameset(a, b)) {
            pnl("Neibb");
            continue;
        }
        if (a == b) {
            pnl("Jebb");
            x++;
            continue;
        }
        int root = subtree[a];
        auto &path = paths[root];
        u = first[a], v = first[b];
        if (u > v)swap(u, v);
        int lca = lcas.find(root)->second.RMQ(u, v);
        int res = INT_MAX;
        while (group[a] != group[lca]) {
            res = min(res, path.find(group[a])->second.RMQ(0, posinpath[a]));
            a = group[a];
            res = min(res, par[a].second);
            a = par[a].first;
        }
        if (a != lca)res = min(res, path.find(group[a])->second.RMQ(posinpath[lca] + 1, posinpath[a]));
        while (group[b] != group[lca]) {
            res = min(res, path.find(group[b])->second.RMQ(0, posinpath[b]));
            b = group[b];
            res = min(res, par[b].second);
            b = par[b].first;
        }
        if (b != lca)res = min(res, path.find(group[b])->second.RMQ(posinpath[lca] + 1, posinpath[b]));
        if (res < c)pnl("Neibb");
        else {
            pnl("Jebb");
            x++;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}