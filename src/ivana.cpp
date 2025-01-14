#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef vector<int> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
typedef vector<double> vd;
typedef vector <vd> vvd;
typedef vector<bool> vb;
typedef vector <vb> vvb;
typedef vector <string> vs;
typedef vector<char> vc;
typedef long long ll;
typedef long double ld;
typedef vector <ll> vl;
typedef vector <vl> vvl;
typedef vector <vvl> vvvl;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair <ll, ll> pll;
typedef vector <pii> vpii;
typedef vector <vpii> vvpii;
typedef vector <pll> vpll;
typedef vector <pdd> vpdd;
typedef tree <pair<int, int>, null_type, less<pair < int, int>>, rb_tree_tag, tree_order_statistics_node_update>
ordered_set;
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
inline void pr(pair <T, U> pa) {
    cout << '(';
    pr(pa.first);
    cout << ',';
    pr(pa.second);
    cout << ") ";
}

template<typename T>
inline void pr(vector <T> v) {
    for (auto i: v) pr(i);
    cout << nl;
}

template<typename T>
inline void pr(set <T> s) {
    for (auto t: s)pr(t);
    cout << nl;
}

template<typename T>
inline void pr(unordered_set <T> s) {
    for (auto t: s)pr(t);
    cout << nl;
}

template<typename T, typename U>
inline void pr(map <T, U> m) {
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
inline void pr(unordered_map <T, U> m) {
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
inline void pr(queue <T> q) {
    queue <T> copy(q);
    while (!copy.empty()) {
        pr(copy.front());
        copy.pop();
    }
    cout << nl;
}

template<typename T>
inline void pr(stack <T> s) {
    stack <T> copy(s);
    while (!copy.empty()) {
        pr(copy.top());
        copy.pop();
    }
    cout << nl;
}

template<typename T>
inline void pr(deque <T> q) {
    deque <T> copy(q);
    while (!copy.empty()) {
        pr(copy.top());
        copy.pop();
    }
    cout << nl;
}

template<typename T>
inline void pr(PQ <T> pq) {
    PQ <T> copy(pq);
    vector <T> arr;
    while (!copy.empty()) {
        arr.pb(copy.top());
        copy.pop();
    }
    pr(arr);
    cout << nl;
}

template<typename T>
inline void pr(PQ <T, vector<T>, greater<T>> pq) {
    auto copy(pq);
    vector <T> arr;
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

inline vvl matmul(int n, vvl &a, vvl &b, int m) {
    vvl res(n, vl(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % m;
            }
        }
    }
    return res;
}

inline vvl matpow(int n, vvl &a, ll p, int m) {
    vvl res(n, vl(n));
    for (int i = 0; i < n; i++)res[i][i] = 1;
    vvl b(a);
    while (p) {
        if (p & 1)res = matmul(n, res, b, m);
        b = matmul(n, b, b, m);
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
    int n;
    cin >> n;
    read(n);
    vvvi dp(2, vvi(n, vi(n, -1)));
    auto f = [&](auto &self, int t, int l, int r) -> int {
        if (dp[t][l][r] != -1)return dp[t][l][r];
        if (l == r)return t ? arr[l] % 2 : 0;
        if (t)
            return dp[t][l][r] = max(arr[l] % 2 + self(self, 0, (l + 1) % n, r),
                                     arr[r] % 2 + self(self, 0, l, (r - 1 + n) % n));
        else return dp[t][l][r] = min(self(self, 1, (l + 1) % n, r),
                                      self(self, 1, l, (r - 1 + n) % n));
    };
    int res = 0, odd = 0;
    for (int &i: arr)if (i % 2)odd++;
    rep(0, n)if (((f(f, 0, (i + 1) % n, (i - 1 + n) % n) + arr[i] % 2) << 1) > odd)res++;
    cout << res;
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