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

struct UFDS {
    vi p;
    int sets;

    UFDS(int n) {
        p.reserve(n + 1);
        sets = n + 1;
        for (int i = 0; i <= n; i++)p.push_back(i);
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

inline double dist(pdd a, pdd b) {
    double c = a.first - b.first, d = a.second - b.second;
    return sqrt(c * c + d * d);
}

inline void solve() {
    int n, e, p, x, y;
    cin >> n >> e >> p;
    UFDS ufds(n);
    vector<pdd> arr(n);
    vector<tuple<double, int, int>> edges;
    for (int i = 0; i < e; i++) {
        cin >> arr[i].first >> arr[i].second;
        ufds.unionset(i, n);
    }
    for (int i = e; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
        for (int j = 0; j < i; j++) {
            edges.push_back(tuple(dist(arr[i], arr[j]), i, j));
        }
    }
    while (p--) {
        cin >> x >> y;
        x--;
        y--;
        if (!ufds.sameset(x, y))ufds.unionset(x, y);
    }
    sort(all(edges));
    int ptr = 0;
    double res = 0;
    while (ufds.sets != 1) {
        auto curr = edges[ptr++];
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