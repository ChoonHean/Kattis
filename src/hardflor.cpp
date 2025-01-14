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
const int mod = 1e9 + 7;
const double EPS = 1e-9;
#define all(a) a.begin(),a.end()
#define read(n) vi arr(n);for(int&_:arr)cin>>_
#define readarr(n, arr) for(auto&_:arr)cin>>_
#define rep(a, n) for(int i=a;i<n;i++)
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

struct FT {                              // index 0 is not used
    vl ft;                                        // internal FT is an array
    FT(int m) { ft.assign(m + 1, 0); }      // create an empty FT
    FT() {}

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
        while (p * 2 < (int) ft.size()) p *= 2;
        int i = 0;
        while (p) {
            if (k > ft[i + p]) {
                k -= ft[i + p];
                i += p;
            }
            p /= 2;
        }
        return i + 1;
    }
};

struct point {
    double x, y;

    point() { x = y = 0.0; }

    point(double _x, double _y) : x(_x), y(_y) {}

    bool operator==(point other) const {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
    }

    bool operator<(const point &p) const {
        return x < p.x || (abs(x - p.x) < EPS && y < p.y);
    }

    friend ostream &operator<<(ostream &os, const point &p) {
        os << "(" << p.x << ", " << p.y << ')';
        return os;
    }
};

double area(const vector<point> &P) {
    double ans = 0.0;
    for (int i = 0; i < (int) P.size() - 1; ++i)      // Shoelace formula
        ans += (P[i].x * P[i + 1].y - P[i + 1].x * P[i].y);
    return fabs(ans) / 2.0;                          // only do / 2.0 here
}

inline void solve() {
    int n;
    cin >> n;
    vector<point> arr{point(0, 0)};
    int x = 0, y = 0;
    string s;
    rep(0, n) {
        cin >> s;
        if (s[0] == 'N')y += stoi(s.substr(1));
        else if (s[0] == 'E')x += stoi(s.substr(1));
        else if (s[0] == 'S')y -= stoi(s.substr(1));
        else x -= stoi(s.substr(1));
        arr.pb(point(x, y));
    }
    cout << "THE AREA IS " << (int) area(arr);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(10);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}