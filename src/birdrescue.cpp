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

inline int LSOne(int i) { return i & -i; }

struct FT {                              // index 0 is not used
    vi ft;                                        // internal FT is an array
    FT(int m) { ft.assign(m + 1, 0); }      // create an empty FT

    inline int rsq(int j) {                                // returns RSQ(1, j)
        int sum = 0;
        for (; j; j -= LSOne(j))
            sum += ft[j];
        return sum;
    }

    // updates value of the i-th element by v (v can be +ve/inc or -ve/dec)
    inline void update(int i, int v) {
        for (; i < (int) ft.size(); i += LSOne(i))
            ft[i] += v;
    }
};

inline void solve() {
    int n, q, a, b, x1, x2, y1, y2, mn, mx;
    cin >> n >> q >> a >> b;
    FT ft(2e6);
    forloop(0, n) {
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2)swap(x1, x2);
        if (y1 > y2)swap(y1, y2);
        int x3 = abs(x1 - a);
        int x4 = abs(x2 - a);
        int y3 = abs(y1 - b);
        int y4 = abs(y2 - b);
        int d = x3 + y3, f = x3 + y4, g = x4 + y3, h = x4 + y4;
        if (x1 <= a && a <= x2) {
            if (y1 <= b && b <= y2)mn = 0;
            else mn = min(y3, y4);
        } else if (y1 <= b && b <= y2)mn = min(x3, x4);
        else mn = min(min(d, f), min(g, h));
        mx = max(max(d, f), max(g, h));
        ft.update(mn + 1, 1);
        ft.update(mx + 2, -1);
    }
    while (q--) {
        cin >> a;
        pnl(ft.rsq(a + 1));
    }
}

int main() {
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}