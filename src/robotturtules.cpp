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
#define PQ priority_queue
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

struct comp {
    bool operator()(pair<int, string> a, pair<int, string> b) const {
        int x = sz(a.second), y = sz(b.second);
        if (x == y)return a.first < b.first;
        else return x < y;
    }
};

inline void solve() {
    vs grid(8);
    int target;
    rep(0, 8) {
        cin >> grid[i];
        for (int j = 0; j < 8; j++)if (grid[i][j] == 'D')target = i * 8 + j;
    }
    vector<vector<pair<int, string>>> adj(256);
    rep(0, 256) {
        int pos = i % 64;
        int x = pos / 8;
        int y = pos % 8;
        adj[i].pb(pair((i + 64) % 256, "R"));
        adj[i].pb(pair((i + 192) % 256, "L"));
        if (i / 64 == 0) {
            if (x > 0) {
                char c = grid[x - 1][y];
                if (c == 'I')adj[i].pb(pair(i - 8, "XF"));
                else if (c == '.' || c == 'D')adj[i].pb(pair(i - 8, "F"));
            }
        } else if (i / 64 == 1) {
            if (y < 7) {
                char c = grid[x][y + 1];
                if (c == 'I')adj[i].pb(pair(i + 1, "XF"));
                else if (c == '.' || c == 'D')adj[i].pb(pair(i + 1, "F"));
            }
        } else if (i / 64 == 2) {
            if (x < 7) {
                char c = grid[x + 1][y];
                if (c == 'I')adj[i].pb(pair(i + 8, "XF"));
                else if (c == '.' || c == 'D')adj[i].pb(pair(i + 8, "F"));
            }
        } else if (y > 0) {
            char c = grid[x][y - 1];
            if (c == 'I')adj[i].pb(pair(i - 1, "XF"));
            else if (c == '.' || c == 'D')adj[i].pb(pair(i - 1, "F"));
        }
    }
    const string inf = string(1000, ' ');
    set<pair<int, string>, comp> tree;
    rep(0, 120)tree.emplace_hint(tree.end(), i, inf);
    rep(121, 256)tree.emplace_hint(tree.end(), i, inf);
    tree.emplace_hint(tree.begin(), 120, "");
    vs dist(256, inf);
    dist[120] = "";
    while (!tree.empty()) {
        auto [i, curr] = *tree.begin();
        tree.erase(tree.begin());
        int len = sz(curr);
        if (len == 1000) {
            pr("no solution");
            return;
        }
        if (i % 64 == target) {
            pr(curr);
            return;
        }
        for (auto [j, moves]: adj[i]) {
            if (len + sz(moves) < sz(dist[j])) {
                tree.erase(pair(j, dist[j]));
                dist[j] = curr + moves;
                tree.emplace(j, dist[j]);
            }
        }
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