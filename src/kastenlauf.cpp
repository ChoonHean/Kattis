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
    int n, x, y;
    cin >> n >> x >> y;
    vector<pii> arr(n + 1);
    forloop(0, n + 1) {
        cin >> arr[i].first >> arr[i].second;
    }
    queue<int> q;
    vb visited(n + 1);
    for (int i = 0; i <= n; i++) {
        pii p = arr[i];
        int dist = abs(x - p.first) + abs(y - p.second);
        if (dist <= 1000) {
            q.push(i);
            visited[i] = true;
        }
    }
    while (!q.empty() && !visited[n]) {
        int curr = q.front();
        x = arr[curr].first, y = arr[curr].second;
        q.pop();
        for (int i = 0; i <= n; i++) {
            if (!visited[i]) {
                pii p = arr[i];
                int dist = abs(x - p.first) + abs(y - p.second);
                if (dist <= 1000) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }
    if (visited[n])cout << "happy" << nl;
    else cout << "sad" << nl;
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}