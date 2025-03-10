// From CP4 (Steven Halim, Felix Halim, Suhendry Effendy)
// https://github.com/stevenhalim/cpbook-code

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
const ll llinf = -4e18;

#if __cplusplus >= 201703L

template<class S,
        auto op,
        auto e,
        class F,
        auto mapping,
        auto composition,
        auto id>
struct lazy_segtree {
    static_assert(std::is_convertible_v<decltype(op), std::function<S(S, S)>>,
                  "op must work as S(S, S)");
    static_assert(std::is_convertible_v<decltype(e), std::function<S()>>,
                  "e must work as S()");
    static_assert(
            std::is_convertible_v<decltype(mapping), std::function<S(F, S)>>,
            "mapping must work as S(F, S)");
    static_assert(
            std::is_convertible_v<decltype(composition), std::function<F(F, F)>>,
            "composition must work as F(F, F)");
    static_assert(std::is_convertible_v<decltype(id), std::function<F()>>,
                  "id must work as F()");

#else

    template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct lazy_segtree {

#endif

public:
    lazy_segtree() : lazy_segtree(0) {}

    explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}

    explicit lazy_segtree(const std::vector<S> &v) : _n(int(v.size())) {
        size = (int) bit_ceil((unsigned int) (_n));
        log = countr_zero((unsigned int) size);
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template<bool (*g)(S)>
    int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }

    template<class G>
    int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template<bool (*g)(S)>
    int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }

    template<class G>
    int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

    int _n, size, log;
    std::vector<S> d;
    std::vector<F> lz;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }

    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }

    void push(int k) {
        all_apply(k << 1, lz[k]);
        all_apply(k << 1 ^ 1, lz[k]);
        lz[k] = id();
    }
};

#if __cplusplus >= 201703L

template<class S, auto op, auto e>
struct segtree {
    static_assert(std::is_convertible_v<decltype(op), std::function<S(S, S)>>,
                  "op must work as S(S, S)");
    static_assert(std::is_convertible_v<decltype(e), std::function<S()>>,
                  "e must work as S()");

#else

    template <class S, S (*op)(S, S), S (*e)()> struct segtree {

#endif

public:
    segtree() : segtree(0) {}

    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}

    explicit segtree(const std::vector<S> &v) : _n(int(v.size())) {
        size = (int) bit_ceil((unsigned int) (_n));
        log = countr_zero((unsigned int) size);
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }

    template<bool (*f)(S)>
    int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }

    template<class F>
    int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template<bool (*f)(S)>
    int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }

    template<class F>
    int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

struct ST {
    int n;                                         // n = (int)A.size()
    vi A, st, lazy;                                // the arrays

    inline int l(int p) { return p << 1; }                 // go to left child
    inline int r(int p) { return p << 1 ^ 1; }              // go to right child

    inline int conquer(int a, int b) {
        if (a == -1) return b;                       // corner case
        if (b == -1) return a;
        return min(a, b);                            // RMQ
    }

    void build(int p, int L, int R) {              // O(n)
        if (L == R)
            st[p] = A[L];                              // base case
        else {
            int m = (L + R) / 2;
            build(l(p), L, m);
            build(r(p), m + 1, R);
            st[p] = conquer(st[l(p)], st[r(p)]);
        }
    }

    inline void propagate(int p, int L, int R) {
        if (lazy[p] != -1) {                         // has a lazy flag
            st[p] = lazy[p];                           // [L..R] has same value
            if (L != R)                                // not a leaf
                lazy[l(p)] = lazy[r(p)] = lazy[p];       // propagate downwards
            else                                       // L == R, a single index
                A[L] = lazy[p];                          // time to update this
            lazy[p] = -1;                              // erase lazy flag
        }
    }

    int RMQ(int p, int L, int R, int i, int j) {   // O(log n)
        propagate(p, L, R);                          // lazy propagation
        if (i > j) return -1;                        // infeasible
        if ((L >= i) && (R <= j)) return st[p];      // found the segment
        int m = (L + R) / 2;
        return conquer(RMQ(l(p), L, m, i, min(m, j)),
                       RMQ(r(p), m + 1, R, max(i, m + 1), j));
    }

    void update(int p, int L, int R, int i, int j, int val) { // O(log n)
        propagate(p, L, R);                          // lazy propagation
        if (i > j) return;
        if ((L >= i) && (R <= j)) {                  // found the segment
            lazy[p] = val;                             // update this
            propagate(p, L, R);                        // lazy propagation
        } else {
            int m = (L + R) / 2;
            update(l(p), L, m, i, min(m, j), val);
            update(r(p), m + 1, R, max(i, m + 1), j, val);
            int lsubtree = (lazy[l(p)] != -1) ? lazy[l(p)] : st[l(p)];
            int rsubtree = (lazy[r(p)] != -1) ? lazy[r(p)] : st[r(p)];
            st[p] = conquer(lsubtree, rsubtree);
        }
    }

    ST(int sz) : n(sz), A(n) {
        int mx = (1 << (33 - __builtin_clz(n - 1))) + 1;
        st.resize(mx);
        lazy.assign(mx, -1);
    }

    ST(const vi &initialA) : ST((int) initialA.size()) {
        A = initialA;
        build(1, 0, n - 1);
    }

    inline void update(int i, int j, int val) { update(1, 0, n - 1, i, j, val); }

    inline int RMQ(int i, int j) { return RMQ(1, 0, n - 1, i, j); }
};

class SparseTable {                              // OOP style
private:
    vi A, P2, L2;
    vector<vi> SpT;                                // the Sparse Table
public:
    SparseTable() {}                               // default constructor

    SparseTable(vi &initialA) {                    // pre-processing routine
        A = initialA;
        int n = (int) A.size();
        int L2_n = (int) log2(n) + 1;
        P2.assign(L2_n + 1, 0);
        L2.assign((1 << L2_n) + 1, 0);
        for (int i = 0; i <= L2_n; ++i) {
            P2[i] = (1 << i);                            // to speed up 2^i
            L2[(1 << i)] = i;                            // to speed up log_2(i)
        }
        for (int i = 2; i < P2[L2_n]; ++i)
            if (L2[i] == 0)
                L2[i] = L2[i - 1];                         // to fill in the blanks

        // the initialization phase
        SpT = vector<vi>(L2[n] + 1, vi(n));
        for (int j = 0; j < n; ++j)
            SpT[0][j] = j;                             // RMQ of sub array [j..j]

        // the two nested loops below have overall time complexity = O(n log n)
        for (int i = 1; P2[i] <= n; ++i)             // for all i s.t. 2^i <= n
            for (int j = 0; j + P2[i] - 1 < n; ++j) {      // for all valid j
                int x = SpT[i - 1][j];                     // [j..j+2^(i-1)-1]
                int y = SpT[i - 1][j + P2[i - 1]];             // [j+2^(i-1)..j+2^i-1]
                SpT[i][j] = A[x] <= A[y] ? x : y;
            }
    }

    int RMQ(int i, int j) {
        int k = L2[j - i + 1];                           // 2^k <= (j-i+1)
        int x = SpT[k][i];                           // covers [i..i+2^k-1]
        int y = SpT[k][j - P2[k] + 1];                   // covers [j-2^k+1..j]
        return A[x] <= A[y] ? A[x] : A[y];
    }
};

struct LCT {
    int n;
    vector<pair<pll, int>> st;
    vi val;

    inline int l(int p) { return p << 1; }

    inline int r(int p) { return p << 1 ^ 1; }

    LCT(int sz, vi &val) : n(sz) {
        int mx = (1 << (33 - __builtin_clz(n - 1))) + 1;
        this->val = val;
        st.assign(mx, {{0, -llinf}, -1});
    }

    ll calc(pll &p, int x) {
        return p.first * x + p.second;
    }

    bool change(pll &to, pll &from, int &x) {
        ll old = calc(from, x);
        ll neww = calc(to, x);
        if (old == neww)return to.first > from.first;
        return neww > old;
    }

    void update(int p, int L, int R, pair<pll, int> &line) {
        if (L == R) {
            int x = val[L];
            if (change(line.first, st[p].first, x))swap(st[p], line);
            return;
        }
        int mid = (L + R) >> 1;
        int x = val[mid];
        bool chgleft = change(line.first, st[p].first, val[L]);
        bool chgmid = change(line.first, st[p].first, x);
        if (chgmid) swap(st[p], line);
        if (chgmid != chgleft) update(l(p), L, mid, line);
        else update(r(p), mid + 1, R, line);
    }

    pair<ll, int> query(int p, int L, int R, int x) {
        if (L == R) return {calc(st[p].first, x), st[p].second};
        int mid = (L + R) >> 1;
        int midval = val[mid];
        if (x <= midval) {
            pair<ll, int> ret = query(l(p), L, mid, x);
            ll cur = calc(st[p].first, x);
            if (ret.first > cur)return ret;
            else return {cur, st[p].second};
        } else {
            pair<ll, int> ret = query(r(p), mid + 1, R, x);
            ll cur = calc(st[p].first, x);
            if (ret.first > cur)return ret;
            else return {cur, st[p].second};
        }
    }

    void update(pair<pll, int> line) {
        update(1, 0, n - 1, line);
    }

    pair<ll, int> query(int x) {
        return query(1, 0, n - 1, x);
    }
};