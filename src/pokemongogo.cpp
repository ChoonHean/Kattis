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
int n, b, done;
vector<vector<pair<int, pii>>> arr;

inline int dist(pii p1, pii p2) { return abs(p1.first - p2.first) + abs(p1.second - p2.second); }

int f(int i, int mask, pii curr) {
    if (mask == done)return dist(pair(0, 0), curr);
    if (dp[i][mask] != -1)return dp[i][mask];
    int res = INT_MAX;
    for (int j = 0; j < n; j++)
        if (((mask >> j) & 1) == 0) {
            for (auto [k, next]: arr[j]) {
                res = min(res, dist(next, curr) + f(k, mask | 1 << j, next));
            }
        }
    return dp[i][mask] = res;
}

inline void solve() {
    cin >> b;
    int x, y, counter = 0, stations = 0;
    string s;
    unordered_map<string, int> m;
    arr.resize(15);
    forloop(0, b) {
        cin >> x >> y >> s;
        if (m.contains(s))arr[m[s]].emplace_back(stations++, pair(x, y));
        else {
            arr[counter].emplace_back(stations++, pair(x, y));
            m[s] = counter++;
        }
    }
    n = sz(m);
    done = (1 << n) - 1;
    dp.assign(b + 1, vi(1 << n, -1));
    p(f(b, 0, pair(0, 0)));
}

int main() {
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}