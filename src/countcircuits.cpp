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
#define pb push_back

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
    for (auto t: m)pr(t);
    cout << nl;
}

template<typename T, typename U>
inline void pr(unordered_map<T, U> m) {
    for (auto t: m)pr(t);
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

int n;
vpii arr;
vector<vvvl> dp(401, vvvl(401, vvl(40, vl(2, -1))));

ll f(int i, int x, int y, int cnt) {
    if (x < 0 || y < 0 || x > 400 || y > 400)return 0;
    if (i == n)return (x == 200) && (y == 200) & cnt;
    if (dp[x][y][i][cnt] != -1)return dp[x][y][i][cnt];
    if (x == 200 && y == 200) {
        if (cnt) {
            dp[x][y][i][cnt] = 1 + f(i + 1, x + arr[i].first, y + arr[i].second, 1) + f(i + 1, x, y, 0);
        } else {
            dp[x][y][i][cnt] = f(i + 1, x + arr[i].first, y + arr[i].second, 1) + f(i + 1, x, y, 0);
        }
    } else {
        dp[x][y][i][cnt] = f(i + 1, x + arr[i].first, y + arr[i].second, 1) + f(i + 1, x, y, 1);
    }
    return dp[x][y][i][cnt];
}

inline void solve() {
    cin >> n;
    arr.resize(n);
    rep(0, n)cin >> arr[i].first >> arr[i].second;
    pr(f(0, 200, 200, 0));
}

int main() {
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}