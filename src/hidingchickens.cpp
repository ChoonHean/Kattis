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

inline void solve() {
    double a, b;
    int n;
    cin >> a >> b >> n;
    vpdd arr(n);
    rep(0, n)cin >> arr[i].first >> arr[i].second;
    vector<vd> dist(n + 1, vd(n + 1));
    rep(0, n) {
        double x = arr[i].first - a, y = arr[i].second - b;
        dist[i][n] = sqrt(x * x + y * y);
        for (int j = i + 1; j < n; j++) {
            x = arr[i].first - arr[j].first;
            y = arr[i].second - arr[j].second;
            dist[i][j] = sqrt(x * x + y * y);
        }
    }
    vd dp(1 << n, inf);
    dp[0] = 0;
    int end = (1 << n) - 1;
    rep(0, 1 << n) {
        for (int j = 0; j < n; j++)
            if (!((i >> j) & 1)) {
                int next = i | (1 << j);
                if (next == end)dp[next] = min(dp[next], dp[i] + dist[j][n]);
                else dp[next] = min(dp[next], dp[i] + 2 * dist[j][n]);
                for (int k = j + 1; k < n; k++)
                    if (!((i >> k) & 1)) {
                        int next2 = next | (1 << k);
                        if (next2 == end)dp[next2] = min(dp[next2], dp[i] + min(dist[j][n], dist[k][n]) + dist[j][k]);
                        else dp[next2] = min(dp[next2], dp[i] + dist[j][n] + dist[k][n] + dist[j][k]);
                    }
            }
    }
    cout << fixed << setprecision(10);
    pr(dp.back());
}

int main() {
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}