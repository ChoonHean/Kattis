#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
const int inf = 1e9;
const int mod = 1e9 + 7;
#define all(a) a.begin(),a.end()
#define read(n) vi arr(n);for(int i=0;i<n;i++)cin>>arr[i]
#define readarr(n, arr) for(int i=0;i<n;i++)cin>>arr[i]
#define forloop(a, n) for(int i=a;i<n;i++)
#define nl "\n"
#define sz(v) ((int)v.size())
#define pb push_back

template<typename T, typename U>
inline void p(pair<T, U> p) { cout << '(' << p.first << ',' << p.second << ") "; }

template<typename T>
inline void p(T t) { cout << t << ' '; }

template<typename T>
inline void pnl(T t) {
    p(t);
    cout << nl;
}

template<typename T>
inline void p(vector<T> v) {
    for (auto i: v) p(i);
    cout << nl;
}

template<typename T>
inline void p(vector<vector<T>> v) {
    for (auto row: v) p(row);
}

template<typename T>
inline void p(set<T> s) {
    for (auto t: s)p(t);
    cout << nl;
}

template<typename T>
inline void p(unordered_set<T> s) {
    for (auto t: s)p(t);
    cout << nl;
}

template<typename T, typename U>
inline void p(map<T, U> m) {
    for (auto t: m)p(t);
    cout << nl;
}

template<typename T, typename U>
inline void p(unordered_map<T, U> m) {
    for (auto t: m)p(t);
    cout << nl;
}

template<typename T>
inline void p(queue<T> q) {
    queue<T> copy(q);
    while (!copy.empty()) {
        p(copy.front());
        copy.pop();
    }
    cout << nl;
}

template<typename T>
inline void p(stack<T> s) {
    stack<T> copy(s);
    while (!copy.empty()) {
        p(copy.top());
        copy.pop();
    }
    cout << nl;
}

const double pi2 = M_PI * 2, eps = 1e-4;

inline void solve() {
    int n;
    double r, x, y, rocket, virus;
    cin >> r >> n;
    vd time(n), loc(n);
    vi speed(n);
    forloop(0, n) {
        cin >> x >> y >> rocket >> virus;
        double dist = sqrt(x * x + y * y);
        time[i] = (dist - r) / rocket;
        speed[i] = virus;
        double angle = atan2(y, x);
        if (angle < 0)angle += pi2;
        loc[i] = angle * r;
    }
    double end = pi2 * r;
    double lo = 0, hi = 1e7;
    while (abs(hi - lo) > eps) {
        vector<pdd> intervals;
        double mid = (lo + hi) / 2;
        forloop(0, n) {
            if (mid < time[i])continue;
            double t = mid - time[i];
            double reach = loc[i] - t * speed[i];
            if (reach < 0) {
                if (reach + end < loc[i]) {
                    intervals.pb(pair(0, end));
                    break;
                }
                intervals.pb(pair(reach + end, end));
                intervals.pb(pair(0, loc[i]));
            } else intervals.pb(pair(reach, loc[i]));
            reach = loc[i] + t * speed[i];
            if (reach > end) {
                intervals.pb(pair(loc[i], end));
                intervals.pb(pair(0, reach - end));
            } else intervals.pb(pair(loc[i], reach));
        }
        sort(all(intervals));
        if (intervals.empty())lo = mid;
        else if (intervals[0].first > 0)lo = mid;
        else {
            double curr = 0;
            for (auto p: intervals) {
                if (p.first > curr)break;
                else curr = max(curr, p.second);
            }
            if (curr == end)hi = mid;
            else lo = mid;
        }
    }
    pnl(lo);
}

int main() {
    int t = 1;
    cin >> t;
    cout << fixed << setprecision(5);
    while (t--) {
        solve();
    }
    return 0;
}