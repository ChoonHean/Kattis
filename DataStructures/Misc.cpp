#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<string> vs;
#define pb push_back
#define rep(i, a, n) for(int i=a;i<n;i++)

struct mint {
    static constexpr int m = 998244353;
    int x;

    mint() : x(0) {}

    mint(long long x_) : x(x_ % m) { if (x < 0) x += m; }

    int val() { return x; }

    mint &operator+=(mint b) {
        if ((x += b.x) >= m) x -= m;
        return *this;
    }

    mint &operator-=(mint b) {
        if ((x -= b.x) < 0) x += m;
        return *this;
    }

    mint &operator*=(mint b) {
        x = (long long) (x) * b.x % m;
        return *this;
    }

    mint pow(long long e) const {
        mint r = 1, b = *this;
        while (e) {
            if (e & 1) r *= b;
            b *= b;
            e >>= 1;
        }
        return r;
    }

    mint inv() { return pow(m - 2); }

    mint &operator/=(mint b) { return *this *= b.pow(m - 2); }

    friend mint operator+(mint a, mint b) { return a += b; }

    friend mint operator-(mint a, mint b) { return a -= b; }

    friend mint operator/(mint a, mint b) { return a /= b; }

    friend mint operator*(mint a, mint b) { return a *= b; }

    friend bool operator==(mint a, mint b) { return a.x == b.x; }

    friend bool operator!=(mint a, mint b) { return a.x != b.x; }

    friend ostream &operator<<(ostream &os, const mint &a) {
        os << a.x;
        return os;
    }
};

inline int euclid(int a, int b, int &x, int &y) { // pass x and y by ref
    int xx = y = 0;
    int yy = x = 1;
    while (b) {                                    // repeats until b == 0
        int q = a / b;
        tie(a, b) = tuple(b, a % b);
        tie(x, xx) = tuple(xx, x - q * xx);
        tie(y, yy) = tuple(yy, y - q * yy);
    }
    return a; // returns gcd(a, b)
}

inline ll crt(ll a, ll b, int m1, int m2) {
    int x1, x2;
    euclid(m1, m2, x1, x2);
    return b * x1 * m1 + a * x2 * m2;
}

inline ll binpow(ll a, ll p, int m) {
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

const int N = 14001;
bitset<N + 1> prime;
vl primes;
vi minPrimeFac(N + 1);

void sieve() {
    prime.set();
    for (ll i = 2; i <= N; i++) {
        if (prime[i]) {
            for (ll j = i * i; j <= N; j += i)prime[j] = 0;
            primes.pb(i);
        }
    }
}

void linSieve() {
    for (int i = 2; i <= N; i++) {
        if (minPrimeFac[i] == 0) {
            minPrimeFac[i] = i;
            primes.pb(i);
        }
        for (int j = 0; i * primes[j] <= N; j++) {
            minPrimeFac[i * primes[j]] = primes[j];
            if (primes[j] == minPrimeFac[i])break;
        }
    }
}

vi primeFactors(ll n) {
    vi factors;
    for (ll div: primes) {
        if (n % div == 0) {
            factors.pb(div);
            n /= div;
            while (n % div == 0)n /= div;
        }
        if (div * div > n)break;
    }
    if (n != 1)factors.pb(n);
    return factors;
}

inline ll binpow2(ll n, ll p, ll m) {
    __int128 res = 1, a = n;
    while (p) {
        if (p & 1)res = (res * a) % m;
        a = (a * a) % m;
        p >>= 1;
    }
    return res;
}

inline bool is_composite(ll n, ll a, ll d, int s) {
    __int128 x = binpow2(a, d, n);
    if (x == 1 || x == n - 1)return false;
    rep(i, 0, s) {
        x = (x * x) % n;
        if (x == n - 1)return false;
    }
    return true;
}

inline bool miller_rabin(ll n) {
    vi tests{2, 3, 5, 7};
    if (n >= 3215031751LL) tests = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    ll d = n - 1;
    int s = 0;
    while (!(d & 1))d >>= 1, s++;
    for (const int &a: tests) {
        if (a > n - 1)break;
        if (is_composite(n, a, d, s))return false;
    }
    return true;
}

