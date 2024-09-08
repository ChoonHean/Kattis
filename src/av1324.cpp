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

struct ST {
    int n;                                         // n = (int)A.size()
    vi st, lazy;                                // the arrays

    inline int l(int p) { return p << 1; }                 // go to left child
    inline int r(int p) { return (p << 1) + 1; }              // go to right child

    inline void propagate(int p, int L, int R) {
        if (lazy[p] != inf) {                         // has a lazy flag
            st[p] = min(st[p], lazy[p]);                           // [L..R] has same value
            if (L != R) {                               // not a leaf
                int left = l(p);
                lazy[left] = min(lazy[left], lazy[p]);
                int right = r(p);
                lazy[right] = min(lazy[right], lazy[p]);
            }
            lazy[p] = inf;                              // erase lazy flag
        }
    }

    int RMQ(int p, int L, int R, int i, int j) {   // O(log n)
        propagate(p, L, R);                          // lazy propagation
        if ((L >= i) && (R <= j)) return st[p];      // found the segment
        int m = (L + R) / 2;
        if (j > m)return RMQ(r(p), m + 1, R, i, j);
        else return RMQ(l(p), L, m, i, j);
    }

    void update(int p, int L, int R, int i, int j, int val) { // O(log n)
        propagate(p, L, R);                          // lazy propagation
        if (i > j) return;
        if ((L >= i) && (R <= j)) {                  // found the segment
            lazy[p] = min(lazy[p], val);                             // update this
            propagate(p, L, R);                        // lazy propagation
        } else {
            int m = (L + R) / 2;
            update(l(p), L, m, i, min(m, j), val);
            update(r(p), m + 1, R, max(i, m + 1), j, val);
        }
    }

    ST(int sz) : n(sz), st(n << 2, inf), lazy(n << 2, inf) {}

    inline void update(int i, int j, int val) { update(1, 0, n - 1, i, j, val); }

    inline int RMQ(int i, int j) { return RMQ(1, 0, n - 1, i, j); }
};

inline void solve() {
    int n;
    cin >> n;
    read(n);
    int one = arr[0];
    ST two(n + 1);
    int three = INT_MAX;
    vi ans, pos(n + 1);
    pos[one] = 0;
    rep(1, n) {
        int curr = arr[i];
        pos[curr] = i;
        if (curr > three) {
            for (int j = 0; j < n; j++)
                if (arr[j] < ans[1]) {
                    pr(j + 1);
                    break;
                }
            for (int j: ans)pr(pos[j] + 1);
            pr(i + 1);
            return;
        }
        int next = two.RMQ(curr, curr);
        if (next < three) {
            three = next;
            ans = {three, curr};
        }
        if (curr > one)two.update(one, curr, curr);
        else one = curr;
    }
    cout << "Ekkert mynstur!";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (--t) {
        solve();
        cout << nl;
    }
    solve();
    return 0;
}