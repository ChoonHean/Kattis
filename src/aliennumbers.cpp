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

inline void solve() {
    string s, source, target;
    cin >> s >> source >> target;
    hmap<char, int> mapper;
    int n = sz(source);
    rep(0, n)mapper[source[i]] = i;
    int num = 0;
    int mul = 1;
    for (auto c = s.rbegin(); c != s.rend(); c++) {
        num += mapper[*c] * mul;
        mul *= n;
    }
    n = sz(target);
    string res;
    while (num) {
        res += target[num % n];
        num /= n;
    }
    for (auto c = res.rbegin(); c != res.rend(); c++)cout << *c;
    cout << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}