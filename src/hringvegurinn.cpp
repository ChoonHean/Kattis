#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef long long ll;
typedef long double ld;
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
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int inf = 1e9;
const int mod = 1e9 + 7;
#define all(a) a.begin(),a.end()
#define read(n) vi arr(n);for(int&_:arr)cin>>_
#define readarr(n, arr) for(auto&_:arr)cin>>_
#define rep(a, n) for(int i=a;i<n;i++)
#define nl "\n"
#define sz(v) ((int)v.size())
#define PQ priority_queue
#define hmap unordered_map
#define hset unordered_set
#define pb push_back
#define lb lower_bound
#define ub upper_bound
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
inline void pr(deque<T> q) {
    deque<T> copy(q);
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

//const int N=14001;
//bitset<N+1>prime;
//vl primes;
//void sieve() {
//    prime.set();
//    for(int i=2;i<=N;i++) {
//        if(prime[i]){
//            for(ll j=1LL*i*i;j<=N;j+=i)prime[j]=0;
//            primes.pb(i);
//        }
//    }
//}
//
//vi primeFactors(int n) {
//    vi factors;
//    for (ll div: primes) {
//        if(n % div == 0) {
//            factors.pb(div);
//            n /= div;
//            while(n%div==0)n/=div;
//        }
//        if (div * div > n)break;
//    }
//    if (n != 1)factors.pb(n);
//    return factors;
//}
struct FT {                              // index 0 is not used
    vl ft;                                        // internal FT is an array
    FT(int m) { ft.assign(m + 1, 0); }      // create an empty FT

    inline void build(const vl &f) {
        int m = (int) f.size() - 1;                     // note f[0] is always 0
        ft.assign(m + 1, 0);
        for (int i = 1; i <= m; ++i) {               // O(m)
            ft[i] += f[i];                             // add this value
            if (i + lsb(i) <= m)                       // i has parent
                ft[i + lsb(i)] += ft[i];                 // add to that parent
        }
    }

    inline FT(const vl &f) { build(f); }        // create FT based on f

    inline FT(int m, const vi &s) {              // create FT based on s
        vl f(m + 1, 0);
        for (int i = 0; i < (int) s.size(); ++i)      // do the conversion first
            ++f[s[i]];                                 // in O(n)
        build(f);                                    // in O(m)
    }

    inline ll rsq(int j) {                                // returns RSQ(1, j)
        ll sum = 0;
        for (; j; j -= lsb(j))
            sum += ft[j];
        return sum;
    }

    inline ll rsq(int i, int j) { return rsq(j) - rsq(i - 1); } // inc/exclusion

    // updates value of the i-th element by v (v can be +ve/inc or -ve/dec)
    inline void update(int i, ll v) {
        for (; i < (int) ft.size(); i += lsb(i))
            ft[i] += v;
    }

    int select(ll k) {                             // O(log m)
        int p = 1;
        while (p * 2 < (int) ft.size()) p *= 2;
        int i = 0;
        while (p) {
            if (k > ft[i + p]) {
                k -= ft[i + p];
                i += p;
            }
            p /= 2;
        }
        return i + 1;
    }
};

struct RUPQ {                                     // RUPQ variant
    FT ft;                                // internally use PURQ FT
    RUPQ(int m) : ft(FT(m)) {}

    inline void range_update(int ui, int uj, ll v) {
        ft.update(ui, v);                            // [ui, ui+1, .., m] +v
        ft.update(uj + 1, -v);                         // [uj+1, uj+2, .., m] -v
    }                                              // [ui, ui+1, .., uj] +v
    inline ll point_query(int i) { return ft.rsq(i); }    // rsq(i) is sufficient
};

struct RURQ {                                    // RURQ variant
    RUPQ rupq;                                     // one RUPQ and
    FT purq;                              // one PURQ
    RURQ(int m) : rupq(RUPQ(m)), purq(FT(m)) {} // initialization
    inline void range_update(int ui, int uj, ll v) {
        rupq.range_update(ui, uj, v);                // [ui, ui+1, .., uj] +v
        purq.update(ui, v * (ui - 1));                   // -(ui-1)*v before ui
        purq.update(uj + 1, -v * uj);                    // +(uj-ui+1)*v after uj
    }

    inline ll rsq(int j) {
        return rupq.point_query(j) * j -               // optimistic calculation
               purq.rsq(j);                          // cancelation factor
    }

    inline ll rsq(int i, int j) { return rsq(j) - rsq(i - 1); } // standard
};

inline void solve() {
    int n, q, x, l, r, c, add = 0;
    cin >> n >> q;
    RURQ ft(n);
    auto shift = [&](int &x, int &y, int a) -> void {
        x += a;
        y += a;
        if (x > n)x -= n;
        if (y > n)y -= n;
    };
    while (q--) {
        cin >> c;
        if (c == 1) {
            cin >> x;
            add = (add + x) % n;
        } else if (c == 2) {
            cin >> l >> r >> x;
            if (l <= r) {
                shift(l, r, add);
                if (l <= r)ft.range_update(l, r, x);
                else {
                    ft.range_update(l, n, x);
                    ft.range_update(1, r, x);
                }
            } else {
                swap(l, r);
                shift(l, r, add);
                if (r <= l)ft.range_update(r, l, x);
                else {
                    ft.range_update(r, n, x);
                    ft.range_update(1, l, x);
                }
            }
        } else {
            cin >> l >> r;
            if (l <= r) {
                shift(l, r, add);
                if (l <= r)pnl(ft.rsq(l, r));
                else pnl(ft.rsq(l, n) + ft.rsq(1, r));
            } else {
                swap(l, r);
                shift(l, r, add);
                if (r <= l)pnl(ft.rsq(r, l));
                else pnl(ft.rsq(r, n) + ft.rsq(1, l));
            }
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}