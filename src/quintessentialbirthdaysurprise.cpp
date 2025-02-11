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

struct LCT {
    int n;
    vector<pair<pll, int>> st;
    vi val;

    inline int l(int p) { return p << 1; }

    inline int r(int p) { return p << 1 ^ 1; }

    LCT(int sz, vi &val) : n(sz) {
        int mx = (1 << (33 - __builtin_clz(n - 1))) + 1;
        this->val = val;
        st.assign(mx, {{0, -llinf}, -1});
    }

    ll calc(pll &p, int x) {
        return p.first * x + p.second;
    }

    bool change(pll &to, pll &from, int &x) {
        ll old = calc(from, x);
        ll neww = calc(to, x);
        if (old == neww)return to.first > from.first;
        return neww > old;
    }

    void update(int p, int L, int R, pair<pll, int> &line) {
        if (L == R) {
            int x = val[L];
            if (change(line.first, st[p].first, x))swap(st[p], line);
            return;
        }
        int mid = (L + R) >> 1;
        int x = val[mid];
        bool chgleft = change(line.first, st[p].first, val[L]);
        bool chgmid = change(line.first, st[p].first, x);
        if (chgmid) swap(st[p], line);
        if (chgmid != chgleft) update(l(p), L, mid, line);
        else update(r(p), mid + 1, R, line);
    }

    pair<ll, int> query(int p, int L, int R, int x) {
        if (L == R) return {calc(st[p].first, x), st[p].second};
        int mid = (L + R) >> 1;
        int midval = val[mid];
        if (x <= midval) {
            pair<ll, int> ret = query(l(p), L, mid, x);
            ll cur = calc(st[p].first, x);
            if (ret.first > cur)return ret;
            else return {cur, st[p].second};
        } else {
            pair<ll, int> ret = query(r(p), mid + 1, R, x);
            ll cur = calc(st[p].first, x);
            if (ret.first > cur)return ret;
            else return {cur, st[p].second};
        }
    }

    void update(pair<pll, int> line) {
        update(1, 0, n - 1, line);
    }

    pair<ll, int> query(int x) {
        return query(1, 0, n - 1, x);
    }
};

inline void solve() {
    int n, m, u, v;
    cin >> n;
    typedef tuple<ll, int, int> tup;
    vector<tup> arr(n);
    for (auto &[t, v, e]: arr)cin >> v >> t >> e;
    sort(all(arr));
    vi val(n);
    rep(i, 0, n)val[i] = get<1>(arr[i]);
    sort(all(val));
    cin >> m;
    vvi bad(6, vi(6));
    rep(i, 0, m) {
        cin >> u >> v;
        bad[u][v] = bad[v][u] = 1;
    }
    pair<ll, int> res = {LLONG_MIN, 0};
    vector<LCT> lct(6, LCT(n, val));
    vi p(n, -1);
    rep(k, 0, n) {
        auto &[t, v, e] = arr[k];
        pair<ll, int> best = {LLONG_MIN, 0};
        rep(i, 1, 6) {
            if (bad[i][e])continue;
            pair<ll, int> ret = lct[i].query(v);
            if (ret.first > best.first)best = ret;
        }
        if (best.first > res.first)res = {best.first, k};
        if (v > res.first)res = {v, k}, p[k] = -1;
        if (best.first <= 0)best = {0, -1};
        lct[e].update({{v, best.first}, k});
        p[k] = best.second;
    }
    pnl(res.first);
    vi ans;
    int i = res.second;
    while (i != -1) {
        ans.pb(i);
        i = p[i];
    }
    pnl(sz(ans));
    for (auto it = ans.rbegin(); it != ans.rend(); it++)pr(*it + 1);
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