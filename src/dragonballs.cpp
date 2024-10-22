#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
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
typedef vector<vpii> vvpii;
typedef vector<pll> vpll;
typedef vector<pdd> vpdd;
typedef tree<pair<int, ll>, null_type, greater<pair<int, ll>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int inf = 1e9;
const int mod = 1e9 + 7;
#define all(a) a.begin(),a.end()
#define read(n) vi arr(n);for(int _=0;_<n;_++)cin>>arr[_]
#define readarr(n, arr) for(int _=0;_<n;_++)cin>>arr[_]
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
#define lsb(i) (i&-i)
mt19937_64 rnd(time(0));


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
        cout << '(';
        pr(t);
        pr('-');
        pr(u);
        pr(')');
    }
    cout << nl;
}

template<typename T, typename U>
inline void pr(unordered_map<T, U> m) {
    for (auto [t, u]: m) {
        cout << '(';
        pr(t);
        pr('-');
        pr(u);
        pr(')');
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

inline int euclid(int a, int b, int &x, int &y) { // pass x and y by ref
    int xx = y = 0;
    int yy = x = 1;
    while (b) { // repeats until b == 0
        int q = a / b;
        int t = b;
        b = a % b;
        a = t;
        t = xx;
        xx = x - q * xx;
        x = t;
        t = yy;
        yy = y - q * yy;
        y = t;
    }
    return a; // returns gcd(a, b)
}

inline ll binpow(ll a, int p, int m) {
    ll res = 1;
    while (p) {
        if (p & 1)res = (res * a) % m;
        a = (a * a) % m;
        p >>= 1;
    }
    return res;
}

inline void solve() {
    int n;
    cin >> n;
    hmap<ll, int> squares;
    squares[1] = 1;
    ll prev = 1;
    vl d{0, 1};
    for (ll i = 2; i < 500001; i++) {
        ll j = i * i;
        squares[j] = i;
        d.pb(j - prev);
        prev = j;
    }
    auto ask = [](int x, int y) -> void {
        cout << x << ' ' << y << endl;
    };
    while (n--) {
        int x = 5e5, y = 5e5;
        ll start, dist;
        ask(x, y);
        cin >> start;
        if (!start)continue;
        if (squares.contains(start)) {
            int a = squares[start];
            ask(x - a, y);
            cin >> dist;
            if (!dist)continue;
            ask(x + a, y);
            cin >> dist;
            if (!dist)continue;
            ask(x, y - a);
            cin >> dist;
            if (!dist)continue;
            ask(x, y + a);
            cin >> dist;
            if (!dist)continue;
        }
        ask(x - 1, y);
        cin >> dist;
        if (dist < start) {
            ll diff = start - dist;
            ll dx = lower_bound(all(d), diff) - d.begin();
            ll dy = squares[start - dx * dx];
            ask(x - dx, y - dy);
            cin >> dist;
            if (!dist)continue;
            ask(x - dx, y + dy);
            cin >> dist;
            if (!dist)continue;
        }
        ask(x + 1, y);
        cin >> dist;
        if (dist < start) {
            ll diff = start - dist;
            ll dx = lower_bound(all(d), diff) - d.begin();
            ll dy = squares[start - dx * dx];
            ask(x + dx, y - dy);
            cin >> dist;
            if (!dist)continue;
            ask(x + dx, y + dy);
            cin >> dist;
            if (!dist)continue;
        }
        ask(x, y + 1);
        cin >> dist;
        if (dist < start) {
            ll diff = start - dist;
            ll dy = lower_bound(all(d), diff) - d.begin();
            ll dx = squares[start - dy * dy];
            ask(x + dx, y + dy);
            cin >> dist;
            if (!dist)continue;
            ask(x - dx, y + dy);
            cin >> dist;
            if (!dist)continue;
        }
        ask(x, y - 1);
        cin >> dist;
        if (dist < start) {
            ll diff = start - dist;
            ll dy = lower_bound(all(d), diff) - d.begin();
            ll dx = squares[start - dy * dy];
            ask(x + dx, y - dy);
            cin >> dist;
            if (!dist)continue;
            ask(x - dx, y - dy);
            cin >> dist;
            if (!dist)continue;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}