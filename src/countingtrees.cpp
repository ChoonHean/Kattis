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

vi fac3{1, 1, 2}, fac11(11, 1), fac101(101, 1);
vl fac(3000301, 1);
vi arr{3, 11, 101, 3000301}; //1e10+3233 = 3*11*101*3000301
ll M = 1e10 + 3233;

inline void solve() {
    ll n, k, c;
    cin >> n >> k >> c;
    --n;
    --c;
    if (c > n) {
        pnl(0);
        return;
    }
    c = min(c, n - c);
    vi mods;
    for (ll m: arr) {
        ll a = n, b = c, res = 1;
        while (a && b) {
            int x = a % m, y = b % m;
            if (y > x) {
                res = 0;
                break;
            }
            if (m == 3)res = res * fac3[x] * fac3[y] * fac3[x - y] % m;
            else if (m == 11)res = res * fac11[x] * binpow(fac11[y], m - 2, m) * binpow(fac11[x - y], m - 2, m) % m;
            else if (m == 101)
                res = res * fac101[x] % m * binpow(fac101[y], m - 2, m) % m * binpow(fac101[x - y], m - 2, m) % m;
            else res = res * fac[x] % m * binpow(fac[y], m - 2, m) % m * binpow(fac[x - y], m - 2, m) % m;
            a /= m, b /= m;
        }
        mods.pb(res);
    }
    ll res = (mods[1] * 12 - mods[0] * 11) % 33; //4 * 3 - 1 * 11 = 12 - 11 = 1
    res = (mods[2] * 1617 - res * 1616) % 3333; //49 * 33 - 16 * 101 = 1617 - 1616 = 1
    res = res * 4908492436LL % M -
          mods[3] * 4908492435LL % M; //-1472695 * 3333 + 1636 * 3000301 = 4908492436 - 4908492435 = 1
    while (res < 0)res += M;
    res %= M;
    pnl((res << 1) % M);
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    rep(2, 11) {
        fac11[i] = (fac11[i - 1] * i) % 11;
        fac101[i] = (fac101[i - 1] * i) % 101;
        fac[i] = (fac[i - 1] * i) % 3000301;
    }
    rep(11, 101) {
        fac101[i] = (fac101[i - 1] * i) % 101;
        fac[i] = (fac[i - 1] * i) % 3000301;
    }
    rep(101, 3000301)fac[i] = (fac[i - 1] * i) % 3000301;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
