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
const ll llinf = 4e18;
const int mod = 1e9 + 7;
const double EPS = 1e-9;
#define all(a) a.begin(),a.end()
#define read(n) vi arr(n);for(int&_:arr)cin>>_
#define readarr(arr) for(auto&_:arr)cin>>_
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

vs split(string s, char delim) {
    vs res;
    int pos = 0, prev = 0;
    while (true) {
        pos = s.find(delim, prev);
        res.pb(s.substr(prev, pos - prev));
        if (pos == string::npos)break;
        prev = pos + 1;
    }
    return res;
}

inline void solve() {
    int n, cnt = 0, ppl = 0, i, j;
    const int m = 10000;
    string com, name;
    hmap<string, int> group, people;
    vs names;
    vector<bitset<m>> arr(100);
    while (true) {
        cin >> com;
        if (com != "group")break;
        cin >> name >> n;
        i = group[name] = cnt++;
        while (n--) {
            cin >> name;
            if (people.contains(name))j = people[name];
            else j = people[name] = ppl++, names.pb(name);
            arr[i].set(j);
        }
    }
    string x, y;
    vs line{com};
    getline(cin, com);
    com.erase(com.begin());
    for (string &s: split(com, ' '))line.pb(s);
    bitset<m> a, b;
    while (true) {
        stack<bitset<m>> st;
        for (auto it = line.rbegin(); it != line.rend(); it++) {
            if (*it == "union") {
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                st.push(a | b);
            } else if (*it == "intersection") {
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                st.push(a & b);
            } else if (*it == "difference") {
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                st.push((a ^ b) & a);
            } else {
                st.push(arr[group[*it]]);
            }
        }
        vs res;
        bitset<m> bs = st.top();
        rep(k, 0, ppl)if (bs.test(k))res.pb(names[k]);
        sort(all(res));
        pr(res);
        if (!getline(cin, com))break;
        line = split(com, ' ');
    }
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(10);
    int t = 1;
//    cin >> t;
    while (t--) solve();
    return 0;
}