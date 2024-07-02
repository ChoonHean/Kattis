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
    string s;
    getline(cin, s);
    unordered_map<char, pii> map;
    vector<vc> grid(5, vc(5));
    int row = 0, col = 0;
    for (char c: s) {
        if (c == 'q' || c == ' ')continue;
        if (map.contains(c))continue;
        map[c] = pair(row, col);
        grid[row][col] = toupper(c);
        col++;
        if (col == 5) {
            col = 0;
            row++;
        }
    }
    for (char c = 'a'; c <= 'z'; c++) {
        if (c == 'q')continue;
        if (map.contains(c))continue;
        map[c] = pair(row, col);
        grid[row][col] = toupper(c);
        col++;
        if (col == 5) {
            col = 0;
            row++;
        }
    }
    string res;
    getline(cin, s);
    for (int i = 0;;) {
        if (s[i] == ' ')s.erase(i, 1);
        else i++;
        if (i >= s.size())break;
    }
    char a, b;
    for (int i = 0; i < s.size(); i++) {
        a = s[i];
        if (i == s.size() - 1)b = 'x';
        else if (s[i] == s[i + 1])b = 'x';
        else b = s[++i];
        pii x = map[a], y = map[b];
        if (x.first == y.first) {
            res += grid[x.first][(x.second + 1) % 5];
            res += grid[y.first][(y.second + 1) % 5];
        } else if (x.second == y.second) {
            res += grid[(x.first + 1) % 5][x.second];
            res += grid[(y.first + 1) % 5][y.second];
        } else {
            res += grid[x.first][y.second];
            res += grid[y.first][x.second];
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