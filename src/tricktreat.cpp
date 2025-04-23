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
int sgn(T x) { return (x > 0) - (x < 0); }

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

template<class P>
P lineProj(P a, P b, P p, bool refl = false) {
    P v = b - a;
    return p - v.perp() * (1 + refl) * v.cross(p - a) / v.dist2();
}

typedef double T;
typedef Point<T> P;

vector<P> convexHull(vector<P> pts) {
    if (sz(pts) <= 1) return pts;
    sort(all(pts));
    vector<P> h(sz(pts) + 1);
    int s = 0, t = 0;
    for (int it = 2; it--; s = --t, reverse(all(pts)))
        for (P p: pts) {
            while (t >= s + 2 && h[t - 2].cross(h[t - 1], p) <= 0) t--;
            h[t++] = p;
        }
    return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}

P ccCenter(const P &A, const P &B, const P &C) {
    P b = C - A, c = B - A;
    return A + (b * c.dist2() - c * b.dist2()).perp() / b.cross(c) / 2;
}

pair<P, double> mec(vector<P> ps) {
    shuffle(all(ps), mt19937(time(0)));
    P o = ps[0];
    double r = 0;
    double EPS = 1 + 1e-8;
    rep(i, 0, sz(ps)) if ((o - ps[i]).dist() > r * EPS) {
            o = ps[i], r = 0;
            rep(j, 0, i) if ((o - ps[j]).dist() > r * EPS) {
                    o = (ps[i] + ps[j]) / 2;
                    r = (o - ps[i]).dist();
                    rep(k, 0, j) if ((o - ps[k]).dist() > r * EPS) {
                            o = ccCenter(ps[i], ps[j], ps[k]);
                            r = (o - ps[i]).dist();
                        }
                }
        }
    return {o, r};
}

inline void solve() {
    int n;
    P a(0, 0), b(1, 0);
    while (cin >> n) {
        if (!n)break;
        vector<P> arr(n);
        readpair(arr);
        arr = convexHull(arr);
        rep(i, 0, n)arr.pb(lineProj(a, b, arr[i], 1));
        auto ret = mec(arr);
        pr(ret.first.x, ret.second);
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