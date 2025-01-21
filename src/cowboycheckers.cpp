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
    vs arr(7);
    for (string &s: arr)cin >> s;
    arr[3][3] = 'B';
    vvi pos{
            {0, 0, 0, 3, 0, 6},
            {1, 1, 1, 3, 1, 5},
            {2, 2, 2, 3, 2, 4},
            {3, 0, 3, 1, 3, 2},
            {3, 4, 3, 5, 3, 6},
            {4, 2, 4, 3, 4, 4},
            {5, 1, 5, 3, 5, 5},
            {6, 0, 6, 3, 6, 6},
            {0, 0, 3, 0, 6, 0},
            {1, 1, 3, 1, 5, 1},
            {2, 2, 3, 2, 4, 2},
            {0, 3, 1, 3, 2, 3},
            {4, 3, 5, 3, 6, 3},
            {2, 4, 3, 4, 4, 4},
            {1, 5, 3, 5, 5, 5},
            {0, 6, 3, 6, 6, 6}
    };
    auto check = [&arr](vi v) {
        return arr[v[0]][v[1]] == 'W' && arr[v[2]][v[3]] == 'W' && arr[v[4]][v[5]] == 'W';
    };
    for (vi &v: pos) {
        if (check(v)) {
            rep(i, 0, 3) {
                int a = v[i * 2], b = v[i * 2 + 1];
                arr[a][b] = '#';
                for (int k = a - 1; k >= 0; k--) {
                    if (arr[k][b] == '.') {
                        arr[k][b] = 'W';
                        for (vi &u: pos) {
                            if ((u[0] == k && u[1] == b) || (u[2] == k && u[3] == b) || (u[4] == k && u[5] == b))
                                if (check(u)) {
                                    cout << "double mill";
                                    return;
                                }
                        }
                        arr[k][b] = '.';
                    } else if (arr[k][b] != '|')break;
                }
                for (int k = a + 1; k < 7; k++) {
                    if (arr[k][b] == '.') {
                        arr[k][b] = 'W';
                        for (vi &u: pos) {
                            if ((u[0] == k && u[1] == b) || (u[2] == k && u[3] == b) || (u[4] == k && u[5] == b))
                                if (check(u)) {
                                    cout << "double mill";
                                    return;
                                }
                        }
                        arr[k][b] = '.';
                    } else if (arr[k][b] != '|')break;
                }
                for (int l = b - 1; l >= 0; l--) {
                    if (arr[a][l] == '.') {
                        arr[a][l] = 'W';
                        for (vi &u: pos) {
                            if ((u[0] == a && u[1] == l) || (u[2] == a && u[3] == l) || (u[4] == a && u[5] == l))
                                if (check(u)) {
                                    cout << "double mill";
                                    return;
                                }
                        }
                        arr[a][l] = '.';
                    } else if (arr[a][l] != '-')break;
                }
                for (int l = b + 1; l < 7; l++) {
                    if (arr[a][l] == '.') {
                        arr[a][l] = 'W';
                        for (vi &u: pos) {
                            if ((u[0] == a && u[1] == l) || (u[2] == a && u[3] == l) || (u[4] == a && u[5] == l))
                                if (check(u)) {
                                    cout << "double mill";
                                    return;
                                }
                        }
                        arr[a][l] = '.';
                    } else if (arr[a][l] != '-')break;
                }
                arr[a][b] = 'W';
            }
        }
    }
    cout << "no double mill";
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