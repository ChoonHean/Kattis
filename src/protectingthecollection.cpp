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
#define clz(i) __builtin_clz(i)
#define ctz(i) __builtin_ctz(i)
#define popcount(i) __builtin_popcount(i)
#define lsb(i) i&-i

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

inline void solve() {
    int n, c, r;
    cin >> n >> c >> r;
    vector<vc> grid(n, vc(n));
    rep(0, n)for (int j = 0; j < n; j++)cin >> grid[i][j];
    int dir = 2; // up:0, right:1, down:2, left:3
    for (int x = 0, y = c - 1; x >= 0 && x < n && y >= 0 && y < n;) {
        if (grid[x][y] == '/') {
            if (dir == 0) {
                dir = 1;
                y++;
            } else if (dir == 1) {
                dir = 0;
                x--;
            } else if (dir == 2) {
                dir = 3;
                y--;
            } else {
                dir = 2;
                x++;
            }
        } else if (grid[x][y] == '\\') {
            if (dir == 0) {
                dir = 3;
                y--;
            } else if (dir == 1) {
                dir = 2;
                x++;
            } else if (dir == 2) {
                dir = 1;
                y++;
            } else {
                dir = 0;
                x--;
            }
        } else {
            grid[x][y] = 'o';
            if (dir == 0)x--;
            else if (dir == 1)y++;
            else if (dir == 2)x++;
            else y--;
        }
    }
    dir = 3;
    for (int x = r - 1, y = n - 1; x >= 0 && x < n && y >= 0 && y < n;) {
        if (grid[x][y] == 'o') {
            pr("YES");
            return;
        } else if (grid[x][y] == '/') {
            if (dir == 0) {
                dir = 1;
                y++;
            } else if (dir == 1) {
                dir = 0;
                x--;
            } else if (dir == 2) {
                dir = 3;
                y--;
            } else {
                dir = 2;
                x++;
            }
        } else if (grid[x][y] == '\\') {
            if (dir == 0) {
                dir = 3;
                y--;
            } else if (dir == 1) {
                dir = 2;
                x++;
            } else if (dir == 2) {
                dir = 1;
                y++;
            } else {
                dir = 0;
                x--;
            }
        } else {
            if (dir == 0)x--;
            else if (dir == 1)y++;
            else if (dir == 2)x++;
            else y--;
        }
    }
    pr("NO");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}