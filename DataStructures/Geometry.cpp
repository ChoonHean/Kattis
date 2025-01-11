// From CP4 (Steven Halim, Felix Halim, Suhendry Effendy)
// https://github.com/stevenhalim/cpbook-code
#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

double DEG_to_RAD(double d) { return d * M_PI / 180.0; }

double RAD_to_DEG(double r) { return r * 180.0 / M_PI; }

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

struct vec {
    double x, y;

    vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(point a, point b) {       // convert 2 points to vector a->b
    return vec(b.x - a.x, b.y - a.y);
}

double dist(point p1, point p2) {                // Euclidean distance
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

double perimeter(const vector<point> &P) {       // by ref for efficiency
    double ans = 0.0;
    for (int i = 0; i < (int) P.size() - 1; ++i)      // note: P[n-1] = P[0]
        ans += dist(P[i], P[i + 1]);                   // as we duplicate P[0]
    return ans;
}

double area(const vector<point> &P) {
    double ans = 0.0;
    for (int i = 0; i < (int) P.size() - 1; ++i)      // Shoelace formula
        ans += (P[i].x * P[i + 1].y - P[i + 1].x * P[i].y);
    return fabs(ans) / 2.0;                          // only do / 2.0 here
}

double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }

double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

double angle(point a, point o, point b) {  // returns angle aob in rad
    vec oa = toVec(o, a), ob = toVec(o, b);
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

// returns the area of polygon P, which is half the cross products
// of vectors defined by edge endpoints
double area_alternative(const vector<point> &P) {
    double ans = 0.0;
    point O(0.0, 0.0);           // O = the Origin
    for (int i = 0; i < (int) P.size() - 1; ++i)      // sum of signed areas
        ans += cross(toVec(O, P[i]), toVec(O, P[i + 1]));
    return fabs(ans) / 2.0;
}

// note: to accept collinear points, we have to change the `> 0'
// returns true if point r is on the left side of line pq
bool ccw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) > 0;
}

// returns true if point r is on the same line as the line pq
bool collinear(point p, point q, point r) {
    return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;
}

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

point lineIntersectSeg(point p, point q, point A, point B) {
    double a = B.y - A.y, b = A.x - B.x, c = B.x * A.y - A.x * B.y;
    double u = fabs(a * p.x + b * p.y + c);
    double v = fabs(a * q.x + b * q.y + c);
    return point((p.x * v + q.x * u) / (u + v), (p.y * v + q.y * u) / (u + v));
}

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