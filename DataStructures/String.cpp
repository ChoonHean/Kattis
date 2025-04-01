// From Cp4 (Steven Halim, Felix Halim, Suhendry Effendy)
// https://github.com/stevenhalim/cpbook-code
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
#define rep(i, a, n) for(int i=a;i<n;i++)
string s, t;
int n = 0, m;
vi b(n);

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