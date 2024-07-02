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
    int n, k, t;
    cin >> n >> k;
    int res = 0;
    vector<vs> arr(n);
    string s;
    forloop(0, n) {
        cin >> t;
        while (t--) {
            cin >> s;
            arr[i].push_back(s);
        }
    }
    for (int i = (1 << k) - 1; i < (1 << n); i++) {
        if (__builtin_popcount(i) != k)continue;
        unordered_map<string, int> mapper;
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) {
                for (string str: arr[j])mapper[str]++;
            }
        }
        for (auto [x, y]: mapper) {
            if (y * 2 > k) {
                res--;
                break;
            }
        }
        res++;
    }
    cout << res;
}

int main() {
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}