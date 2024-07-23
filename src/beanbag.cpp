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

vector<vi> dp;
vi arr;
vi types;
int n, b;

int f(int i, int mask) {
    if (dp[i][mask] != -1)return dp[i][mask];
    if (i == n) {
        int res = 0;
        for (int j = 0; j < b; j++)if (((mask >> j) & 1) == 0)res += types[j];
        return dp[i][mask] = res;
    }
    int res = 0;
    for (int j = 0; j < b; j++)if ((mask >> j) & (arr[i] >> j) & 1)return f(i + 1, mask);
    for (int j = 0; j < b; j++)if ((arr[i] >> j) & 1)res = max(res, f(i + 1, mask | 1 << j));
    return dp[i][mask] = res;
}

inline void solve() {
    int t, x;
    cin >> b;
    arr.resize(b);
    forloop(0, b) {
        cin >> x;
        types.pb(x);
    }
    cin >> n;
    arr.resize(n);
    forloop(0, n) {
        cin >> t;
        while (t--) {
            cin >> x;
            x--;
            arr[i] |= 1 << x;
        }
    }
    dp.assign(n + 1, vi(1 << b, -1));
    p(f(0, 0));
}

int main() {
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}