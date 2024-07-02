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
    vi p, size;
    int sets;

    UFDS(int n) {
        p.reserve(n);
        sets = n;
        for (int i = 0; i < n; i++)p.push_back(i);
        size.assign(n, 1);
    }

    int find(int n) {
        if (n == p[n])return n;
        return p[n] = find(p[n]);
    }

    inline bool sameset(int x, int y) { return find(x) == find(y); }

    inline void unionset(int x, int y) {
        sets--;
        x = find(x);
        y = find(y);
        p[y] = x;
        size[x] += size[y];
    }

    inline int sz(int n) { return size[find(n)]; }
};

inline void solve() {
    int n;
    cin >> n;
    UFDS ufds(n << 1);
    unordered_map<string, int> mapper;
    int counter = 0, x, y;
    string s1, s2;
    forloop(0, n) {
        cin >> s1 >> s2;
        if (mapper.contains(s1))x = mapper[s1];
        else x = mapper[s1] = counter++;
        if (mapper.contains(s2))y = mapper[s2];
        else y = mapper[s2] = counter++;
        if (!ufds.sameset(x, y))ufds.unionset(x, y);
        cout << ufds.sz(x) << nl;
    }
}

int main() {
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}