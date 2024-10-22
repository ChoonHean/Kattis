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
    double a, b, c;
    cin >> n;
    vector<vd> arr(n, vd(4));
    for (auto &v: arr) {
        cin >> a >> b;
        v[2] = 2 * a;
        v[3] = -a * a + b;
        double root = sqrt(b);
        v[0] = a - root;
        v[1] = a + root;
    }
    sort(all(arr));
    vd cur(3);
    PQ<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    double res = 0, start = -inf;
    auto f = [&](double end) -> double {
        double x = end;
        double ret = c * x;
        x *= end;
        ret += b * x;
        x *= end;
        return ret + a * x;
    };
    rep(0, n) {
        while (!pq.empty() && pq.top().first <= arr[i][0]) {
            auto [end, idx] = pq.top();
            pq.pop();
            if (sz(pq)) {
                a = cur[0] / 3;
                b = cur[1] / 2;
                c = cur[2];
                res += f(end);
                res -= f(start);
            }
            start = end;
            cur[0]++;
            cur[1] -= arr[idx][2];
            cur[2] -= arr[idx][3];
        }
        if (sz(pq) > 1) {
            a = cur[0] / 3;
            b = cur[1] / 2;
            c = cur[2];
            res += f(arr[i][0]);
            res -= f(start);
        }
        cur[0]--;
        cur[1] += arr[i][2];
        cur[2] += arr[i][3];
        start = arr[i][0];
        pq.push({arr[i][1], i});
    }
    while (sz(pq) >= 2) {
        auto [end, idx] = pq.top();
        pq.pop();
        a = cur[0] / 3;
        b = cur[1] / 2;
        c = cur[2];
        res += f(end);
        res -= f(start);
        start = end;
        cur[0]++;
        cur[1] -= arr[idx][2];
        cur[2] -= arr[idx][3];
    }
    cout << fixed << setprecision(10) << res;
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