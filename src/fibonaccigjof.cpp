#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int mod = 1e9 + 7;
ll inf = LLONG_MAX;

template<typename T>
void print(T v) {
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

template<typename T>
void print_p(T v) {
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << "(" << (*it).first << "," << (*it).second << ") ";
    }
    cout << endl;
}

vector<pll> fib(5000000);
vector<pll> seeds(5000000);

inline ll calc(ll n) {
    if (n == 0) return 0;
    pll coeffs = fib[(n - 1) % 5000000];
    pll vars = seeds[(n - 1) / 5000000];
    return (coeffs.first * vars.first + coeffs.second * vars.second) % mod;
}

struct SegmentTree {                              // OOP style
    int n;                                         // n = (int)A.size()
    vl lazy;                                // the arrays
    vector<pll> st, A;

    inline int l(int p) { return p << 1; }                 // go to left child
    inline int r(int p) { return (p << 1) + 1; }              // go to right child

    inline pll conquer(pll a, pll b) {
        return pair((a.first + b.first) % mod, (a.second + b.second) % mod);          // RMQ
    }

    inline pll shift(pll orig, ll amt) {
        ll prev = calc(amt - 1);
        ll next = calc(amt);
        return pair((orig.first * prev + orig.second * next) % mod,
                    (orig.first * next + orig.second * (prev + next)) % mod);
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
        if (lazy[p]) {                           // has a lazy flag
            st[p] = shift(st[p], lazy[p]);                           // [L..R] has same value
            if (L != R) {                              // not a leaf
                lazy[l(p)] += lazy[p];                 // propagate downwards
                lazy[r(p)] += lazy[p];
            }
            lazy[p] = 0;                              // erase lazy flag
        }
    }

    ll RMQ(int p, int L, int R, int i, int j) {   // O(log n)
        propagate(p, L, R);                          // lazy propagation
        if (i > j) return 0;                        // infeasible
        if ((L >= i) && (R <= j)) {                 // found the segment
            return st[p].second;
        }
        int m = (L + R) / 2;
        return (RMQ(l(p), L, m, i, min(m, j)) + RMQ(r(p), m + 1, R, max(i, m + 1), j)) % mod;
    }

    void update(int p, int L, int R, int i, int j, int val) { // O(log n)
        propagate(p, L, R);                          // lazy propagation
        if (i > j) return;
        if ((L >= i) && (R <= j)) {                  // found the segment
            lazy[p] += val;                             // update this
            propagate(p, L, R);                        // lazy propagation
        } else {
            int m = (L + R) / 2;
            update(l(p), L, m, i, min(m, j), val);
            update(r(p), m + 1, R, max(i, m + 1), j, val);
            st[p] = conquer(st[l(p)], st[r(p)]);
        }
    }

    SegmentTree(int sz) : n(sz), A(n), st(4 * n), lazy(4 * n, 0) {}

    SegmentTree(const vector<pll> &initialA) : SegmentTree((int) initialA.size()) {
        A = initialA;
        build(1, 0, n - 1);
    }

    void update(int i, int j, int val) { update(1, 0, n - 1, i, j, val); }

    int RMQ(int i, int j) { return RMQ(1, 0, n - 1, i, j); }
};

void solve() {
    int n, m, command, l, r;
    int d;
    cin >> n >> m;
    vl arr(n);
    vector<pll> pairs(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        pairs[i] = pair(calc(arr[i] - 1), calc(arr[i]));
    }
    SegmentTree st(pairs);
    for (int i = 0; i < m; i++) {
        cin >> command >> l >> r;
        l--;
        r--;
        if (command == 1) {
            cin >> d;
            st.update(l, r, d);
        } else {
            cout << st.RMQ(l, r) << endl;
        }
    }
}

int main() {
    fib[0] = pair(0, 1);
    for (int i = 1; i < 5000000; i++) {
        pll prev = fib[i - 1];
        fib[i] = pair(prev.second % mod, (prev.first + prev.second) % mod);
    }
    seeds[0] = pair(0, 1);
    auto it = fib.rbegin();
    ll lasta = (*it).first, lastb = (*it).second;
    it++;
    ll secondlasta = (*it).first, secondlastb = (*it).second;
    for (int i = 1; i < 5000000; i++) {
        pll prev = seeds[i - 1];
        ll first = (lasta * prev.first + lastb * prev.second) % mod;
        ll second = (first + secondlasta * prev.first + secondlastb * prev.second) % mod;
        seeds[i] = pair(first, second);
    }
    int t = 1;
    while (t--) solve();
    return 0;
}