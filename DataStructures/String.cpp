// From Cp4 (Steven Halim, Felix Halim, Suhendry Effendy)
// https://github.com/stevenhalim/cpbook-code
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
#define rep(i, a, n) for(int i=a;i<n;i++)
string s, t;
int n = 0, m;
vi b(n);

/**
 * Author: Simon Lindholm
 * Date: 2015-03-15
 * License: CC0
 * Source: own work
 * Description: Self-explanatory methods for string hashing.
 * Status: stress-tested
 */
// Arithmetic mod 2^64-1. 2x slower than mod 2^64 and more
// code, but works on evil test data (e.g. Thue-Morse, where
// ABBA... and BAAB... of length 2^10 hash the same mod 2^64).
// "typedef ull H;" instead if you think test data is random,
// or work mod 10^9+7 if the Birthday paradox is not a problem.
struct H {
    ull x;

    H(ull x = 0) : x(x) {}

    H operator+(H o) { return x + o.x + (x + o.x < x); }

    H operator-(H o) { return *this + ~o.x; }

    H operator*(H o) {
        auto m = (__uint128_t) x * o.x;
        return H((ull) m) + (ull) (m >> 64);
    }

    ull get() const { return x + !~x; }

    bool operator==(H o) const { return get() == o.get(); }

    bool operator<(H o) const { return get() < o.get(); }

    friend ostream &operator<<(ostream &os, const H &h) {
        return os << h.get();
    }
};

static const H C = (ll) 1e11 + 3; // (order ~ 3e9; random also ok)

struct HashInterval {
    vector<H> ha, pw;

    HashInterval(string &str) : ha(sz(str) + 1), pw(ha) {
        pw[0] = 1;
        rep(i, 0, sz(str))
            ha[i + 1] = ha[i] * C + str[i],
                    pw[i + 1] = pw[i] * C;
    }

    H hashInterval(int a, int b) { // hash [a, b)
        return ha[b] - ha[a] * pw[b - a];
    }
};

vector<H> getHashes(string &str, int length) {
    if (sz(str) < length) return {};
    H h = 0, pw = 1;
    rep(i, 0, length)h = h * C + str[i], pw = pw * C;
    vector<H> ret = {h};
    rep(i, length, sz(str)) {
        ret.push_back(h = h * C + str[i] - pw * str[i - length]);
    }
    return ret;
}

H hashString(string &s) {
    H h{};
    for (char c: s) h = h * C + c;
    return h;
}

/**
 * Author: 罗穗骞, chilli
 * Date: 2019-04-11
 * License: Unknown
 * Source: Suffix array - a powerful tool for dealing with strings
 * (Chinese IOI National team training paper, 2009)
 * Description: Builds suffix array for a string.
 * \texttt{sa[i]} is the starting index of the suffix which
 * is $i$'th in the sorted suffix array.
 * The returned vector is of size $n+1$, and \texttt{sa[0] = n}.
 * The \texttt{lcp} array contains longest common prefixes for
 * neighbouring strings in the suffix array:
 * \texttt{lcp[i] = lcp(sa[i], sa[i-1])}, \texttt{lcp[0] = 0}.
 * The input string must not contain any nul chars.
 * Time: O(n \log n)
 * Status: stress-tested
 */
struct SuffixArray {
    vi sa, lcp;

    SuffixArray(string s, int lim = 256) { // or vector<int>
        s.push_back(0);
        int n = sz(s), k = 0, a, b;
        vi x(all(s)), y(n), ws(max(n, lim));
        sa = lcp = y, iota(all(sa), 0);
        for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
            p = j, iota(all(y), n - j);
            rep(i, 0, n) if (sa[i] >= j) y[p++] = sa[i] - j;
            fill(all(ws), 0);
            rep(i, 0, n) ws[x[i]]++;
            rep(i, 1, lim) ws[i] += ws[i - 1];
            for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
            swap(x, y), p = 1, x[sa[0]] = 0;
            rep(i, 1, n) a = sa[i - 1], b = sa[i], x[b] =
                        (y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
        }
        for (int i = 0, j; i < n - 1; lcp[x[i++]] = k)
            for (k &&k--, j = sa[x[i] - 1];
                    s[i + k] == s[j + k];
        k++);
    }
};

auto cmp = [&](int a, int n, int m, string &s, string &str) -> int {
    rep(i, 0, m) {
        if (i + a >= n)return -1;
        if (s[i + a] < str[i])return -1;
        if (s[i + a] > str[i])return 1;
    }
    return 0;
};

/**
 * Author: User adamant on CodeForces
 * Source: http://codeforces.com/blog/entry/12143
 * Description: For each position in a string, computes p[0][i] = half length of
 *  longest even palindrome around pos i, p[1][i] = longest odd (half rounded down).
 * Time: O(N)
 * Status: Stress-tested
 */
array<vi, 2> manacher(const string &s) {
    int n = sz(s);
    array<vi, 2> p = {vi(n + 1), vi(n)};
    rep(z, 0, 2) for (int i = 0, l = 0, r = 0; i < n; i++) {
            int t = r - i + !z;
            if (i < r) p[z][i] = min(t, p[z][l + t]);
            int L = i - p[z][i], R = i + p[z][i] - !z;
            while (L >= 1 && R + 1 < n && s[L - 1] == s[R + 1])
                p[z][i]++, L--, R++;
            if (R > r) l = L, r = R;
        }
    return p;
}

void kmppreprocess() {                           // call this first
    int i = 0, j = -1;
    b[0] = -1;                  // starting values
    while (i < m) {                                // pre-process p
        while ((j >= 0) && (t[i] != t[j])) j = b[j]; // different, reset j
        ++i;
        ++j;                                    // same, advance both
        b[i] = j;
    }
}

int kmpSearch() {                               // similar as above
    int freq = 0;
    int i = 0, j = 0;                              // starting values
    while (i < n) {                                // search through t
        while ((j >= 0) && (s[i] != t[j])) j = b[j]; // if different, reset j
        ++i;
        ++j;                                    // if same, advance both
        if (j == m) {                                // a match is found
            ++freq;
            j = b[j];                                  // prepare j for the next
        }
    }
    return freq;
}

const int p = 131, mod = 1e9 + 7;

inline void computePower(vi &power) {
    power[0] = 1;                                    // compute p^i % M
    for (int i = 1; i < (int) power.size(); ++i)                    // O(n)
        power[i] = ((ll) power[i - 1] * p) % mod;
}

inline void computeRollingHash(string &s, vi &h, vi &power) {                      // Overall: O(n)
    h[0] = 0;
    for (int i = 0; i < (int) h.size(); ++i) {                  // O(n)
        if (i != 0) h[i] = h[i - 1];                   // rolling hash
        h[i] = (((ll) h[i] * p) % mod + s[i]) % mod;
    }
}

inline int hash_fast(int L, int R, vi &h, vi &power) {                    // O(1) hash of any substr
    if (L == 0) return h[R];                       // h is the prefix hashes
    int ans = 0;
    ans = (h[R] - (ll) h[L - 1] * power[R - L + 1]) % mod;           // compute differences
    return (ans + mod) % mod;
}

void findPalindromes() {
    cin >> s;
    n = sz(s);
    string r = s;
    reverse(all(r));//pos i goes to n-1-i
    vi pow(n), h1(n), h2(n);
    computePower(pow);
    computeRollingHash(s, h1, pow);
    computeRollingHash(r, h2, pow);
    vi pal(n);
    rep(i, 0, n) {
        int &lo = pal[i];
        int hi = min(i + 1, n - 1 - i);
        while (lo < hi) {
            int mid = (lo + hi + 1) >> 1;
            if (hash_fast(i - mid + 1, i + mid, h1, pow) ==
                hash_fast(n - 1 - i - mid, n - 1 - i + mid - 1, h2, pow))
                lo = mid;
            else hi = mid - 1;
        }
    }
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