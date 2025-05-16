#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef unsigned int uint;
typedef unsigned long long ull;
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
typedef tuple<int, int, int> ti;
typedef vector<ti> vti;
typedef pair<double, double> pdd;
typedef pair<double, int> pdi;
typedef pair<int, double> pid;
typedef vector<pid> vpid;
typedef vector<vpid> vvpid;
typedef pair<string, int> psi;
typedef pair<int, ll> pil;
typedef vector<pil> vpil;
typedef vector<vpil> vvpil;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<vvpii> vvvpii;
typedef vector<pll> vpll;
typedef vector<pdd> vpdd;
typedef tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>
        ordered_set;
const int inf = 1e9;
const ll llinf = 4e18;
const int mod = 1e9 + 7;
const double eps = 1e-9;
#define all(a) a.begin(),a.end()
#define read(n) vi a(n);for(int&_:a)cin>>_
#define reada(arr) for(auto&_:arr)cin>>_
#define readpair(arr) for(auto&[_,__]:arr)cin>>_>>__
#define readtup(arr) for(auto&[_,__,___]:arr)cin>>_>>__>>___
#define read2d(arr) for(auto&_:arr)reada(_)
#define rep(i, a, n) for(int i=a;i<n;++i)
#define repr(i, a, n) for(int i=a;i>=n;--i)
#define nl "\n"
#define sz(v) ((int)v.size())
#define PQ priority_queue
#define hmap unordered_map
#define hset unordered_set
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define lsb(i) (i&-i)
mt19937_64 rnd(time(0));

template<typename T>
inline bool chmin(T &a, T &b) {
    if (a > b) {
        swap(a, b);
        return true;
    } else return false;
}

template<typename T>
inline bool chmax(T &a, T &b) {
    if (a < b) {
        swap(a, b);
        return true;
    } else return false;
}

template<typename T>
inline T ceildiv(T a, T b) {
    return (a + b - 1) / b;
}

inline void YN(const bool &b) {
    cout << (b ? "YES" : "NO") << nl;
}

template<typename T>
inline void pr(const T &t) { cout << t << ' '; }

template<typename T>
inline void pr(const vector<T> &t);

template<typename T, typename U>
inline void pr(const pair<T, U> &pa) {
    cout << '(';
    pr(pa.first);
    cout << ',';
    pr(pa.second);
    cout << ") ";
}

template<typename... Args>
inline void pr(const tuple<Args...> &tup) {
    apply([](const auto &... args) {
        pr('[');
        (pr(args), ...);
        pr(']');
    }, tup);
}

template<typename T>
inline void pr(const vector<T> &v) {
    for (const auto &i: v) pr(i);
    cout << nl;
}

template<typename T>
inline void pr(const set<T> &s) {
    for (const auto &t: s)pr(t);
    cout << nl;
}

template<typename T>
inline void pr(const multiset<T> &s) {
    for (const auto &t: s)pr(t);
    cout << nl;
}

template<typename T>
inline void pr(const ordered_set &s) {
    for (const auto &t: s)pr(t);
    cout << nl;
}

template<typename T, typename H>
inline void pr(const unordered_set<T, H> &s) {
    for (const auto &t: s)pr(t);
    cout << nl;
}

template<typename T, typename U, typename H>
inline void pr(const map<T, U, H> &m) {
    for (const auto &[t, u]: m) {
        cout << '(';
        pr(t);
        pr('-');
        pr(u);
        pr(')');
    }
    cout << nl;
}

template<typename T, typename U, typename H>
inline void pr(const unordered_map<T, U, H> &m) {
    for (const auto &[t, u]: m) {
        cout << '(';
        pr(t);
        pr('-');
        pr(u);
        pr(')');
    }
    cout << nl;
}

template<typename T>
inline void pr(const queue<T> &q1) {
    queue<T> copy(q1);
    while (!copy.empty()) {
        pr(copy.front());
        copy.pop();
    }
    cout << nl;
}

template<typename T>
inline void pr(const stack<T> &s) {
    stack<T> copy(s);
    while (!copy.empty()) {
        pr(copy.top());
        copy.pop();
    }
    cout << nl;
}

template<typename T>
inline void pr(const deque<T> &q1) {
    deque<T> copy(q1);
    while (!copy.empty()) {
        pr(copy.top());
        copy.pop();
    }
    cout << nl;
}

template<typename T>
inline void pr(const PQ<T> &pq1) {
    auto copy(pq1);
    vector<T> arr;
    while (!copy.empty()) {
        arr.pb(copy.top());
        copy.pop();
    }
    pr(arr);
    cout << nl;
}

template<typename T, typename C>
inline void pr(const PQ<T, vector<T>, C> &pq1) {
    auto copy(pq1);
    vector<T> arr;
    while (!copy.empty()) {
        arr.pb(copy.top());
        copy.pop();
    }
    pr(arr);
    cout << nl;
}

template<typename T>
inline void pnl(const T &t) {
    pr(t);
    cout << nl;
}

template<typename... Args>
void pr(const Args &... args) {
    (pr(args), ...);
    cout << nl;
}

struct TwoSat {
    int N;
    vector<vi> gr;
    vi values; // 0 = false, 1 = true

    TwoSat(int n = 0) : N(n), gr(2 * n) {}

    int addVar() { // (optional)
        gr.emplace_back();
        gr.emplace_back();
        return N++;
    }

    void either(int f, int j) {
        f = max(2 * f, -1 - 2 * f);
        j = max(2 * j, -1 - 2 * j);
        gr[f].push_back(j ^ 1);
        gr[j].push_back(f ^ 1);
    }

    void setValue(int x) { either(x, x); }

    void atMostOne(const vi &li) { // (optional)
        int cur = ~li[0];
        rep(i, 2, sz(li)) {
            int next = addVar();
            either(cur, ~li[i]);
            either(cur, next);
            either(~li[i], next);
            cur = ~next;
        }
        either(cur, ~li[1]);
    }

    void equal(int f, int j) {
        either(~f, j);
        either(f, ~j);
    }

    void exactlyOne(int f, int j) {
        either(f, j);
        either(~f, ~j);
    }

    vi val, comp, z;
    int time = 0;

    int dfs(int i) {
        int low = val[i] = ++time, x;
        z.push_back(i);
        for (int e: gr[i])
            if (!comp[e])
                low = min(low, val[e] ?: dfs(e));
        if (low == val[i])
            do {
                x = z.back();
                z.pop_back();
                comp[x] = low;
                if (values[x >> 1] == -1)
                    values[x >> 1] = x & 1;
            } while (x != i);
        return val[i] = low;
    }

    bool solve() {
        values.assign(N, -1);
        val.assign(2 * N, 0);
        comp = val;
        rep(i, 0, 2 * N) if (!comp[i]) dfs(i);
        rep(i, 0, N) if (comp[2 * i] == comp[2 * i + 1]) return 0;
        return 1;
    }
};

bool run = true;
array<vi, 10000> adj;
array<char, 4> chars = {'A', 'G', 'T', 'C'};

inline void solve() {
    int n, t;
    string s, st;
    cin >> n >> t >> s;
    if (!n) {
        run = false;
        return;
    }
    rep(i, 0, n)adj[i].clear();
    rep(i, 0, t) {
        cin >> st;
        int k = stoi(st.substr(0, sz(st) - 1));
        read(k);
        rep(j, 0, k / 2)adj[a[j]].pb(a[k - j - 1]), adj[a[k - j - 1]].pb(a[j]);
    }
    vb vis(n);
    TwoSat ts(n);
    rep(i, 0, n)
        if (!vis[i]) {
            vis[i] = 1;
            vi id;
            bitset<4> ch;
            queue<int> q({i});
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                id.pb(u);
                if (s[u] == 'A')ch[0] = 1;
                else if (s[u] == 'G')ch[1] = 1;
                else if (s[u] == 'T')ch[2] = 1;
                else ch[3] = 1;
                for (const int &v: adj[u])if (!vis[v])vis[v] = 1, q.push(v);
            }
            int c = ch.count();
            if (c == 4) {
                YN(0);
                return;
            } else if (c == 1)continue;
            else if (c == 3) {
                int clear = 2;
                if (!ch[1])clear = 3;
                if (!ch[2])clear = 0;
                if (!ch[3])clear = 1;
                for (const int &x: id)if (s[x] != chars[clear])ts.setValue(x);
            } else if ((ch[0] && ch[2]) || ch[1] && ch[3]) {
                for (const int &x: id)ts.setValue(x);
            } else {
                vi a{id[0]}, b;
                rep(j, 1, sz(id)) {
                    if (s[id[j]] == s[a[0]])a.pb(id[j]);
                    else b.pb(id[j]);
                }
                rep(j, 1, sz(a)) ts.equal(a[0], a[j]);
                rep(j, 1, sz(b)) ts.equal(b[0], b[j]);
                ts.exactlyOne(a[0], b[0]);
            }
        }
    rep(i, 1, n)ts.either(~(i - 1), ~i);
    YN(ts.solve());
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(10);
    int cases = 1;
//    cin >> cases;
    while (run)solve();
    return 0;
}