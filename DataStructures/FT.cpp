// From CP4 (Steven Halim, Felix Halim, Suhendry Effendy)
// https://github.com/stevenhalim/cpbook-code

#include <bits/stdc++.h>

using namespace std;

#define lsb(S) ((S) & -(S))                    // the key operation

typedef long long ll;                            // for extra flexibility
typedef vector<ll> vl;
typedef vector<int> vi;

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
        while (p*2 < (int)ft.size()) p *= 2;
        int i = 0;
        while (p) {
            if (k > ft[i+p]) {
                k -= ft[i+p];
                i += p;
            }
            p /= 2;
        }
        return i+1;
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

// From mouse_wireless
// https://codeforces.com/blog/entry/64914

/* Example use cases
 * BIT<N, M, K> b; create a N x M x K BIT 
 * b.update(x, y, z, P); add a point with (x,y,z)
 * b.query(x1, x2, y1, y2, z1, z2); 
 */

template <int... ArgsT> struct BIT {
    int val = 0;
    void update(int v) {
        val += v;
    }
    int query() {
        return val;
    }
};
template <int N, int... Ns>
struct BIT<N, Ns...> {
    BIT<Ns...> bit[N + 1];
    template<typename... Args>
    void update(int pos, Args... args) {
        for (; pos <= N; bit[pos].update(args...), pos += lsb(pos));
    }
    template<typename... Args>
    int query(int l, int r, Args... args) {
        int ans = 0;
        for (; r >= 1; ans += bit[r].query(args...), r -= lsb(r));
        for (--l; l >= 1; ans -= bit[l].query(args...), l -= lsb(l));
        return ans;
    }
};