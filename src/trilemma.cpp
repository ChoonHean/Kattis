#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef unsigned int uint;
typedef unsigned long long ull;
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
typedef tuple<int, int, int> ti;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<pll> vpll;
typedef vector<pdd> vpdd;
typedef tree<ti, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>
        ordered_set;
const int inf = 1e9;
const ll llinf = 1e18;
const int mod = 1e9 + 7;
const double eps = 1e-9;
#define all(a) a.begin(),a.end()
#define read(n) vi arr(n);for(int&_:arr)cin>>_
#define readarr(arr) for(auto&_:arr)cin>>_
#define readpair(arr) for(auto&[_,__]:arr)cin>>_>>__
#define rep(i, a, n) for(int i=a;i<n;++i)
#define repr(i, a, n) for(int i=a;i>=n;--i)
#define nl "\n"
#define sz(v) ((int)v.size())
#define PQ priority_queue
#define hmap unordered_map
#define hset unordered_set
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define lsb(i) (i&-i)
mt19937_64 rnd(time(0));

template<typename T>
inline bool chmin(T &a, T &b) {
    if (a > b) {
        swap(a, b);
        return true;
    } else return false;
}

template<typename T>
inline bool chmax(T &a, T &b) {
    if (a < b) {
        swap(a, b);
        return true;
    } else return false;
}

template<typename T>
inline void pr(const T &t) { cout << t << ' '; }

template<typename T, typename U>
inline void pr(const pair<T, U> &pa) {
    cout << '(';
    pr(pa.first);
    cout << ',';
    pr(pa.second);
    cout << ") ";
}

template<typename... Args>
inline void pr(const tuple<Args...> &tup) {
    apply([](const auto &... args) {
        pr('[');
        (pr(args), ...);
        pr(']');
    }, tup);
}

template<typename T>
void pr(const PQ<T, vector<T>, greater<>> &v);

template<typename T>
inline void pr(const vector<T> &v) {
    for (const auto &i: v) pr(i);
    cout << nl;
}

template<typename T>
inline void pr(const set<T> &s) {
    for (const auto &t: s)pr(t);
    cout << nl;
}

template<typename T>
inline void pr(const multiset<T> &s) {
    for (const auto &t: s)pr(t);
    cout << nl;
}

template<typename T>
inline void pr(const unordered_set<T> &s) {
    for (const auto &t: s)pr(t);
    cout << nl;
}

template<typename T, typename U>
inline void pr(const map<T, U> &m) {
    for (const auto &[t, u]: m) {
        cout << '(';
        pr(t);
        pr('-');
        pr(u);
        pr(')');
    }
    cout << nl;
}

template<typename T, typename U>
inline void pr(const unordered_map<T, U> &m) {
    for (const auto &[t, u]: m) {
        cout << '(';
        pr(t);
        pr('-');
        pr(u);
        pr(')');
    }
    cout << nl;
}

template<typename T>
inline void pr(const queue<T> &q) {
    queue<T> copy(q);
    while (!copy.empty()) {
        pr(copy.front());
        copy.pop();
    }
    cout << nl;
}

template<typename T>
inline void pr(const stack<T> &s) {
    stack<T> copy(s);
    while (!copy.empty()) {
        pr(copy.top());
        copy.pop();
    }
    cout << nl;
}

template<typename T>
inline void pr(const deque<T> &q) {
    deque<T> copy(q);
    while (!copy.empty()) {
        pr(copy.top());
        copy.pop();
    }
    cout << nl;
}

template<typename T>
inline void pr(const PQ<T> &pq) {
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
inline void pr(const PQ<T, vector<T>, greater<>> &pq) {
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
inline void pnl(const T &t) {
    pr(t);
    cout << nl;
}

template<typename... Args>
void pr(const Args &... args) {
    (pr(args), ...);
    cout << nl;
}

template<class T>
struct Point {
    typedef Point P;
    T x, y;

    explicit Point(T x = 0, T y = 0) : x(x), y(y) {}

    bool operator<(P p) const { return tie(x, y) < tie(p.x, p.y); }

    bool operator==(P p) const { return tie(x, y) == tie(p.x, p.y); }

    P operator+(P p) const { return P(x + p.x, y + p.y); }

    P operator-(P p) const { return P(x - p.x, y - p.y); }

    P operator*(T d) const { return P(x * d, y * d); }

    P operator/(T d) const { return P(x / d, y / d); }

    T dot(P p) const { return x * p.x + y * p.y; }

    T cross(P p) const { return x * p.y - y * p.x; }

    T cross(P a, P b) const { return (a - *this).cross(b - *this); }

    T dist2() const { return x * x + y * y; }

    double dist() const { return sqrt((double) dist2()); }

    // angle to x-axis in interval [-pi, pi]
    double angle() const { return atan2(y, x); }

    P unit() const { return *this / dist(); } // makes dist()=1
    P perp() const { return P(-y, x); } // rotates +90 degrees
    P normal() const { return perp().unit(); }

    // returns point rotated 'a' radians ccw around the origin
    P rotate(double a) const {
        return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
    }

    friend ostream &operator<<(ostream &os, const P &p) {
        return os << "(" << p.x << "," << p.y << ")";
    }
};

typedef Point<int> P;

inline void solve() {
    int n, x1, x2, x3, y1, y2, y3;
    cin >> n;
    rep(i, 0, n) {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        cout << "Case #" << i + 1 << ": ";
        P a(x1, y1), b(x2, y2), c(x3, y3);
        if (a.cross(b, c) == 0) {
            cout << "not a triangle\n";
            continue;
        }
        vi lengths{(b - a).dist2(), (c - a).dist2(), (b - c).dist2()};
        sort(all(lengths));
        if (lengths[0] == lengths[1] || lengths[1] == lengths[2])cout << "isosceles ";
        else cout << "scalene ";
        if (lengths[0] + lengths[1] == lengths[2])cout << "right triangle\n";
        else if (lengths[0] + lengths[1] < lengths[2])cout << "obtuse triangle\n";
        else cout << "acute triangle\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(10);
    int cases = 1;
//    cin >> cases;
    while (cases--) solve();
    return 0;
}