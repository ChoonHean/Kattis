#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
const int inf = 1e9;
const int mod = 1e9 + 7;
#define all(a) a.begin(),a.end()
#define read(n) vi arr(n);for(int i=0;i<n;i++)cin>>arr[i]
#define readarr(n, arr) for(int i=0;i<n;i++)cin>>arr[i]
#define forloop(a, n) for(int i=a;i<n;i++)
#define nl "\n"
#define sz(v) ((int)v.size())
#define pb push_back

template<typename T, typename U>
inline void p(pair<T, U> p) { cout << '(' << p.first << ',' << p.second << ") "; }

template<typename T>
inline void p(T t) { cout << t << ' '; }

template<typename T>
inline void pnl(T t) {
    p(t);
    cout << nl;
}

template<typename T>
inline void p(vector<T> v) {
    for (auto i: v) p(i);
    cout << nl;
}

template<typename T>
inline void p(vector<vector<T>> v) {
    for (auto row: v) p(row);
}

template<typename T>
inline void p(set<T> s) {
    for (auto t: s)p(t);
    cout << nl;
}

template<typename T>
inline void p(unordered_set<T> s) {
    for (auto t: s)p(t);
    cout << nl;
}

template<typename T, typename U>
inline void p(map<T, U> m) {
    for (auto t: m)p(t);
    cout << nl;
}

template<typename T, typename U>
inline void p(unordered_map<T, U> m) {
    for (auto t: m)p(t);
    cout << nl;
}

template<typename T>
inline void p(queue<T> q) {
    queue<T> copy(q);
    while (!copy.empty()) {
        p(copy.front());
        copy.pop();
    }
    cout << nl;
}

bool c = true;

template<typename T>
inline void p(stack<T> s) {
    stack<T> copy(s);
    while (!copy.empty()) {
        p(copy.top());
        copy.pop();
    }
    cout << nl;
}

inline void solve() {
    int n, m, q, s, u, v, w;
    cin >> n >> m >> q >> s;
    if (n + m == 0) {
        c = false;
        return;
    }
    vector<vector<pii>> adj(n);
    forloop(0, m) {
        cin >> u >> v >> w;
        adj[u].pb(pair(v, w));
    }
    vi d(n, inf);
    set<pii> tree;
    forloop(0, n)tree.emplace_hint(tree.end(), inf, i);
    tree.erase(pair(inf, s));
    d[s] = 0;
    vb visited(n);
    visited[s] = true;
    for (auto [x, y]: adj[s]) {
        if (y < d[x]) {
            tree.erase(pair(d[x], x));
            tree.emplace(y, x);
            d[x] = y;
        }
    }
    while (!tree.empty()) {
        pii curr = *tree.begin();
        visited[curr.second] = true;
        tree.erase(tree.begin());
        for (auto [x, y]: adj[curr.second])
            if (!visited[x]) {
                if (curr.first + y < d[x]) {
                    tree.erase(pair(d[x], x));
                    tree.emplace(curr.first + y, x);
                    d[x] = curr.first + y;
                }
            }
    }
    while (q--) {
        cin >> v;
        d[v] == inf ? pnl("Impossible") : pnl(d[v]);
    }
}

int main() {
    int t = 1;
    //cin >> t;
    while (c) {
        solve();
    }
    return 0;
}