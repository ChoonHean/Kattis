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

bool b = true;
const int N = 10001;
vi marbles(N), p(N), indeg(N);

inline void solve() {
    int n, t, v;
    cin >> n;
    if (n == 0) {
        b = false;
        return;
    }
    vector<vi> adj(n);
    queue<int> q;
    forloop(0, n) {
        cin >> t >> marbles[i] >> t;
        indeg[i] = t;
        if (t == 0)q.push(i);
        while (t--) {
            cin >> v;
            adj[--v].push_back(i);
            p[v] = i;
        }
    }
    int res = 0;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        int xfer = marbles[curr] - 1;
        marbles[p[curr]] += xfer;
        res += abs(xfer);
        for (int i: adj[curr]) {
            if (indeg[i] == 1)q.push(i);
            else indeg[i]--;
        }
    }
    cout << res << nl;
}

int main() {
    int t = 1;
    //cin >> t;
    while (b) {
        solve();
    }
    return 0;
}