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
#define all(a) a.begin(),a.end()

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

inline int nextp(int n) {
    int t = n | (n - 1);
    return (t + 1) | (((~t & -~t) - 1) >> (countr_zero((ull) n) + 1));
}
/**
 * Author: Ulf Lundstrom
 * Date: 2009-04-17
 * License: CC0
 * Source: Numeriska algoritmer med matlab, Gerd Eriksson, NADA, KTH
 * Description: Finds the argument minimizing the function $f$ in the interval $[a,b]$
 * assuming $f$ is unimodal on the interval, i.e. has only one local minimum and no local
 * maximum. The maximum error in the result is $eps$. Works equally well for maximization
 * with a small change in the code. See TernarySearch.h in the Various chapter for a
 * discrete version.
 * Usage:
	double func(double x) { return 4+x+.3*x*x; }
	double xmin = gss(-1000,1000,func);
 * Time: O(\log((b-a) / \epsilon))
 * Status: tested
 */
#pragma once

/// It is important for r to be precise, otherwise we don't necessarily maintain the inequality a < x1 < x2 < b.
double gss(double a, double b, double (*f)(double)) {
    double r = (sqrt(5) - 1) / 2, eps = 1e-7;
    double x1 = b - r * (b - a), x2 = a + r * (b - a);
    double f1 = f(x1), f2 = f(x2);
    while (b - a > eps)
        if (f1 < f2) { //change to > to find maximum
            b = x2;
            x2 = x1;
            f2 = f1;
            x1 = b - r * (b - a);
            f1 = f(x1);
        } else {
            a = x1;
            x1 = x2;
            f1 = f2;
            x2 = a + r * (b - a);
            f2 = f(x2);
        }
    return a;
}

/**
 * Author: Ludo Pulles, chilli, Simon Lindholm
 * Date: 2019-01-09
 * License: CC0
 * Source: http://neerc.ifmo.ru/trains/toulouse/2017/fft2.pdf (do read, it's excellent)
   Accuracy bound from http://www.daemonology.net/papers/fft.pdf
 * Description: fft(a) computes $\hat f(k) = \sum_x a[x] \exp(2\pi i \cdot k x / N)$ for all $k$. N must be a power of 2.
   Useful for convolution:
   \texttt{conv(a, b) = c}, where $c[x] = \sum a[i]b[x-i]$.
   For convolution of complex numbers or more than two vectors: FFT, multiply
   pointwise, divide by n, reverse(start+1, end), FFT back.
   Rounding is safe if $(\sum a_i^2 + \sum b_i^2)\log_2{N} < 9\cdot10^{14}$
   (in practice $10^{16}$; higher for random inputs).
   Otherwise, use NTT/FFTMod.
 * Time: O(N \log N) with $N = |A|+|B|$ ($\tilde 1s$ for $N=2^{22}$)
 * Status: somewhat tested
 * Details: An in-depth examination of precision for both FFT and FFTMod can be found
 * here (https://github.com/simonlindholm/fft-precision/blob/master/fft-precision.md)
 */

typedef complex<double> C;
typedef vector<double> vd;

void fft(vector<C> &a) {
    int n = sz(a), L = 31 - __builtin_clz(n);
    static vector<complex<long double>> R(2, 1);
    static vector<C> rt(2, 1);  // (^ 10% faster if double)
    for (static int k = 2; k < n; k *= 2) {
        R.resize(n);
        rt.resize(n);
        auto x = polar(1.0L, acos(-1.0L) / k);
        rep(i, k, 2 * k) rt[i] = R[i] = i & 1 ? R[i / 2] * x : R[i / 2];
    }
    vi rev(n);
    rep(i, 0, n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    rep(i, 0, n) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int k = 1; k < n; k *= 2)
        for (int i = 0; i < n; i += 2 * k)
            rep(j, 0, k) {
                // C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  /// include-line
                auto x = (double *) &rt[j + k], y = (double *) &a[i + j + k];        /// exclude-line
                C z(x[0] * y[0] - x[1] * y[1], x[0] * y[1] + x[1] * y[0]);           /// exclude-line
                a[i + j + k] = a[i + j] - z;
                a[i + j] += z;
            }
}

vd conv(const vd &a, const vd &b) {
    if (a.empty() || b.empty()) return {};
    vd res(sz(a) + sz(b) - 1);
    int L = 32 - __builtin_clz(sz(res)), n = 1 << L;
    vector<C> in(n), out(n);
    copy(all(a), begin(in));
    rep(i, 0, sz(b)) in[i].imag(b[i]);
    fft(in);
    for (C &x: in) x *= x;
    rep(i, 0, n) out[i] = in[-i & (n - 1)] - conj(in[i]);
    fft(out);
    rep(i, 0, sz(res)) res[i] = imag(out[i]) / (4 * n);
    return res;
}

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

const int N = 31624;
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

hmap<int, int> primeFactors(ll n) {
    hmap<int, int> factors;
    for (ll div: primes) {
        while (n % div == 0)n /= div, factors[div]++;
        if (div * div > n)break;
    }
    if (n != 1)factors[n]++;
    return factors;
}

int eulerTot(int n) {
    int res = n;
    for (const ll &i: primes) {
        if (n % i == 0) {
            res -= res / i;
            n /= i;
            while (n % i == 0)n /= i;
        }
    }
    if (n > 1)res -= res / n;
    return res;
}

vi phi(N + 1);

void eulerTotN() {
    iota(all(phi), 0);
    for (int i = 2; i <= N; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= N; j += i)phi[j] -= phi[j] / i;
        }
    }
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
    if (n < 2)return false;
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

int solveLinear(vector<vd> &A, vd &b, vd &x) {
    int n = sz(A), m = sz(x), rank = 0, br, bc;
    if (n) assert(sz(A[0]) == m);
    vi col(m);
    iota(all(col), 0);

    rep(i, 0, n) {
        double v, bv = 0;
        rep(r, i, n) rep(c, i, m)
                if ((v = fabs(A[r][c])) > bv)
                    br = r, bc = c, bv = v;
        if (bv <= eps) {
            rep(j, i, n) if (fabs(b[j]) > eps) return -1;
            break;
        }
        swap(A[i], A[br]);
        swap(b[i], b[br]);
        swap(col[i], col[bc]);
        rep(j, 0, n) swap(A[j][i], A[j][bc]);
        bv = 1 / A[i][i];
        rep(j, i + 1, n) {
            double fac = A[j][i] * bv;
            b[j] -= fac * b[i];
            rep(k, i + 1, m) A[j][k] -= fac * A[i][k];
        }
        rank++;
    }

    x.assign(m, 0);
    for (int i = rank; i--;) {
        b[i] /= A[i][i];
        x[col[i]] = b[i];
        rep(j, 0, i) b[j] -= A[j][i] * b[i];
    }
    return rank; // (multiple solutions if rank < m)
}