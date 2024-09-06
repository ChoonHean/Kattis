#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pdd> vpdd;
const int inf = 1e9;
const int mod = 1e9 + 7;
#define all(a) a.begin(),a.end()
#define read(n) vi arr(n);for(int i=0;i<n;i++)cin>>arr[i]
#define readarr(n, arr) for(int i=0;i<n;i++)cin>>arr[i]
#define rep(a, n) for(int i=a;i<n;i++)
#define nl "\n"
#define sz(v) ((int)v.size())
#define PQ priority_queue
#define hashmap unordered_map
#define hashset unordered_set
#define pb push_back
#define clz(i) __builtin_clz(i)
#define ctz(i) __builtin_ctz(i)
#define popcount(i) __builtin_popcount(i)
#define LSOne(i) (i&-i)

template<typename T>
inline void pr(T t) { cout << t << ' '; }

template<typename T>
inline void pnl(T t) {
    pr(t);
    cout << nl;
}

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
    for (auto t: m)pr(t);
    cout << nl;
}

template<typename T, typename U>
inline void pr(unordered_map<T, U> m) {
    for (auto t: m)pr(t);
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

vi arr(4096);

inline void solve() {
    int n;
    cin >> n;
    pnl(arr[n]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    bitset<4096> visited;
    int n = 4095;
    visited[0] = 1;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        int val = arr[curr];
        rep(1, 16) {
            int next = curr | i;
            if (!visited[next]) {
                visited[next] = 1;
                arr[next] = val + 1;
                q.push(next);
            }
        }
        rep(1, 8) {
            int next = (curr << i) & n;
            if (!visited[next]) {
                visited[next] = 1;
                arr[next] = val + 1;
                q.push(next);
            }
        }
        int temp = (curr << 12) | curr;
        rep(1, 8) {
            int next = (temp >> i) & n;
            if (!visited[next]) {
                visited[next] = 1;
                arr[next] = val + 1;
                q.push(next);
            }
        }
        int next = (curr + 1) & n;
        if (!visited[next]) {
            visited[next] = 1;
            arr[next] = val + 1;
            q.push(next);
        }
        next = curr ^ n;
        if (!visited[next]) {
            visited[next] = 1;
            arr[next] = val + 1;
            q.push(next);
        }
        rep(1, 8) {
            next = curr + ((curr << i) & n) & n;
            if (!visited[next]) {
                visited[next] = 1;
                arr[next] = val + 1;
                q.push(next);
            }
        }
    }
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}