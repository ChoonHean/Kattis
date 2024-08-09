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
typedef vector<pii> vpii;
typedef vector<pll> vpll;
const int inf = 1e9;
const int mod = 1e9 + 7;
#define all(a) a.begin(),a.end()
#define read(n) vi arr(n);for(int i=0;i<n;i++)cin>>arr[i]
#define readarr(n, arr) for(int i=0;i<n;i++)cin>>arr[i]
#define rep(a, n) for(int i=a;i<n;i++)
#define nl "\n"
#define sz(v) ((int)v.size())
#define pb push_back

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

inline void solve() {
    int money, aim, d, p;
    string s;
    cin >> s;
    s.erase(s.find('.'), 1);
    money = stoi(s);
    cin >> s >> d;
    s.erase(s.find('.'), 1);
    aim = stoi(s) * 6;
    if (aim % 10 != 0) {
        pr("IMPOSSIBLE");
        return;
    }
    aim /= 10;
    vs names(d);
    vector<pii> arr(d);
    rep(0, d) {
        cin >> names[i] >> p >> s;
        if (s[2] == '1')arr[i].first = p * 6;
        else if (s[2] == '2')arr[i].first = p * 3;
        else arr[i].first = p * 2;
        cin >> s;
        s.erase(s.find('.'), 1);
        arr[i].second = stoi(s);
    }
    map<int, map<int, unordered_map<int, int>>> dp;
    rep(0, d) {
        int units = arr[i].first, cost = arr[i].second;
        if (!dp[units].contains(cost))dp[units][cost][i] = 1;
        for (auto it = dp.begin(); it != dp.end(); it++) {
            int currunits = it->first;
            auto costmap = it->second;
            int next = currunits + units;
            if (next > aim)break;
            for (auto [currcost, drinks]: costmap) {
                int nextcost = currcost + cost;
                if (nextcost > money)break;
                if (!dp[next].contains(nextcost)) {
                    dp[next][nextcost] = drinks;
                    dp[next][nextcost][i]++;
                }
            }
        }
    }
    for (auto it = dp.lower_bound(aim); it != dp.end(); it++) {
        if (it->second.contains(money)) {
            for (auto [a, b]: it->second[money]) {
                pr(names[a]);
                pnl(b);
            }
            return;
        }
    }
    pr("IMPOSSIBLE");
}

int main() {
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}