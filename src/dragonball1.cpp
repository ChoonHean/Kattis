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
const ll inf = 1e15;
const int mod = 1e9 + 7;
#define all(a) a.begin(),a.end()
#define read(n) vi arr(n);for(int i=0;i<n;i++)cin>>arr[i]
#define readarr(n, arr) for(int i=0;i<n;i++)cin>>arr[i]
#define rep(a, n) for(int i=a;i<n;i++)
#define nl "\n"
#define sz(v) ((int)v.size())
#define pb push_back

template<typename T>
inline void p(T t) { cout << t << ' '; }

template<typename T>
inline void pnl(T t) {
    p(t);
    cout << nl;
}

template<typename T, typename U>
inline void p(pair<T, U> pa) {
    cout << '(';
    p(pa.first);
    cout << ',';
    p(pa.second);
    cout << ") ";
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
    int n, m, u, v, t;
    cin >> n >> m;
    vector<vector<pii>> adj(n);
    rep(0, m) {
        cin >> u >> v >> t;
        u--;
        v--;
        adj[u].pb(pair(v, t));
        adj[v].pb(pair(u, t));
    }
    vi loc(7);
    rep(0, 7) {
        cin >> loc[i];
        loc[i]--;
    }
    vector<vl> dist(7, vl(n, inf));
    rep(0, 7) {
        dist[i][loc[i]] = 0;
        set<pll> tree;
        for (int j = 0; j < n; j++)tree.emplace_hint(tree.end(), inf, j);
        tree.erase(pair(inf, loc[i]));
        for (auto [to, w]: adj[loc[i]]) {
            tree.erase(pair(inf, to));
            tree.emplace(w, to);
            dist[i][to] = w;
        }
        while (!tree.empty()) {
            pll curr = *tree.begin();
            if (curr.first == inf)break;
            tree.erase(tree.begin());
            for (auto [to, w]: adj[curr.second]) {
                ll next = curr.first + w;
                if (next < dist[i][to]) {
                    tree.erase(pair(dist[i][to], to));
                    tree.emplace(pair(next, to));
                    dist[i][to] = next;
                }
            }
        }
    }
    vector<vl> dp(n, vl(1 << 7, inf));
    dp[0][0] = 0;
    for (int shift = 0; shift < 7; shift++) {
        dp[loc[shift]][1 << shift] = dist[shift][0];
    }
    rep(1, 1 << 7) {
        for (int j: loc) {
            for (int shift = 0; shift < 7; shift++) {
                if (!((i >> shift) & 1)) {
                    int next = loc[shift];
                    int state = i | (1 << shift);
                    dp[next][state] = min(dp[next][state], dp[j][i] + dist[shift][j]);
                }
            }
        }
    }
    ll res = inf;
    for (int i: loc)res = min(res, dp[i][(1 << 7) - 1]);
    res == inf ? p(-1) : p(res);
}

int main() {
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}