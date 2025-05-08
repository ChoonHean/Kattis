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
typedef tree<pii, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>
        ordered_set;
const int inf = 1e8;
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

template<typename T>
inline void pr(const T &t) { cout << t << ' '; }

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

inline void solve() {
    vi a{3, 8, 11, 32, 35, 56, 59, 64, 67, 118, 121, 208, 211, 216, 219, 622, 625, 712, 715, 720, 723, 744, 747, 896,
         899, 986, 989, 2560, 2563, 2778, 2781, 3806, 3809, 3890, 3893, 4198, 4201, 4584, 4587, 5338, 5341, 5458, 5461,
         5962, 5965, 8642, 8645, 12084, 12087, 12772, 12775, 13602, 13605, 14012, 14015, 17336, 17339, 18016, 18019,
         19310, 19313, 20940, 20943, 26374, 26377, 29320, 29323, 38154, 38157, 42662, 42665, 43502, 43505, 45930, 45933,
         49686, 49689, 60066, 60069, 64476, 64479, 72448, 72451, 83956, 83959, 91046, 91049, 93740, 93743, 96310, 96313,
         118766, 118769, 123806, 123809, 143434, 143437, 147712, 147715, 154866, 154869, 170090, 170093, 187820, 187823,
         209752, 209755, 244800, 244803, 273474, 273477, 347428, 347431, 382530, 382533, 402720, 402723, 467274, 467277,
         543812, 543815, 561334, 561337, 580884, 580887, 607694, 607697, 665034, 665037, 686696, 686699, 693306, 693309,
         816300, 816303, 960620, 960623, 960964, 960967, 1024258, 1024261, 1157516, 1157519, 1340720, 1340723, 1377504,
         1377507, 1412330, 1412333, 1454878, 1454881, 1488314, 1488317, 1608896, 1608899, 1907342, 1907345, 1915204,
         1915207, 1953088, 1953091, 2011552, 2011555, 2053088, 2053091, 2218520, 2218523, 2439860, 2439863, 2506800,
         2506803, 2792760, 2792763, 2818000, 2818003, 3058974, 3058977, 3692938, 3692941, 3810186, 3810189, 3850764,
         3850767, 4240946, 4240949, 5380204, 5380207, 5484644, 5484647, 5632196, 5632199, 6136490, 6136493, 6929080,
         6929083, 7019280, 7019283, 7163844, 7163847, 7339412, 7339415, 8299624, 8299627, 9702450, 9702453, 10000910,
         10000913, 11404634, 11404637, 13368688, 13368691, 13509604, 13509607, 13750138, 13750141, 15095790, 15095793,
         16166924, 16166927, 16409144, 16409147, 17105420, 17105423, 17412348, 17412351, 17820008, 17820011, 20007958,
         20007961, 20693774, 20693777, 22045460, 22045463, 23380094, 23380097, 24789334, 24789337, 25126678, 25126681,
         26647980, 26647983, 27683252, 27683255, 27781826, 27781829, 28640628, 28640631, 33645474, 33645477, 36104218,
         36104221, 36190982, 36190985, 36607498, 36607501, 36830424, 36830427, 38880354, 38880357, 40010700, 40010703,
         42600652, 42600655, 46883338, 46883341, 47261042, 47261045, 50441582, 50441585, 50806108, 50806111, 51326550,
         51326553, 63270628, 63270631, 73376298, 73376301, 79246954, 79246957, 85507614, 85507617, 86494788, 86494791,
         87659372, 87659375, 93188572, 93188575, 102490320, 102490323, 111387292, 111387295, 117666362, 117666365,
         125481924, 125481927, 125946452, 125946455, 129257606, 129257609, 131533502, 131533505, 148061544, 148061547,
         154708884, 154708887, 156257698, 156257701, 164235208, 164235211, 174422902, 174422905, 177543326, 177543329,
         200688798, 200688801, 203517204, 203517207, 227993998, 227994001, 235532762, 235532765, 239063820, 239063823,
         241476986, 241476989, 251732672, 251732675, 279478702, 279478705, 281430472, 281430475, 294129388, 294129391,
         300664758, 300664761, 309796952, 309796955, 315713182, 315713185, 343273582, 343273585, 364007276, 364007279,
         367324042, 367324045, 373016576, 373016579, 385477086, 385477089, 405738568, 405738571, 442967366, 442967369,
         480451560, 480451563, 519983304, 519983307, 536597756, 536597759, 629403140, 629403143, 713858034, 713858037,
         739002982, 739002985, 809065744, 809065747, 813583138, 813583141, 822228058, 822228061, 830259270, 830259273,
         834828324, 834828327, 916215504, 916215507, 978364206, 978364209, 1000000005};
    int q, x;
    cin >> q;
    while (q--)cin >> x, pnl(*lb(all(a), x) == x ? "Bob" : "Alice");
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(2);
    int cases = 1;
//    cin >> cases;
    while (cases--) solve();
    return 0;
}