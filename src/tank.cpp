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
    int n, d;
    double l, lo = 0, hi = 0, x, y;
    cin >> n >> d >> l;
    l = l * 1000 / d;
    deque<point> dq;
    rep(0, n) {
        cin >> x >> y;
        hi = max(hi, y);
        dq.pb(point(x, y));
    }
    vector<point> arr;
    while (dq.front().y != 0 || dq.back().y != 0) {
        dq.pb(dq.front());
        dq.pop_front();
    }
    while (!dq.empty()) {
        arr.pb(dq.back());
        dq.pop_back();
    }
    while (fabs(hi - lo) > 1e-4) {
        double mid = (hi + lo) / 2;
        vector<point> v;
        rep(0, n) {
            if (arr[i].y > mid) {
                if (arr[i].x == arr[i - 1].x) {
                    v.pb(point(arr[i].x, mid));
                } else {
                    double grad = (arr[i].y - arr[i - 1].y) / (arr[i].x - arr[i - 1].x);
                    v.pb(point((mid - arr[i - 1].y) / grad + arr[i - 1].x, mid));
                }
                break;
            } else v.pb(arr[i]);
        }
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i].y > mid) {
                if (arr[i + 1].x == arr[i].x)v.pb(point(arr[i].x, mid));
                else {
                    double grad = (arr[i + 1].y - arr[i].y) / (arr[i + 1].x - arr[i].x);
                    v.pb(point((mid - arr[i + 1].y) / grad + arr[i + 1].x, mid));
                }
                i++;
                for (; i < n; i++)v.pb(arr[i]);
                break;
            }
        }
        double a = area(v);
        if (a >= l)hi = mid;
        else lo = mid;
    }
    cout << fixed << setprecision(2) << lo;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}