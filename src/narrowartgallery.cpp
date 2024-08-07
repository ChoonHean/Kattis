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

bool c = true;

inline void solve() {
    int n, k;
    cin >> n >> k;
    if ((n | k) == 0) {
        c = false;
        return;
    }
    vector<vi> arr(n, vi(2));
    forloop(0, n)cin >> arr[i][0] >> arr[i][1];
    vector<vector<vi>> dp(k + 1, vector<vi>(n, vi(2)));
    dp[0][0][0] = dp[0][0][1] = arr[0][0] + arr[0][1];
    if (k > 0) {
        dp[1][0][0] = arr[0][0];
        dp[1][0][1] = arr[0][1];
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j <= min(i + 1, k - 1); j++) {
            dp[j + 1][i + 1][0] = max(dp[j + 1][i + 1][0], dp[j][i][0] + arr[i + 1][0]);
            dp[j + 1][i + 1][1] = max(dp[j + 1][i + 1][1], dp[j][i][1] + arr[i + 1][1]);
            int x = max(dp[j][i][0], dp[j][i][1]) + arr[i + 1][0] + arr[i + 1][1];
            dp[j][i + 1][0] = max(dp[j][i + 1][0], x);
            dp[j][i + 1][1] = max(dp[j][i + 1][1], x);
        }
        if (i + 1 >= k)dp[k][i + 1][0] = dp[k][i + 1][1] = max(max(dp[k][i + 1][0], dp[k][i + 1][1]),
                                                               max(dp[k][i][0], dp[k][i][1]) + arr[i + 1][0] +
                                                               arr[i + 1][1]);
    }
    pnl(max(dp[k][n - 1][0], dp[k][n - 1][1]));
}

int main() {
    int t = 1;
    //cin >> t;
    while (c) {
        solve();
    }
    return 0;
}