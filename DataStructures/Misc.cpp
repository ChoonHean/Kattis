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

inline ll crt(ll a, ll b, int m1, int m2) {
    int x1, x2;
    euclid(m1, m2, x1, x2);
    return b * x1 * m1 + a * x2 * m2;
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

const int N = 14001;
bitset<N + 1> prime;
vl primes;

void sieve() {
    prime.set();
    for (int i = 2; i <= N; i++) {
        if (prime[i]) {
            for (ll j = 1LL * i * i; j <= N; j += i)prime[j] = 0;
            primes.pb(i);
        }
    }
}

vi primeFactors(int n) {
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

vs split(string s, char delim) {
    vs res;
    int pos = 0, prev = 0;
    while (true) {
        pos = s.find(delim, prev);
        res.pb(s.substr(prev, pos - prev));
        if (pos == string::npos)break;
        prev = pos + 1;
    }
    return res;
}