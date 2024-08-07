#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector <string> vs;
typedef vector<char> vc;
typedef long long ll;
typedef vector <ll> vl;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair <ll, ll> pll;
const int inf = 1e9;
const int mod = 1e9 + 7;
#define all(a) a.begin(),a.end()
#define read(n) vi arr(n);for(int i=0;i<n;i++)cin>>arr[i]
#define readarr(n, arr) for(int i=0;i<n;i++)cin>>arr[i]
#define forloop(a, n) for(int i=a;i<n;i++)
#define nl "\n"
#define sz(v) ((int)v.size())
#define pb push_back

template<typename T, typename U>
inline void p(pair <T, U> p) { cout << '(' << p.first << ',' << p.second << ") "; }

template<typename T>
inline void p(T t) { cout << t << ' '; }

template<typename T>
inline void pnl(T t) {
    p(t);
    cout << nl;
}

template<typename T>
inline void p(vector <T> v) {
    for (auto i: v) p(i);
    cout << nl;
}

template<typename T>
inline void p(vector <vector<T>> v) {
    for (auto row: v) p(row);
}

template<typename T>
inline void p(set <T> s) {
    for (auto t: s)p(t);
    cout << nl;
}

template<typename T>
inline void p(unordered_set <T> s) {
    for (auto t: s)p(t);
    cout << nl;
}

template<typename T, typename U>
inline void p(map <T, U> m) {
    for (auto t: m)p(t);
    cout << nl;
}

template<typename T, typename U>
inline void p(unordered_map <T, U> m) {
    for (auto t: m)p(t);
    cout << nl;
}

template<typename T>
inline void p(queue <T> q) {
    queue <T> copy(q);
    while (!copy.empty()) {
        p(copy.front());
        copy.pop();
    }
    cout << nl;
}

template<typename T>
inline void p(stack <T> s) {
    stack <T> copy(s);
    while (!copy.empty()) {
        p(copy.top());
        copy.pop();
    }
    cout << nl;
}

inline void solve() {
    int n;
    cin >> n;
    read(n);
    vi pre(n);
    pre[0] = arr[0];
    forloop(1, n)pre[i] = pre[i - 1] + arr[i];
    if (pre.back() % 3 != 0) {
        pnl(-1);
        return;
    }
    int tot = pre.back();
    auto it = lower_bound(all(pre), tot / 3);
    if (*it * 3 != tot) {
        pnl(-1);
        return;
    }
    auto it2 = lower_bound(all(pre), tot / 3 * 2);
    if (*it2 * 3 / 2 != tot) {
        pnl(-1);
        return;
    }
    cout << it - pre.begin() + 1 << ' ' << it2 - pre.begin() + 1;
}

int main() {
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}