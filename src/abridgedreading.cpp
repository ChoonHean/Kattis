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

template<typename T>
inline void p(stack<T> s) {
    stack<T> copy(s);
    while (!copy.empty()) {
        p(copy.top());
        copy.pop();
    }
    cout << nl;
}

const int N = 1000;
vector<bitset<N>> arr;
vi adj;

bitset<N> dfs(int n) {
    if (arr[n].any())return arr[n];
    arr[n].set(n);
    if (adj[n] == -1)return arr[n];
    arr[n] |= dfs(adj[n]);
    return arr[n];
}

inline void solve() {
    int n, m, u, v;
    cin >> n >> m;
    vi pages(n), indeg(n);
    readarr(n, pages);
    arr.resize(n);
    adj.assign(n, -1);
    while (m--) {
        cin >> v >> u;
        v--;
        adj[u - 1] = v;
        indeg[v]++;
    }
    vector<bitset<N>> chapters;
    forloop(0, n)
        if (indeg[i] == 0) {
            dfs(i);
            chapters.pb(arr[i]);
        }
    int res = INT_MAX;
    forloop(0, sz(chapters))
        for (int j = i + 1; j < sz(chapters); j++) {
            int curr = 0;
            bitset<N> set = chapters[i] | chapters[j];
            for (int k = 0; k < n; k++)if (set.test(k))curr += pages[k];
            res = min(res, curr);
        }
    p(res);
}

int main() {
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}