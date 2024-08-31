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

struct info {
    int idx, solved, penalty, time, bonus;

    info() {};

    info(int a, int b, int c, int d, int e) {
        idx = a;
        solved = b;
        penalty = c;
        time = d;
        bonus = e;
    }

    bool operator<(const info other) const {
        if (solved != other.solved)return solved > other.solved;
        if (penalty != other.penalty)return penalty < other.penalty;
        return time < other.time;
    }

    bool operator==(const info other) const {
        return solved == other.solved && penalty == other.penalty && time == other.time;
    }
};

inline void solve() {
    int n, a;
    cin >> n;
    vector<info> arr(n);
    rep(0, n) {
        cin >> arr[i].solved >> arr[i].penalty >> arr[i].time >> arr[i].bonus;
        arr[i].idx = i;
    }
    sort(all(arr));
    vi points = {100, 75, 60, 50, 45, 40, 36, 32, 29, 26, 24, 22, 20, 18, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4,
                 3, 2, 1};
    points.resize(n);
    int startpos = 0;
    vpii res(n);
    rep(1, n) {
        if (arr[i] != arr[i - 1]) {
            double total = 0;
            for (int j = startpos; j < i; j++)total += points[j];
            int add = ceil(total / (i - startpos));
            for (int j = startpos; j < i; j++) {
                res[j].first = arr[j].idx;
                res[j].second = add + arr[j].bonus;
            }
            startpos = i;
        }
    }
    if (arr[n - 1] == arr[n - 2]) {
        double total = 0;
        for (int j = startpos; j < n; j++)total += points[j];
        int add = ceil(total / (n - startpos));
        for (int j = startpos; j < n; j++) {
            res[j].first = arr[j].idx;
            res[j].second = add + arr[j].bonus;
        }
    } else {
        res.back().first = arr.back().idx;
        res.back().second = arr.back().bonus + points[n - 1];
    }
    sort(all(res));
    rep(0, n)pnl(res[i].second);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}