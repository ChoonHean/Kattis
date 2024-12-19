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
typedef tree<pair<int, ll>, null_type, greater<pair<int, ll>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int inf = 1e9;
const int mod = 998244353;
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
inline void solve() {
    int r, c, n;
    cin >> r >> c >> n;
    vvi arr(r, vi(c));
    rep(0, r)readarr(c, arr[i]);
    vvi pass(r, vi(c));
    rep(1, r - 1)
        for (int j = 1; j < c - 1; j++) {
            if (arr[i - 1][j] <= arr[i][j])continue;
            if (arr[i + 1][j] <= arr[i][j])continue;
            if (arr[i][j - 1] >= arr[i][j] || arr[i][j - 1] == -1)continue;
            if (arr[i][j + 1] >= arr[i][j] || arr[i][j + 1] == -1)continue;
            pass[i][j] = 1;
        }
    vvi dp(r, vi(n + 2, inf));
    rep(0, r)if (arr[i][0] != -1)dp[i][0] = arr[i][0];
    for (int j = 0; j < c - 1; j++) {
        vvi ndp(r, vi(n + 2, inf));
        for (int k = 0; k <= n; k++) {
            if (arr[0][j + 1] != -1)ndp[0][k] = min(ndp[0][k], dp[0][k] + arr[0][j + 1]);
            int l = pass[1][j + 1];
            if (arr[1][j + 1] != -1)ndp[1][k + l] = min(ndp[1][k + l], dp[0][k] + arr[1][j + 1]);
            rep(1, r - 1) {
                l = pass[i - 1][j + 1];
                if (arr[i - 1][j + 1] != -1)ndp[i - 1][k + l] = min(ndp[i - 1][k + l], dp[i][k] + arr[i - 1][j + 1]);
                l = pass[i][j + 1];
                if (arr[i][j + 1] != -1)ndp[i][k + l] = min(ndp[i][k + l], dp[i][k] + arr[i][j + 1]);
                l = pass[i + 1][j + 1];
                if (arr[i + 1][j + 1] != -1)ndp[i + 1][k + l] = min(ndp[i + 1][k + l], dp[i][k] + arr[i + 1][j + 1]);
            }
            l = pass[r - 2][j + 1];
            if (arr[r - 2][j + 1] != -1)ndp[r - 2][k + l] = min(ndp[r - 2][k + l], dp[r - 1][k] + arr[r - 2][j + 1]);
            if (arr[r - 1][j + 1] != -1)ndp[r - 1][k] = min(ndp[r - 1][k], dp[r - 1][k] + arr[r - 1][j + 1]);
        }
        swap(dp, ndp);
    }
    int res = inf;
    for (auto &v: dp)res = min(res, v[n]);
    if (res == inf)cout << "impossible";
    else cout << res;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
//    cin >> t;
    while (t--) solve();
    return 0;
}