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
//const int inf = 1e9;
const int mod = 1e9 + 7;
#define all(a) a.begin(),a.end()
#define read(n) vi arr(n);for(int i=0;i<n;i++)cin>>arr[i]
#define readarr(n, arr) for(int i=0;i<n;i++)cin>>arr[i]
#define rep(a, n) for(int i=a;i<n;i++)
#define nl "\n"
#define sz(v) ((int)v.size())
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
    for (auto t: m)pr(t);
    cout << nl;
}

template<typename T, typename U>
inline void pr(unordered_map<T, U> m) {
    for (auto t: m)pr(t);
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

vvi adj, t;
stack<int> order;
vb visited;
vi sccs;
int counter;

void kosaraju(int i) {
    visited[i] = true;
    for (int j: adj[i])if (!visited[j])kosaraju(j);
    order.push(i);
}

void dfs(int i) {
    sccs[i] = counter;
    for (int j: t[i])if (sccs[j] == -1)dfs(j);
}

inline void solve() {
    int n, e, u, v;
    cin >> n >> e;
    adj.assign(n, vi());
    t.assign(n, vi());
    visited.assign(n, false);
    sccs.assign(n, -1);
    counter = 0;
    rep(0, e) {
        cin >> u >> v;
        adj[--u].pb(--v);
        t[v].pb(u);
    }
    rep(0, n)if (!visited[i])kosaraju(i);
    while (!order.empty()) {
        int i = order.top();
        order.pop();
        if (sccs[i] == -1) {
            dfs(i);
            counter++;
        }
    }
    vector<unordered_set<int>> g(counter);
    rep(0, n)for (int j: adj[i])if (sccs[i] != sccs[j])g[sccs[i]].insert(sccs[j]);
    vi indeg(counter), outdeg(counter);
    rep(0, counter) {
        outdeg[i] = sz(g[i]);
        for (int j: g[i])indeg[j]++;
    }
    int x = 0, y = 0;
    rep(0, counter) {
        if (indeg[i] == 0)x++;
        if (outdeg[i] == 0)y++;
    }
    if (counter == 1)pr(0);
    else pr(max(x, y));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}