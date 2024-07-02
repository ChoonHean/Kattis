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

struct UFDS {
    vi p;
    int sets;

    UFDS(int n) {
        p.reserve(n);
        sets = n;
        for (int i = 0; i < n; i++)p.push_back(i);
    }

    int find(int n) {
        if (n == p[n])return n;
        return p[n] = find(p[n]);
    }

    inline bool sameset(int x, int y) { return find(x) == find(y); }

    inline void unionset(int x, int y) {
        sets--;
        p[find(x)] = p[find(y)];
    }
};

inline double dist(pii a, pii b) { return (abs(a.first - b.first) + abs(a.second - b.second)) << 1; }

inline void solve() {
    int n;
    cin >> n;
    vector<pii> arr(n);
    vector<tuple<double, int, int>> edges;
    forloop(0, n) {
        cin >> arr[i].first >> arr[i].second;
        for (int j = 0; j < i; j++)edges.push_back(tuple(dist(arr[i], arr[j]), i, j));
    }
    sort(all(edges));
    int res = 0, i = 0;
    UFDS ufds(n);
    while (ufds.sets != 1) {
        auto curr = edges[i++];
        if (!ufds.sameset(get<1>(curr), get<2>(curr))) {
            res += get<0>(curr);
            ufds.unionset(get<1>(curr), get<2>(curr));
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