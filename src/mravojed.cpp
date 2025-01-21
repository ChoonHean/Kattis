#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<pll> vpll;
typedef vector<pdd> vpdd;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
        ordered_set;
const int inf = 1e9;
const int mod = 1e9 + 7;
const double EPS = 1e-9;
#define all(a) a.begin(),a.end()
#define read(n) vi arr(n);for(int&_:arr)cin>>_
#define readarr(n, arr) for(auto&_:arr)cin>>_
#define rep(i, a, n) for(int i=a;i<n;i++)
#define nl "\n"
#define sz(v) ((int)v.size())
#define PQ priority_queue
#define hmap unordered_map
#define hset unordered_set
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define clz(i) __builtin_clz(i)
#define ctz(i) __builtin_ctz(i)
#define popcount(i) __builtin_popcount(i)
#define lsb(i) (i&-i)
mt19937_64 rnd(time(0));


template<typename T>
inline void pr(T t) { cout << t << ' '; }


template<typename T, typename U>
inline void pr(pair<T, U> pa) {
    cout << '(';
    pr(pa.first);
    cout << ',';
    pr(pa.second);
    cout << ") ";
}

template<typename T>
inline void pr(vector<T> v) {
    for (auto i: v) pr(i);
    cout << nl;
}

template<typename T>
inline void pr(set<T> s) {
    for (auto t: s)pr(t);
    cout << nl;
}

template<typename T>
inline void pr(unordered_set<T> s) {
    for (auto t: s)pr(t);
    cout << nl;
}

template<typename T, typename U>
inline void pr(map<T, U> m) {
    for (auto [t, u]: m) {
        cout << '(';
        pr(t);
        pr('-');
        pr(u);
        pr(')');
    }
    cout << nl;
}

template<typename T, typename U>
inline void pr(unordered_map<T, U> m) {
    for (auto [t, u]: m) {
        cout << '(';
        pr(t);
        pr('-');
        pr(u);
        pr(')');
    }
    cout << nl;
}

template<typename T>
inline void pr(queue<T> q) {
    queue<T> copy(q);
    while (!copy.empty()) {
        pr(copy.front());
        copy.pop();
    }
    cout << nl;
}

template<typename T>
inline void pr(stack<T> s) {
    stack<T> copy(s);
    while (!copy.empty()) {
        pr(copy.top());
        copy.pop();
    }
    cout << nl;
}

template<typename T>
inline void pr(deque<T> q) {
    deque<T> copy(q);
    while (!copy.empty()) {
        pr(copy.top());
        copy.pop();
    }
    cout << nl;
}

template<typename T>
inline void pr(PQ<T> pq) {
    PQ<T> copy(pq);
    vector<T> arr;
    while (!copy.empty()) {
        arr.pb(copy.top());
        copy.pop();
    }
    pr(arr);
    cout << nl;
}

template<typename T>
inline void pr(PQ<T, vector<T>, greater<T>> pq) {
    auto copy(pq);
    vector<T> arr;
    while (!copy.empty()) {
        arr.pb(copy.top());
        copy.pop();
    }
    pr(arr);
    cout << nl;
}

template<typename T>
inline void pnl(T t) {
    pr(t);
    cout << nl;
}

inline void solve() {
    int r, c;
    cin >> r >> c;
    vs arr(r);
    vector<pair<pii, int>> res;
    rep(i, 0, r)cin >> arr[i];
    bool cont = true;
    for (int i = 0; i < r && cont; i++)
        rep(j, 0, c)
            if (arr[i][j] == 'x') {
                int k = i + 1;
                while (k < r && arr[k][j] == 'x')k++;
                int l = j + 1;
                while (l < c && arr[i][l] == 'x')l++;
                int len = min(k - i, l - j);
                res.pb({{i + 1, j + 1}, len});
                cont = false;
                for (int a = i; a < i + len; a++)
                    for (int b = j; b < j + len; b++) {
                        arr[a][b] = '-';
                    }
                break;
            }
    cont = true;
    for (int i = r - 1; i >= 0 && cont; i--)
        rep(j, 0, c)
            if (arr[i][j] == 'x') {
                int k = i - 1;
                while (k >= 0 && (arr[k][j] == 'x' || arr[k][j] == '-'))k--;
                int l = j + 1;
                while (l < c && (arr[i][l] == 'x' || arr[i][l] == '-'))l++;
                int len = min(i - k, l - j);
                res.pb({{i - len + 2, j + 1}, len});
                cont = false;
                break;
            }
    cont = true;
    for (int i = 0; i < r && cont; i++)
        for (int j = c - 1; j >= 0; j--)
            if (arr[i][j] == 'x') {
                int k = i + 1;
                while (k < r && (arr[k][j] == 'x' || arr[k][j] == '-'))k++;
                int l = j - i;
                while (l >= 0 && (arr[i][l] == 'x' || arr[i][l] == '-'))l--;
                int len = min(k - i, j - l);
                if (len > res.back().second) {
                    res.back().first = {i + 1, j - len + 2};
                    res.back().second = len;
                }
                cont = false;
                break;
            }
    cont = true;
    for (int i = r - 1; r >= 0 && cont; r--)
        for (int j = c - 1; j >= 0; j--)
            if (arr[i][j] == 'x') {
                int k = i - 1;
                while (k >= 0 && (arr[k][j] == 'x' || arr[k][j] == '-'))k--;
                int l = j - 1;
                while (l >= 0 && (arr[i][l] == 'x' || arr[i][l] == '-'))l--;
                int len = min(i - k, j - l);
                if (len > res.back().second) {
                    res.back().first = {i - len + 2, j - len + 2};
                    res.back().second = len;
                }
                cont = false;
                break;
            }
    for (auto &[a, b]: res)pr(a.first), pr(a.second), pnl(b);
    if (sz(res) == 1)for (auto &[a, b]: res)pr(a.first), pr(a.second), pnl(b);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(10);
    int t = 1;
//    cin >> t;
    while (t--)solve();
    return 0;
}