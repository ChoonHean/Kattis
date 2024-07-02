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
    int n, m;
    cin >> n >> m;
    vi indeg(n + 1), outdeg(n + 1);
    int u, v;
    forloop(0, m) {
        cin >> u >> v;
        outdeg[u]++;
        indeg[v]++;
    }
    int out = -1, in = -1;
    forloop(1, n + 1) {
        int diff = indeg[i] - outdeg[i];
        if (diff == 0)continue;
        if (diff == 1) {
            if (in != -1) {
                cout << "no";
                return;
            }
            in = i;
        } else if (diff == -1) {
            if (out != -1) {
                cout << "no";
                return;
            }
            out = i;
        } else {
            cout << "no";
            return;
        }
    }
    if (out == -1 ^ in == -1)cout << "no";
    else if (out == -1)cout << "anywhere";
    else cout << out << ' ' << in;
}

int main() {
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}