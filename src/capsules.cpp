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

vector<vi> grid, region;
vector<vb> used;
int r, c;

bool dfs(int x, int y) {
    if (x >= r)return true;
    if (grid[x][y] != 0) {
        if (y == c - 1)return dfs(x + 1, 0);
        else return dfs(x, y + 1);
    }
    int curr = region[x][y];
    for (int i = 1; i < used[curr].size(); i++) {
        if (!used[curr][i]) {
            if (x > 0) {
                if (y > 0) {
                    if (grid[x - 1][y - 1] == i)continue; //up left
                }
                if (grid[x - 1][y] == i)continue; //up
                if (y < c - 1) {
                    if (grid[x - 1][y + 1] == i)continue; //up right
                }
            }
            if (y > 0)if (grid[x][y - 1] == i)continue; //left
            if (y < c - 1)if (grid[x][y + 1] == i)continue; //right
            if (x < r - 1) {
                if (y > 0) {
                    if (grid[x + 1][y - 1] == i)continue; //down left
                }
                if (grid[x + 1][y] == i)continue; //down
                if (y < c - 1)if (grid[x + 1][y + 1] == i)continue; //down right
            }
            grid[x][y] = i;
            used[curr][i] = true;
            if (y == c - 1) {
                if (dfs(x + 1, 0))return true;
            } else if (dfs(x, y + 1))return true;
            used[curr][i] = false;
        }
    }
    grid[x][y] = 0;
    return false;
}

inline void solve() {
    cin >> r >> c;
    grid.assign(r, vi(c)), region.assign(r, vi(c));
    string s;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            cin >> s;
            if (s == "-")grid[i][j] = 0;
            else grid[i][j] = stoi(s);
        }
    int n, t, counter = 0;
    cin >> n;
    used.reserve(n);
    forloop(0, n) {
        cin >> t;
        used.push_back(vb(t + 1));
        while (t--) {
            cin >> s;
            region[s[1] - '1'][s[3] - '1'] = counter;
        }
        counter++;
    }
    for (int i = 0; i < r; i++)for (int j = 0; j < c; j++)if (grid[i][j] != 0)used[region[i][j]][grid[i][j]] = true;
    dfs(0, 0);
    for (auto v: grid)print(v);
}

int main() {
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}