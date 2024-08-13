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

const int N = 2000;

inline void solve() {
    int n1, n2, m1, m2, u, v;
    cin >> n1 >> n2 >> m1 >> m2;
    vvi adj1(n1), adj2(n2);
    vi indeg1(n1), indeg2(n2);
    rep(0, m1) {
        cin >> u >> v;
        adj1[--u].pb(--v);
        indeg1[v]++;
    }
    rep(0, m2) {
        cin >> u >> v;
        adj2[--u].pb(--v);
        indeg2[v]++;
    }
    queue<int> q;
    q.push(0);
    vector<bitset<N>> dp1(n1), dp2(n2);
    dp1[0][0] = 1;
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        for (int j: adj1[i]) {
            dp1[j] |= dp1[i] << 1;
            if (!--indeg1[j])q.push(j);
        }
    }
    q.push(0);
    dp2[0][0] = 1;
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        for (int j: adj2[i]) {
            dp2[j] |= dp2[i] << 1;
            if (!--indeg2[j])q.push(j);
        }
    }
    cin >> u;
    bitset<N> a = dp1.back(), b = dp2.back();
    while (u--) {
        cin >> v;
        bool done = false;
        rep(0, min(v + 1, n1)) {
            if (a[i] & b[v - i]) {
                done = true;
                pnl("Yes");
                break;
            }
        }
        if (!done)pnl("No");
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