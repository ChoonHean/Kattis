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
typedef tree<pii, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>
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
#define repr(i, a, n) for(int i=a;i>=n;i--)
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

double DEG_to_RAD(double d) { return d * M_PI / 180.0; }

double RAD_to_DEG(double r) { return r * 180.0 / M_PI; }

// points_lines ------------------------------------------------------------
struct point_i {
    int x, y;                                      // use this if possible
    point_i() { x = y = 0; }                       // default constructor
    point_i(int _x, int _y) : x(_x), y(_y) {}      // constructor
};

struct point {
    double x, y;                                   // if need more precision
    point() { x = y = 0.0; }                       // default constructor
    point(double _x, double _y) : x(_x), y(_y) {}  // constructor
    bool operator<(point other) const {          // override < operator
        if (fabs(x - other.x) > EPS)                   // useful for sorting
            return x < other.x;                        // by x-coordinate
        return y < other.y;                          // if tie, by y-coordinate
    }

    // use EPS (1e-9) when testing equality of two floating points
    bool operator==(point other) const {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
    }

    friend ostream &operator<<(ostream &os, const point p) {
        os << '(' << p.x << ' ' << p.y << ')';
        return os;
    }
};

double dist(point p1, point p2) {                // Euclidean distance
    // hypot(dx, dy) returns sqrt(dx*dx + dy*dy)
    return hypot(p1.x - p2.x, p1.y - p2.y);            // return double
}

// rotate p by theta degrees CCW w.r.t origin (0, 0)
point rotate(point p, double theta) {
    double rad = DEG_to_RAD(theta);                // convert to radian
    return point(p.x * cos(rad) - p.y * sin(rad),
                 p.x * sin(rad) + p.y * cos(rad));
}

struct line {
    double a, b, c;
};                 // most versatile

// the answer is stored in the third parameter (pass by reference)
void pointsToLine(point p1, point p2, line &l) {
    if (fabs(p1.x - p2.x) < EPS)                     // vertical line is fine
        l = {1.0, 0.0, -p1.x};                       // default values
    else {
        double a = -(double) (p1.y - p2.y) / (p1.x - p2.x);
        l = {a, 1.0, -(double) (a * p1.x) - p1.y};      // NOTE: b always 1.0
    }
}

// not needed since we will use the more robust form: ax + by + c = 0
struct line2 {
    double m, c;
};                   // alternative way

int pointsToLine2(point p1, point p2, line2 &l) {
    if (p1.x == p2.x) {                            // vertical line
        l.m = inf;                                   // this is to denote a
        l.c = p1.x;                                  // line x = x_value
        return 0;                                    // differentiate result
    } else {
        l.m = (double) (p1.y - p2.y) / (p1.x - p2.x);
        l.c = p1.y - l.m * p1.x;
        return 1;                                    // standard y = mx + c
    }
}

bool areParallel(line l1, line l2) {             // check a & b
    return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS);
}

bool areSame(line l1, line l2) {                 // also check  c
    return areParallel(l1, l2) && (fabs(l1.c - l2.c) < EPS);
}

// returns true (+ intersection point p) if two lines are intersect
bool areIntersect(line l1, line l2, point &p) {
    if (areParallel(l1, l2)) return false;         // no intersection
    // solve system of 2 linear algebraic equations with 2 unknowns
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    // special case: test for vertical line to avoid division by zero
    if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
    else p.y = -(l2.a * p.x + l2.c);
    return true;
}

struct vec {
    double x, y; // name: `vec' is different from STL vector
    vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(const point &a, const point &b) {      // convert 2 points
    return vec(b.x - a.x, b.y - a.y);                  // to vector a->b
}

vec scale(const vec &v, double s) {              // s = [<1..1..>1]
    return vec(v.x * s, v.y * s);                      // shorter/eq/longer
}                                                // return a new vec
point translate(const point &p, const vec &v) {  // translate p
    return point(p.x + v.x, p.y + v.y);                // according to v
}                                                // return a new point

// convert point and gradient/slope to line
void pointSlopeToLine(point p, double m, line &l) {
    l.a = -m;                                      // always -m
    l.b = 1;                                       // always 1
    l.c = -((l.a * p.x) + (l.b * p.y));            // compute this
}

void closestPoint(line l, point p, point &ans) {
    // this line is perpendicular to l and pass through p
    line perpendicular;
    if (fabs(l.b) < EPS) {                         // vertical line
        ans.x = -(l.c);
        ans.y = p.y;
        return;
    }
    if (fabs(l.a) < EPS) {                         // horizontal line
        ans.x = p.x;
        ans.y = -(l.c);
        return;
    }
    pointSlopeToLine(p, 1 / l.a, perpendicular);     // normal line
    // intersect line l with this perpendicular line
    // the intersection point is the closest point
    areIntersect(l, perpendicular, ans);
}

// returns the reflection of point on a line
void reflectionPoint(line l, point p, point &ans) {
    point b;
    closestPoint(l, p, b);                         // similar to distToLine
    vec v = toVec(p, b);                           // create a vector
    ans = translate(translate(p, v), v);           // translate p twice
}

// returns the dot product of two vectors a and b
double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }

// returns the squared value of the normalized vector
double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

double angle(const point &a, const point &o, const point &b) {
    vec oa = toVec(o, a), ob = toVec(o, b);        // a != o != b
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}                                                // angle aob in rad

// returns the distance from p to the line defined by
// two points a and b (a and b must be different)
// the closest point is stored in the 4th parameter (byref)
double distToLine(point p, point a, point b, point &c) {
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    // formula: c = a + u*ab
    c = translate(a, scale(ab, u));                // translate a to c
    return dist(p, c);                             // Euclidean distance
}

// returns the distance from p to the line segment ab defined by
// two points a and b (technically, a has to be different than b)
// the closest point is stored in the 4th parameter (byref)
double distToLineSegment(point p, point a, point b, point &c) {
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    if (u < 0.0) {                                 // closer to a
        c = point(a.x, a.y);
        return dist(p, a);                           // dist p to a
    }
    if (u > 1.0) {                                 // closer to b
        c = point(b.x, b.y);
        return dist(p, b);                           // dist p to b
    }
    return distToLine(p, a, b, c);                 // use distToLine
}

// returns the cross product of two vectors a and b
double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

//// another variant
// returns 'twice' the area of this triangle A-B-c
// int area2(point p, point q, point r) {
//   return p.x * q.y - p.y * q.x +
//          q.x * r.y - q.y * r.x +
//          r.x * p.y - r.y * p.x;
// }

// note: to accept collinear points, we have to change the `> 0'
// returns true if point r is on the left side of line pq
bool ccw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) > -EPS;
}

// returns true if point r is on the same line as the line pq
bool collinear(point p, point q, point r) {
    return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;
}

// circles -------------------------------------------------------------------
int insideCircle(point_i p, point_i c, int r) {  // all integer version
    int dx = p.x - c.x, dy = p.y - c.y;
    int Euc = dx * dx + dy * dy, rSq = r * r;            // all integer
    return Euc < rSq ? 1 : Euc == rSq ? 0 : -1;    // inside/border/outside
}

bool circle2PtsRad(point p1, point p2, double r, point &c) {
    // to get the other center, reverse p1 and p2
    double d2 = (p1.x - p2.x) * (p1.x - p2.x) +
                (p1.y - p2.y) * (p1.y - p2.y);
    double det = r * r / d2 - 0.25;
    if (det < 0.0) return false;
    double h = sqrt(det);
    c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
    c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
    return true;
}

// polygon ----------------------------------------------------------------

// returns the perimeter of polygon P, which is the sum of
// Euclidian distances of consecutive line segments (polygon edges)
double perimeter(const vector<point> &P) {       // by ref for efficiency
    double ans = 0.0;
    for (int i = 0; i < (int) P.size() - 1; ++i)      // note: P[n-1] = P[0]
        ans += dist(P[i], P[i + 1]);                   // as we duplicate P[0]
    return ans;
}

// returns the area of polygon P


// returns the area of polygon P, which is half the cross products
// of vectors defined by edge endpoints
double area_alternative(const vector<point> &P) {
    double ans = 0.0;
    point O(0.0, 0.0);           // O = the Origin
    for (int i = 0; i < (int) P.size() - 1; ++i)      // sum of signed areas
        ans += cross(toVec(O, P[i]), toVec(O, P[i + 1]));
    return fabs(ans) / 2.0;
}

// returns true if we always make the same turn
// while examining all the edges of the polygon one by one
bool isConvex(const vector<point> &P) {
    int n = (int) P.size();
    // a point/sz=2 or a line/sz=3 is not convex
    if (n <= 3) return false;
    bool firstTurn = ccw(P[0], P[1], P[2]);        // remember one result,
    for (int i = 1; i < n - 1; ++i)                 // compare with the others
        if (ccw(P[i], P[i + 1], P[(i + 2) == n ? 1 : i + 2]) != firstTurn)
            return false;                              // different -> concave
    return true;                                   // otherwise -> convex
}

// returns 1/0/-1 if point p is inside/on (vertex/edge)/outside of
// either convex/concave polygon P
int insidePolygon(point pt, const vector<point> &P) {
    int n = (int) P.size();
    if (n <= 3) return -1;                         // avoid point or line
    bool on_polygon = false;
    for (int i = 0; i < n - 1; ++i)                  // on vertex/edge?
        if (fabs(dist(P[i], pt) + dist(pt, P[i + 1]) - dist(P[i], P[i + 1])) < EPS)
            on_polygon = true;
    if (on_polygon) return 0;                      // pt is on polygon
    double sum = 0.0;                              // first = last point
    for (int i = 0; i < n - 1; ++i) {
        if (ccw(pt, P[i], P[i + 1]))
            sum += angle(P[i], pt, P[i + 1]);            // left turn/ccw
        else
            sum -= angle(P[i], pt, P[i + 1]);            // right turn/cw
    }
    return fabs(sum) > M_PI ? 1 : -1;              // 360d->in, 0d->out
}

// compute the intersection point between line segment p-q and line A-B
point lineIntersectSeg(point p, point q, point A, point B) {
    double a = B.y - A.y, b = A.x - B.x, c = B.x * A.y - A.x * B.y;
    double u = fabs(a * p.x + b * p.y + c);
    double v = fabs(a * q.x + b * q.y + c);
    return point((p.x * v + q.x * u) / (u + v), (p.y * v + q.y * u) / (u + v));
}

// cuts polygon Q along the line formed by point A->point B (order matters)
// (note: the last point must be the same as the first point)
vector<point> cutPolygon(point A, point B, const vector<point> &Q) {
    vector<point> P;
    for (int i = 0; i < (int) Q.size(); ++i) {
        double left1 = cross(toVec(A, B), toVec(A, Q[i])), left2 = 0;
        if (i != (int) Q.size() - 1) left2 = cross(toVec(A, B), toVec(A, Q[i + 1]));
        if (left1 > -EPS) P.push_back(Q[i]);         // Q[i] is on the left
        if (left1 * left2 < -EPS)                      // crosses line AB
            P.push_back(lineIntersectSeg(Q[i], Q[i + 1], A, B));
    }
    if (!P.empty() && !(P.back() == P.front()))
        P.push_back(P.front());                      // wrap around
    return P;
}

vector<point> CH_Graham(vector<point> &Pts) {    // overall O(n log n)
    vector<point> P(Pts);                          // copy all points
    int n = (int) P.size();
    if (n <= 3) {                                  // point/line/triangle
        if (!(P[0] == P[n - 1])) P.push_back(P[0]);    // corner case
        return P;                                    // the CH is P itself
    }

    // first, find P0 = point with lowest Y and if tie: rightmost X
    int P0 = min_element(P.begin(), P.end()) - P.begin();
    swap(P[0], P[P0]);                             // swap P[P0] with P[0]

    // second, sort points by angle around P0, O(n log n) for this sort
    sort(++P.begin(), P.end(), [&](point a, point b) {
        return ccw(P[0], a, b);                      // use P[0] as the pivot
    });

    // third, the ccw tests, although complex, it is just O(n)
    vector<point> S({P[n - 1], P[0], P[1]});         // initial S
    int i = 2;                                     // then, we check the rest
    while (i < n) {                                // n > 3, O(n)
        int j = (int) S.size() - 1;
        if (ccw(S[j - 1], S[j], P[i]))                 // CCW turn
            S.push_back(P[i++]);                       // accept this point
        else                                         // CW turn
            S.pop_back();                              // pop until a CCW turn
    }
    return S;                                      // return the result
}

vector<point> CH_Andrew(vector<point> &Pts) {    // overall O(n log n)
    int n = Pts.size(), k = 0;
    vector<point> H(2 * n);
    sort(Pts.begin(), Pts.end());                  // sort the points by x/y
    for (int i = 0; i < n; ++i) {                  // build lower hull
        while ((k >= 2) && !ccw(H[k - 2], H[k - 1], Pts[i])) --k;
        H[k++] = Pts[i];
    }
    for (int i = n - 2, t = k + 1; i >= 0; --i) {       // build upper hull
        while ((k >= t) && !ccw(H[k - 2], H[k - 1], Pts[i])) --k;
        H[k++] = Pts[i];
    }
    H.resize(k);
    return H;
}

// triangles -----------------------------------------------------------

double perimeter(double ab, double bc, double ca) {
    return ab + bc + ca;
}

double perimeter(point a, point b, point c) {
    return dist(a, b) + dist(b, c) + dist(c, a);
}

double area(double ab, double bc, double ca) {
    // Heron's formula, split sqrt(a*b) into sqrt(a)*sqrt(b)
    double s = 0.5 * perimeter(ab, bc, ca);
    return sqrt(s) * sqrt(s - ab) * sqrt(s - bc) * sqrt(s - ca);
}

double area(point a, point b, point c) {
    return area(dist(a, b), dist(b, c), dist(c, a));
}

double rInCircle(double ab, double bc, double ca) {
    return area(ab, bc, ca) / (0.5 * perimeter(ab, bc, ca));
}

double rInCircle(point a, point b, point c) {
    return rInCircle(dist(a, b), dist(b, c), dist(c, a));
}

// assumption: the required points/lines functions have been written
// returns 1 if there is an inCircle center, returns 0 otherwise
// if this function returns 1, ctr will be the inCircle center
// and r is the same as rInCircle
int inCircle(point p1, point p2, point p3, point &ctr, double &r) {
    r = rInCircle(p1, p2, p3);
    if (fabs(r) < EPS) return 0;                   // no inCircle center

    line l1, l2;                    // compute these two angle bisectors
    double ratio = dist(p1, p2) / dist(p1, p3);
    point p = translate(p2, scale(toVec(p2, p3), ratio / (1 + ratio)));
    pointsToLine(p1, p, l1);

    ratio = dist(p2, p1) / dist(p2, p3);
    p = translate(p1, scale(toVec(p1, p3), ratio / (1 + ratio)));
    pointsToLine(p2, p, l2);

    areIntersect(l1, l2, ctr);           // get their intersection point
    return 1;
}

double rCircumCircle(double ab, double bc, double ca) {
    return ab * bc * ca / (4.0 * area(ab, bc, ca));
}

double rCircumCircle(point a, point b, point c) {
    return rCircumCircle(dist(a, b), dist(b, c), dist(c, a));
}

// assumption: the required points/lines functions have been written
// returns 1 if there is a circumCenter center, returns 0 otherwise
// if this function returns 1, ctr will be the circumCircle center
// and r is the same as rCircumCircle
int circumCircle(point p1, point p2, point p3, point &ctr, double &r) {
    double a = p2.x - p1.x, b = p2.y - p1.y;
    double c = p3.x - p1.x, d = p3.y - p1.y;
    double e = a * (p1.x + p2.x) + b * (p1.y + p2.y);
    double f = c * (p1.x + p3.x) + d * (p1.y + p3.y);
    double g = 2.0 * (a * (p3.y - p2.y) - b * (p3.x - p2.x));
    if (fabs(g) < EPS) return 0;

    ctr.x = (d * e - b * f) / g;
    ctr.y = (a * f - c * e) / g;
    r = dist(p1, ctr);  // r = distance from center to 1 of the 3 points
    return 1;
}

// returns true if point d is inside the circumCircle defined by a,b,c
int inCircumCircle(point a, point b, point c, point d) {
    return (a.x - d.x) * (b.y - d.y) * ((c.x - d.x) * (c.x - d.x) + (c.y - d.y) * (c.y - d.y)) +
           (a.y - d.y) * ((b.x - d.x) * (b.x - d.x) + (b.y - d.y) * (b.y - d.y)) * (c.x - d.x) +
           ((a.x - d.x) * (a.x - d.x) + (a.y - d.y) * (a.y - d.y)) * (b.x - d.x) * (c.y - d.y) -
           ((a.x - d.x) * (a.x - d.x) + (a.y - d.y) * (a.y - d.y)) * (b.y - d.y) * (c.x - d.x) -
           (a.y - d.y) * (b.x - d.x) * ((c.x - d.x) * (c.x - d.x) + (c.y - d.y) * (c.y - d.y)) -
           (a.x - d.x) * ((b.x - d.x) * (b.x - d.x) + (b.y - d.y) * (b.y - d.y)) * (c.y - d.y) > 0 ? 1 : 0;
}

bool canFormTriangle(double a, double b, double c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

double area(const vector<point> &P, int l, int r, int n) {
    double ans = 0.0;
    for (int i = l; i != r; i = (i + 1) % n)      // Shoelace formula
        ans += (P[i].x * P[(i + 1) % n].y - P[(i + 1) % n].x * P[i].y);
    ans += (P[r].x * P[l].y - P[l].x * P[r].y);
    return fabs(ans) / 2.0;                          // only do / 2.0 here
}

inline void solve() {
    int n, k;
    cin >> n >> k;
    if (k == 1) {
        pr(1);
        return;
    } else if (k == 2) {
        pr(1, 2);
        return;
    }
    k = n - k;
    vector<point> arr(n);
    readpair(arr);
    vvd sub(n, vd(n));
    rep(i, 0, n)rep(j, i, i + k)sub[i][j % n] = area(arr, (i + n - 1) % n, (j + 1) % n, n);
    double mx = 0;
    vi exclude;
    hset<int> b;
    if (n <= 100)rep(i, 0, n)b.insert(i);
    else if (n <= 1000)while (sz(b) < 8)b.insert(rand() % n);
    else while (sz(b) < 2)b.insert(rand() % n);
    for (const auto &start: b) {
        vvd dp(n + 1, vd(k + 1, 0));
        vvi p(n + 1, vi(k + 1, -1));
        dp[0][0] = 0;
        rep(i, 0, n) {
            rep(j, 0, k + 1) {
                if (dp[i][j] >= dp[i + 1][j]) {
                    dp[i + 1][j] = dp[i][j];
                    p[i + 1][j] = i;
                }
            }
            rep(j, i + 2, min(n, i + k + 1) + 1) {
                rep(skip, 0, k + 1 - (j - i - 1)) {
                    double next = dp[i][skip] + sub[(start + i + 1) % n][(start + j - 1) % n];
                    if (next > dp[j][skip + j - i - 1]) {
                        dp[j][skip + j - i - 1] = next;
                        p[j][skip + j - i - 1] = i;
                    }
                }
            }
        }
        double curmx = 0, idx = 0;
        rep(i, 0, n)if (dp[i].back() > curmx)curmx = dp[i].back(), idx = i;
        if (curmx > mx) {
            mx = curmx;
            int j = k;
            exclude.clear();
            while (idx != 0) {
                int next = p[idx][j];
                repr(i, idx - 1, next + 1)exclude.pb((i + start) % n);
                j -= idx - next - 1;
                idx = next;
            }
        }
    }
    int pt = 0;
    sort(all(exclude));
    rep(i, 0, n) {
        if (pt < sz(exclude) && exclude[pt] == i)pt++;
        else pr(i + 1);
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