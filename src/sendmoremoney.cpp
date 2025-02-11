#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<pll> vpll;
typedef vector<pdd> vpdd;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
        ordered_set;
const int inf = 1e9;
const ll llinf = 4e18;
const int mod = 1e9 + 7;
const double EPS = 1e-9;
#define all(a) a.begin(),a.end()
#define read(n) vi arr(n);for(int&_:arr)cin>>_
#define readarr(arr) for(auto&_:arr)cin>>_
#define readpair(arr) for(auto&[_,__]:arr)cin>>_>>__
#define rep(i, a, n) for(int i=a;i<n;i++)
#define nl "\n"
#define sz(v) ((int)v.size())
#define PQ priority_queue
#define hmap unordered_map
#define hset unordered_set
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define clz(i) __builtin_clz(i)
#define ctz(i) __builtin_ctz(i)
#define popcount(i) __builtin_popcount(i)
#define lsb(i) (i&-i)
mt19937_64 rnd(time(0));


template<typename T>
inline void pr(T t) { cout << t << ' '; }


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
        cout << '(';
        pr(t);
        pr('-');
        pr(u);
        pr(')');
    }
    cout << nl;
}

template<typename T, typename U>
inline void pr(unordered_map<T, U> m) {
    for (auto [t, u]: m) {
        cout << '(';
        pr(t);
        pr('-');
        pr(u);
        pr(')');
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
inline void pr(deque<T> q) {
    deque<T> copy(q);
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

template<typename T>
inline void pnl(T t) {
    pr(t);
    cout << nl;
}

inline void solve() {
    string puzzle;
    cin >> puzzle;
    int plus = puzzle.find('+'), equal = puzzle.find('=');
    string a = puzzle.substr(0, plus), b = puzzle.substr(plus + 1, equal - plus - 1), c = puzzle.substr(equal + 1);
    set<char> tree;
    for (char &ch: a)tree.insert(ch);
    for (char &ch: b)tree.insert(ch);
    for (char &ch: c)tree.insert(ch);
    vector<char> chars;
    for (char ch: tree)chars.pb(ch);
    if (sz(chars) > 10) {
        cout << "impossible";
        return;
    }
    for (char &ch: a)ch = lb(all(chars), ch) - chars.begin();
    for (char &ch: b)ch = lb(all(chars), ch) - chars.begin();
    for (char &ch: c)ch = lb(all(chars), ch) - chars.begin();
    vi starts{a[0], b[0], c[0]};
    reverse(all(a));
    reverse(all(b));
    reverse(all(c));
    int x = sz(a), y = sz(b), z = sz(c), n = max(x, max(y, z));
    if (z != n) {
        cout << "impossible";
        return;
    }
    vi arr(10);
    iota(all(arr), 0);
    vi comb;
    rep(i, 0, 10 - sz(chars))comb.pb(0);
    rep(i, 0, sz(chars))comb.pb(1);
    vi mn(sz(chars), 10);
    do {
        vi p;
        rep(i, 0, 10)if (comb[i])p.pb(arr[i]);
        do {
            if (p[starts[0]] == 0 || p[starts[1]] == 0 || p[starts[2]] == 0)continue;
            int carry = 0;
            bool can = 1;
            rep(i, 0, n) {
                int sum = (i >= x ? 0 : p[a[i]]) + (i >= y ? 0 : p[b[i]]) + carry;
                if (sum % 10 != p[c[i]]) {
                    can = 0;
                    break;
                }
                carry = sum / 10;
            }
            if (can && !carry) {
                mn = min(mn, p);
            }
        } while (next_permutation(all(p)));
    } while (next_permutation(all(comb)));
    if (mn[0] == 10)pr("impossible");
    else {
        reverse(all(a));
        reverse(all(b));
        reverse(all(c));
        for (char &ch: a)cout << mn[ch];
        cout << '+';
        for (char &ch: b)cout << mn[ch];
        cout << '=';
        for (char &ch: c)cout << mn[ch];
    }
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(10);
    int cases = 1;
    // cin >> cases;
    while (cases--) solve();
    return 0;
}