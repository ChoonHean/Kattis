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
#define range(a, n) for(int i=a;i<n;i++)
#define nl "\n"
#define sz(v) ((int)v.size())
#define pb push_back

template<typename T>
inline void p(T t) { cout << t << ' '; }

template<typename T>
inline void pnl(T t) {
    p(t);
    cout << nl;
}

template<typename T, typename U>
inline void p(pair<T, U> pa) {
    cout << '(';
    p(pa.first);
    cout << ',';
    p(pa.second);
    cout << ") ";
}

template<typename T>
inline void p(vector<T> v) {
    for (auto i: v) p(i);
    cout << nl;
}

template<typename T>
inline void p(vector<vector<T>> v) {
    for (auto row: v) p(row);
}

template<typename T>
inline void p(set<T> s) {
    for (auto t: s)p(t);
    cout << nl;
}

template<typename T>
inline void p(unordered_set<T> s) {
    for (auto t: s)p(t);
    cout << nl;
}

template<typename T, typename U>
inline void p(map<T, U> m) {
    for (auto t: m)p(t);
    cout << nl;
}

template<typename T, typename U>
inline void p(unordered_map<T, U> m) {
    for (auto t: m)p(t);
    cout << nl;
}

template<typename T>
inline void p(queue<T> q) {
    queue<T> copy(q);
    while (!copy.empty()) {
        p(copy.front());
        copy.pop();
    }
    cout << nl;
}

template<typename T>
inline void p(stack<T> s) {
    stack<T> copy(s);
    while (!copy.empty()) {
        p(copy.top());
        copy.pop();
    }
    cout << nl;
}

vector<set<int>> adj;
vi arr;

bool f(int i) {
    if (arr[i]) {
        for (int j: adj[i])if (arr[j] == arr[i])return false;
        return true;
    }
    for (int a = 1; a < 5; a++) {
        bool can = true;
        for (int j: adj[i])if (arr[j] == a)can = false;
        if (!can)continue;
        arr[i] = a;
        for (int j: adj[i]) {
            if (!f(j)) {
                can = false;
                break;
            }
        }
        if (can)return can;
    }
    arr[i] = 0;
    return false;
}

void solve() {
    int n;
    cin >> n;
    string s;
    adj.resize(n);
    arr.resize(n);
    while (cin >> s) {
        int pos = s.find('-');
        int u = stoi(s.substr(0, pos)) - 1;
        int v = stoi(s.substr(pos + 1, sz(s))) - 1;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    f(0);
    range(1, n + 1) {
        p(i);
        pnl(arr[i - 1]);
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