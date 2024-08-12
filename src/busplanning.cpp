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
#define pb push_back
#define clz(i) __builtin_clz(i)
#define ctz(i) __builtin_ctz(i)
#define popcount(i) __builtin_popcount(i)
#define lsb(i) i&-i

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

vvi sets;
int n, m, c, a, b, done;
vector<pair<int, vi>> dp;

pair<int, vi> f(int mask) {
    if (mask == done)return pair(0, vi());
    if (dp[mask].first != -1)return dp[mask];
    int i = 0;
    while (((mask) >> i) & 1)i++;
    pair<int, vi> res = pair(20, vi());
    for (int j: sets[i])
        if ((j & mask) == 0) {
            pair<int, vi> ret = f(j | mask);
            if (ret.first < res.first) {
                res = ret;
                res.first++;
                res.second.pb(j);
            }
        }
    return dp[mask] = res;
}

inline void solve() {
    string u, v;
    cin >> n >> m >> c;
    unordered_map<string, int> mapper;
    vs names(n);
    rep(0, n) {
        cin >> names[i];
        mapper[names[i]] = i;
    }
    vector<unordered_set<int>> adj(n);
    rep(0, m) {
        cin >> u >> v;
        a = mapper[u];
        b = mapper[v];
        adj[a].insert(b);
        adj[b].insert(a);
    }
    sets.resize(n);
    rep(1, 1 << n) {
        if (popcount(i) <= c) {
            bool ok = true;
            for (int j = 0; j < n; j++)
                if ((i >> j) & 1) {
                    for (int k = j + 1; k < n; k++)
                        if ((i >> k) & 1) {
                            if (adj[j].contains(k))ok = false;
                        }
                }
            if (ok)
                for (int j = 0; j < n; j++)
                    if ((i >> j) & 1) {
                        sets[j].pb(i);
                        break;
                    }
        }
    }
    done = (1 << n) - 1;
    dp.assign(1 << n, pair(-1, vi()));
    pair<int, vi> res = f(0);
    cout << res.first << nl;
    for (int i: res.second) {
        string s;
        for (int j = 0; j < n; j++)if ((i >> j) & 1)s += names[j] + ' ';
        s.pop_back();
        cout << s << nl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}