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
    int n;
    cin >> n;
    int res = (1 << (n + 1)) - 1;
    read(1 << n);
    vi tree(1 << n);
    for (int i = 0; i < 1 << n; i++) {
        int j = 0;
        for (int k = 0; k < n; k++)j |= ((i >> k) & 1) << (n - k - 1);
        tree[j] = arr[i];
    }
    int counter = 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 1 << n; j += 1 << (i + 1)) {
            if (tree[j] == tree[j + (1 << i)])res -= 2;
            else tree[j] = counter++;
        }
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