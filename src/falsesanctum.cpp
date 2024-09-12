#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pdd> vpdd;
const int inf = 1e9;
const int mod = 1e9 + 7;
#define all(a) a.begin(),a.end()
#define read(n) vi arr(n);for(int i=0;i<n;i++)cin>>arr[i]
#define readarr(n, arr) for(int i=0;i<n;i++)cin>>arr[i]
#define rep(a, n) for(int i=a;i<n;i++)
#define nl "\n"
#define sz(v) ((int)v.size())
#define PQ priority_queue
#define hmap unordered_map
#define hset unordered_set
#define pb push_back
#define clz(i) __builtin_clz(i)
#define ctz(i) __builtin_ctz(i)
#define popcount(i) __builtin_popcount(i)
#define LSOne(i) (i&-i)

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
        pr(t);
        pr('-');
        pr(u);
    }
    cout << nl;
}

template<typename T, typename U>
inline void pr(unordered_map<T, U> m) {
    for (auto [t, u]: m) {
        pr(t);
        pr('-');
        pr(u);
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

#define int ll

struct ST {
    int n;                                         // n = (int)A.size()
    vl A, st, lazy;

    inline int l(int p) { return p << 1; }                 // go to left child
    inline int r(int p) { return (p << 1) + 1; }              // go to right child

    inline ll conquer(ll a, ll b) {
        return a + b;                            // RMQ
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
                lazy[l(p)] = lazy[r(p)] = lazy[p] >> 1;       // propagate downwards
            else                                       // L == R, a single index
                A[L] = lazy[p];                          // time to update this
            lazy[p] = -1;                              // erase lazy flag
        }
    }

    ll RMQ(int p, int L, int R, int i, int j) {   // O(log n)
        propagate(p, L, R);                          // lazy propagation
        if (i > j) return 0;                        // infeasible
        if ((L >= i) && (R <= j)) return st[p];      // found the segment
        int m = (L + R) / 2;
        return conquer(RMQ(l(p), L, m, i, min(m, j)),
                       RMQ(r(p), m + 1, R, max(i, m + 1), j));
    }

    void update(int p, int L, int R, int i, int j, int val) { // O(log n)
        propagate(p, L, R);                          // lazy propagation
        if (i > j) return;
        if ((L >= i) && (R <= j)) {                  // found the segment
            lazy[p] = val * (R - L + 1);                             // update this
            propagate(p, L, R);                        // lazy propagation
        } else {
            int m = (L + R) / 2;
            update(l(p), L, m, i, min(m, j), val);
            update(r(p), m + 1, R, max(i, m + 1), j, val);
            ll lsubtree = (lazy[l(p)] != -1) ? lazy[l(p)] : st[l(p)];
            ll rsubtree = (lazy[r(p)] != -1) ? lazy[r(p)] : st[r(p)];
            st[p] = conquer(lsubtree, rsubtree);
        }
    }

    ST(int sz) : n(sz), A(n), st(4 * n), lazy(4 * n, -1) {}

    ST(const vl &initialA) : ST((int) initialA.size()) {
        A = initialA;
        build(1, 0, n - 1);
    }

    inline void update(int i, int j, int val) { update(1, 0, n - 1, i, j, val); }

    inline ll RMQ(int i, int j) { return RMQ(1, 0, n - 1, i, j); }
};

inline void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    set<int> mp{0};
    vl sum(n);
    int l = 0, r = 0;
    while (l < n) {
        while (s[r] == s[l]) {
            r++;
            if (r == n)break;
        }
        int size = r - l;
        rep(l, r)sum[i] = size;
        if (r != n)mp.emplace_hint(mp.end(), r);
        l = r;
    }
    while (popcount(sz(sum)) != 1)sum.pb(0);
    mp.insert(n);
    ST st(sum);
    int command;
    char c;
    while (q--) {
        cin >> command;
        if (command == 1) {
            cin >> l >> c;
            --l;
            if (c == s[l])continue;
            if (l) {
                if (s[l - 1] == s[l]) {
                    auto it = mp.insert(l).first;
                    int len = l - (*(--it));
                    st.update(*it, l - 1, len);
                }
                if (s[l - 1] == c) {
                    mp.erase(l);
                }
            }
            if (l != n - 1) {
                if (s[l] == s[l + 1]) {
                    auto it = mp.insert(l + 1).first;
                    int len = (*(++it)) - l - 1;
                    st.update(l + 1, *it - 1, len);
                }
                if (c == s[l + 1]) {
                    mp.erase(l + 1);
                }
            }
            s[l] = c;
            auto it = mp.upper_bound(l);
            auto it2 = prev(it);
            st.update(*it2, *it - 1, *it - *it2);
        } else {
            cin >> l >> r;
            --l;
            --r;
            ll left = *mp.lower_bound(l), right = *--mp.upper_bound(r);
            if (left <= right)
                pnl((left - l) * (left - l) + st.RMQ(left, right - 1) + (r - right + 1) * (r - right + 1));
            else pnl((r - l + 1) * (r - l + 1));
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}