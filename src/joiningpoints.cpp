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

inline void solve() {
    int n;
    cin >> n;
    vpii arr(n);
    int mnx = inf, mxx = -inf, mny = inf, mxy = -inf;
    rep(0, n) {
        cin >> arr[i].first >> arr[i].second;
        mnx = min(mnx, arr[i].first);
        mxx = max(mxx, arr[i].first);
        mny = min(mny, arr[i].second);
        mxy = max(mxy, arr[i].second);
    }
    for (auto [x, y]: arr)
        if (x != mxx && x != mnx && y != mny && y != mxy) {
            pr("Impossible");
            return;
        }
    int a = mxx - mnx, b = mxy - mny;
    if (a == b) {
        pr(mnx);
        pr(mxx);
        pr(mny);
        pr(mxy);
    } else if (a > b) { //extend y
        int cnt1 = 0, cnt2 = 0;
        for (auto [x, y]: arr) {
            if (y == mxy && x != mnx && x != mxx)cnt1++;
            else if (y == mny && x != mnx && x != mxx)cnt2++;
        }
        if (cnt1 == 0) {
            pr(mnx);
            pr(mxx);
            pr(mny);
            pr(mny + a);
        } else if (cnt2 == 0) {
            pr(mnx);
            pr(mxx);
            pr(mxy - a);
            pr(mxy);
        } else pr("Impossible");
    } else {
        int cnt1 = 0, cnt2 = 0;
        for (auto [x, y]: arr) {
            if (x == mxx & y != mny && y != mxy)cnt1++;
            else if (x == mnx && y != mny && y != mxy)cnt2++;
        }
        if (cnt1 == 0) {
            pr(mnx);
            pr(mnx + b);
            pr(mny);
            pr(mxy);
        } else if (cnt2 == 0) {
            pr(mxx - b);
            pr(mxx);
            pr(mny);
            pr(mxy);
        } else pr("Impossible");
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}