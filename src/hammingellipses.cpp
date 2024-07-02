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

template<typename T>
inline void print(T it) {
    for (auto i = it.begin(); i != it.end(); i++) {
        cout << *i << " ";
    }
    cout << nl;
}

template<typename T>
inline void print_p(T v) {
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << "(" << (*it).first << "," << (*it).second << ") ";
    }
    cout << nl;
}

inline void solve() {
    int n, q, d;
    cin >> q >> n >> d;
    string s1, s2;
    cin >> s1 >> s2;
    vector<vl> dp(n, vl(d + 1));
    if (s1[0] == s2[0]) {
        dp[0][0] = 1;
        dp[0][2] = q - 1;
    } else {
        dp[0][1] = 2;
        dp[0][2] = q - 2;
    }
    for (int i = 1; i < n; i++) {
        if (s1[i] == s2[i]) {
            for (int j = 0; j < 2; j++) {
                dp[i][j] = dp[i - 1][j];
            }
            for (int j = 2; j <= d; j++) {
                dp[i][j] = dp[i - 1][j - 2] * (q - 1) + dp[i - 1][j];
            }
        } else {
            dp[i][1] = dp[i - 1][0] * 2;
            for (int j = 2; j <= d; j++) {
                dp[i][j] = dp[i - 1][j - 2] * (q - 2) + dp[i - 1][j - 1] * 2;
            }
        }
    }
    cout << dp[n - 1][d];
}

int main() {
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}