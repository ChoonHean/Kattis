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
int mod = 1e9 + 7;
#define all(a) a.begin(),a.end()
#define read(n) vi arr(n);for(int i=0;i<n;i++)cin>>arr[i]
#define readarr(n, arr) for(int i=0;i<n;i++)cin>>arr[i]
#define range(a, n) for(int i=a;i<n;i++)
#define nl "\n"
#define sz(v) ((int)v.size())
#define pb push_back

template<typename T>
inline void p(T t) { cout << t << ' '; }

template<typename T>
inline void pnl(T t) {
    p(t);
    cout << nl;
}

template<typename T, typename U>
inline void p(pair<T, U> pa) {
    cout << '(';
    p(pa.first);
    cout << ',';
    p(pa.second);
    cout << ") ";
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

void solve() {
    mod = 1000003;
    int n, m, init, x = -1, y = -1;
    cin >> n >> m >> init;
    vs arr(n);
    for (int i = 0; i < n; i++)cin >> arr[i];
    for (int i = 0; i < n && x == -1; i++) {
        for (int j = 0; j < m; j++)
            if (arr[i][j] == '@') {
                x = i;
                y = j;
                break;
            }
    }
    vector<vi> dp(n, vi(m, -1));
    dp.back()[init] = 1;
    for (int i = n - 1; i >= max(1, x); i--) {
        for (int j = 0; j < m; j++) {
            if (dp[i][j] == -1)continue;
            if (arr[i][j] == '>')dp[i][j + 1] = (max(dp[i][j + 1], 0) + dp[i][j]) % mod;
        }
        for (int j = m - 1; j > 0; j--) {
            if (dp[i][j] == -1)continue;
            if (arr[i][j] == '<')dp[i][j - 1] = (max(dp[i][j - 1], 0) + dp[i][j]) % mod;
        }
        for (int j = 0; j < m; j++) {
            if (dp[i][j] == -1)continue;
            if (arr[i][j] != '#')dp[i - 1][j] = dp[i][j];
        }
    }
    if (x == 0) {
        for (int j = 0; j < m; j++) {
            if (dp[0][j] == -1)continue;
            if (arr[0][j] == '>')dp[0][j + 1] = (max(dp[0][j + 1], 0) + dp[0][j]) % mod;
        }
        for (int j = m - 1; j > 0; j--) {
            if (dp[0][j] == -1)continue;
            if (arr[0][j] == '<')dp[0][j - 1] = (max(dp[0][j - 1], 0) + dp[0][j]) % mod;
        }
    }
    dp[x][y] == -1 ? pnl("begin repairs") : pnl(dp[x][y]);
}

int main() {
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}