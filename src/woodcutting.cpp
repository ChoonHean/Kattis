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
    int n, w, x;
    cin >> n;
    vi arr(n);
    forloop(0, n) {
        cin >> w;
        while (w--) {
            cin >> x;
            arr[i] += x;
        }
    }
    sort(all(arr));
    ll res = 0, sum = 0;
    forloop(0, n) {
        sum += arr[i];
        res += sum;
    }
    cout << res / (double) n << nl;
}

int main() {
    int t = 1;
    cin >> t;
    cout << fixed << setprecision(10);
    while (t--) {
        solve();
    }
    return 0;
}