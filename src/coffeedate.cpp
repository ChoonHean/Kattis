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
typedef tree<pair<int, ll>, null_type, greater<pair<int, ll>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int inf = 1e9;
const int mod = 1e9 + 7;
#define all(a) a.begin(),a.end()
#define read(n) vi arr(n);for(int _=0;_<n;_++)cin>>arr[_]
#define readarr(n, arr) for(int _=0;_<n;_++)cin>>arr[_]
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

inline void solve() {
    int n, m, a, b, t, s, x;
    cin >> n >> m >> a >> b;
    vector<pair<int, vi>> el;
    rep(0, m) {
        int start = sz(el), tot = 0;
        cin >> t >> s;
        pair<int, vi> edge{0, vi(4)}; //{from, (to, weight, interval, first bus)}
        cin >> edge.first >> edge.second[0];
        edge.second[2] = t;
        el.pb(edge);
        for (int j = 2; j < s; j++) {
            edge.first = el.back().second[0];
            cin >> edge.second[0];
            edge.second[2] = t;
            el.pb(edge);
        }
        for (int j = 0; j < s - 1; j++) {
            cin >> x;
            el[start + j].second[1] = x;
            el[start + j].second[3] = tot;
            tot += x;
            tot %= t;
        }
    }
    vvvi adj(n);
    for (auto &[u, v]: el) { //(to, weight, interval, first bus)
        adj[u].pb(v);
    }
    vi dista(n, inf), distb(n, inf);
    dista[a] = 0;
    set<pii> pq;
    pq.insert({0, a});
    rep(0, a)pq.emplace_hint(pq.end(), inf, i);
    rep(a + 1, n)pq.emplace_hint(pq.end(), inf, i);
    while (!pq.empty()) {
        auto [d, i] = *pq.begin();
        pq.erase(pq.begin());
        for (auto &v: adj[i]) { //(to, weight, interval, first bus)
            int diff = d - v[3];
            int next = d + v[1];
            if (diff < 0)next = v[3] + v[1];
            else if (diff % v[2] != 0)next += v[2] - diff % v[2];
            if (next < dista[v[0]]) {
                pq.erase({dista[v[0]], v[0]});
                pq.insert({next, v[0]});
                dista[v[0]] = next;
            }
        }
    }
    pq.insert({0, b});
    distb[b] = 0;
    rep(0, b)pq.emplace_hint(pq.end(), inf, i);
    rep(b + 1, n)pq.emplace_hint(pq.end(), inf, i);
    while (!pq.empty()) {
        auto [d, i] = *pq.begin();
        pq.erase(pq.begin());
        for (auto &v: adj[i]) { //(to, weight, interval, first bus)
            int diff = d - v[3];
            int next = d + v[1];
            if (diff < 0)next = v[3] + v[1];
            else if (diff % v[2] != 0)next += v[2] - diff % v[2];
            if (next < distb[v[0]]) {
                pq.erase({distb[v[0]], v[0]});
                pq.insert({next, v[0]});
                distb[v[0]] = next;
            }
        }
    }
    int res = inf;
    rep(0, n) {
        res = min(res, max(dista[i], distb[i]));
    }
    res == inf ? pnl("NO COFFEE FOR YOU") : pnl(res);
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