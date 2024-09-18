#include <bits/stdc++.h>

using namespace std;
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
#define LSOne(i) (i&-i)

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
        pr(t);
        pr('-');
        pr(u);
    }
    cout << nl;
}

template<typename T, typename U>
inline void pr(unordered_map<T, U> m) {
    for (auto [t, u]: m) {
        pr(t);
        pr('-');
        pr(u);
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

bool _ = true;

inline void solve() {
    int n, counter = 0;
    cin >> n;
    if (!n) {
        _ = false;
        return;
    }
    char a, b, c, d, e, s;
    int A, B, C, D, E, S;
    hmap<char, int> map;
    vc name;
    vvi adj;
    rep(0, n) {
        cin >> a >> b >> c >> d >> e >> s;
        if (map.contains(a))A = map[a];
        else {
            A = map[a] = counter++;
            adj.pb(vi());
            name.pb(a);
        }
        if (map.contains(b))B = map[b];
        else {
            B = map[b] = counter++;
            adj.pb(vi());
            name.pb(b);
        }
        if (map.contains(c))C = map[c];
        else {
            C = map[c] = counter++;
            adj.pb(vi());
            name.pb(c);
        }
        if (map.contains(d))D = map[d];
        else {
            D = map[d] = counter++;
            adj.pb(vi());
            name.pb(d);
        }
        if (map.contains(e))E = map[e];
        else {
            E = map[e] = counter++;
            adj.pb(vi());
            name.pb(e);
        }
        S = map[s];
        if (A != S)adj[S].pb(A);
        if (B != S)adj[S].pb(B);
        if (C != S)adj[S].pb(C);
        if (D != S)adj[S].pb(D);
        if (E != S)adj[S].pb(E);
    }
    n = sz(adj);
    stack<int> order;
    vb visited(n);
    function<void(int)> topo = [&](int i) {
        visited[i] = true;
        for (int j: adj[i])if (!visited[j])topo(j);
        order.push(i);
    };
    rep(0, n)if (!visited[i])topo(i);
    vvi t(n);
    rep(0, n)for (int j: adj[i])t[j].pb(i);
    vector<vc> res;
    visited.assign(n, false);
    function<void(int)> dfs = [&](int i) {
        visited[i] = true;
        res.back().pb(name[i]);
        for (int j: t[i])if (!visited[j])dfs(j);
    };
    while (!order.empty()) {
        int i = order.top();
        order.pop();
        if (!visited[i]) {
            res.pb(vc());
            dfs(i);
        }
    }
    rep(0, sz(res))sort(all(res[i]));
    sort(all(res));
    for (auto v: res)pr(v);
    pnl("");
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (_) {
        solve();
    }
    return 0;
}