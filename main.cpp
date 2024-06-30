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
typedef pair<ll, ll> pll;
int inf = 1e9;
int mod = 1e9 + 7;
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
    int n, t;
    cin >> n;
    string s, s2;
    unordered_map<string, vs> mapper;
    unordered_map<string, int> counts, counts2;
    forloop(0, n) {
        cin >> s >> t;
        counts2[s] = 0;
        while (t--) {
            cin >> s2;
            mapper[s2].push_back(s);
        }
    }
    while (cin >> s)counts[s]++;
    for (auto [x, y]: counts)for (string s3: mapper[x])counts2[s3] += y;
    int mx = 0;
    for (auto [x, y]: counts2)mx = max(mx, y);
    vs ans;
    for (auto [x, y]: counts2)if (y == mx)ans.push_back(x);
    sort(all(ans));
    for (string s3: ans)cout << s3 << nl;
}

int main() {
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}