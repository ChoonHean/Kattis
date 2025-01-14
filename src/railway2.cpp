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
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
        ordered_set;
const int inf = 1e9;
const int mod = 1e9 + 7;
const double EPS = 1e-9;
#define all(a) a.begin(),a.end()
#define read(n) vi arr(n);for(int&_:arr)cin>>_
#define readarr(n, arr) for(auto&_:arr)cin>>_
#define rep(a, n) for(int i=a;i<n;i++)
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

struct FT {                              // index 0 is not used
    vi ft;                                        // internal FT is an array
    FT(int m) { ft.assign(m + 1, 0); }      // create an empty FT
    FT() {}

    inline void build(const vi &f) {
        int m = (int) f.size() - 1;                     // note f[0] is always 0
        ft.assign(m + 1, 0);
        for (int i = 1; i <= m; ++i) {               // O(m)
            ft[i] += f[i];                             // add this value
            if (i + lsb(i) <= m)                       // i has parent
                ft[i + lsb(i)] += ft[i];                 // add to that parent
        }
    }

    inline FT(const vi &f) { build(f); }        // create FT based on f

    inline FT(int m, const vi &s) {              // create FT based on s
        vi f(m + 1, 0);
        for (int i = 0; i < (int) s.size(); ++i)      // do the conversion first
            ++f[s[i]];                                 // in O(n)
        build(f);                                    // in O(m)
    }

    inline int rsq(int j) {                                // returns RSQ(1, j)
        int sum = 0;
        for (; j; j -= lsb(j))
            sum += ft[j];
        return sum;
    }

    inline int rsq(int i, int j) { return rsq(j) - rsq(i - 1); } // inc/exclusion

    // updates value of the i-th element by v (v can be +ve/inc or -ve/dec)
    inline void update(int i, int v) {
        for (; i < (int) ft.size(); i += lsb(i))
            ft[i] += v;
    }

    int select(ll k) {                             // O(log m)
        int p = 1;
        while (p * 2 < (int) ft.size()) p *= 2;
        int i = 0;
        while (p) {
            if (k > ft[i + p]) {
                k -= ft[i + p];
                i += p;
            }
            p /= 2;
        }
        return i + 1;
    }
};

struct RUPQ {                                     // RUPQ variant
    FT ft;                                // internally use PURQ FT
    RUPQ(int m) : ft(FT(m)) {}

    RUPQ() : ft() {}

    inline void range_update(int ui, int uj, int v) {
        ft.update(ui, v);                            // [ui, ui+1, .., m] +v
        ft.update(uj + 1, -v);                         // [uj+1, uj+2, .., m] -v
    }                                              // [ui, ui+1, .., uj] +v
    inline int point_query(int i) { return ft.rsq(i); }    // rsq(i) is sufficient
};

struct LCA {
    int n;
    vpii A, st;

    inline int l(int p) { return p << 1; }

    inline int r(int p) { return (p << 1) + 1; }

    inline pii conquer(pii a, pii b) {
        if (a.first < b.first)return a;
        else return b;
    }

    void build(int p, int L, int R) {
        if (L == R)
            st[p] = A[L];
        else {
            int m = (L + R) / 2;
            build(l(p), L, m);
            build(r(p), m + 1, R);
            st[p] = conquer(st[l(p)], st[r(p)]);
        }
    }

    pii RMQ(int p, int L, int R, int i, int j) {
        if (i > j) return {inf, inf};
        if ((L >= i) && (R <= j)) return st[p];
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

    inline int RMQ(int i, int j) {
        if (i > j)swap(i, j);
        return RMQ(1, 0, n - 1, i, j).second;
    }
};

inline void solve() {
    int n, m, k, u, v, t;
    cin >> n >> m >> k;
    vvi adj(n);
    map<pii, int> edges;
    rep(1, n) {
        cin >> u >> v;
        adj[--u].pb(--v);
        adj[v].pb(u);
        if (u < v)edges.emplace(pair(u, v), i);
        else edges.emplace(pair(v, u), i);
    }
    vi par(n), heavy(n), group(n), pos(n), first(n), depth(n);
    auto dfs = [&](auto &self, int i) -> int {
        int size = 1, mx = 0;
        for (auto &j: adj[i]) {
            if (j == par[i])continue;
            par[j] = i;
            int child = self(self, j);
            if (child > mx) {
                heavy[i] = j;
                mx = child;
            }
            size += child;
        }
        return size;
    };
    auto decompose = [&](auto &self, int i, int p) -> void {
        group[i] = p;
        for (auto &j: adj[i]) {
            if (j == par[i])continue;
            if (j == heavy[i]) {
                pos[j] = pos[i] + 1;
                self(self, j, p);
            } else self(self, j, j);
        }
    };
    vpii order(n << 1);
    int idx = 0;
    auto processlca = [&](auto &self, int i, int d) -> void {
        first[i] = idx;
        order[idx++] = {d, i};
        depth[i] = d;
        for (auto &j: adj[i]) {
            if (j == par[i])continue;
            self(self, j, d + 1);
            order[idx++] = {d, i};
        }
    };
    dfs(dfs, 0);
    decompose(decompose, 0, 0);
    processlca(processlca, 0, 0);
    LCA lca(order);
    vector<RUPQ> fts(n);
    vi size(n);
    for (int &i: group)size[i]++;
    rep(0, n)if (size[i])fts[i] = RUPQ(size[i]);
    vi deepest(n, -1);
    while (m--) {
        cin >> t;
        vi arr(t);
        for (int &i: arr)cin >> i, --i;
        int root = lca.RMQ(first[arr[0]], first[arr[1]]);
        rep(2, t)root = lca.RMQ(first[root], first[arr[i]]);
        hset<int> edited;
        edited.insert(group[root]);
        for (int i: arr) {
            int g = group[i];
            while (g != group[root]) {
                edited.insert(g);
                deepest[g] = max(deepest[g], pos[i]);
                i = par[g];
                g = group[i];
            }
            deepest[g] = max(deepest[g], pos[i]);
        }
        for (int i: edited) {
            fts[i].range_update(1, deepest[i] + 1, 1);
            deepest[i] = -1;
        }
        fts[group[root]].range_update(1, pos[root] + 1, -1);
    }
    vi res, out;
    rep(1, n)if (fts[group[i]].point_query(pos[i] + 1) >= k)res.pb(i);
    for (int &i: res) {
        int j = par[i];
        if (i < j)out.pb(edges[pair(i, j)]);
        else out.pb(edges[pair(j, i)]);
    }
    pnl(sz(out));
    sort(all(out));
    pr(out);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}