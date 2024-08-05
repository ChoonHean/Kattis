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

void solve() {
    int n;
    cin >> n;
    unordered_set<string> words;
    string s, curr;
    range(0, n) {
        cin >> s;
        words.insert(s);
    }
    getline(cin, s);
    for (int _ = 0; _ < 3; _++) {
        getline(cin, s);
        vector<set<int>> dp(sz(s));
        curr = "";
        for (int i = 0; i < min(7, sz(s)); i++) {
            if (s[i] == ' ')break;
            curr += s[i];
            if (words.contains(curr))dp[i].insert(1);
        }
        for (int i = 0; i < sz(s) - 1; i++) {
            if (s[i] == ' ')dp[i] = dp[i - 1];
            if (dp[i].empty())continue;
            curr = "";
            for (int j = i + 1; j < min(i + 8, sz(s)); j++) {
                if (s[j] == ' ')break;
                curr += s[j];
                if (words.contains(curr)) {
                    for (int k: dp[i])dp[j].insert(k + 1);
                }
            }
        }
        if (_ & 1) {
            if (!dp.back().contains(7)) {
                cout << "come back next year";
                return;
            }
        } else {
            if (!dp.back().contains(5)) {
                cout << "come back next year";
                return;
            }
        }
    }
    cout << "haiku";
}

int main() {
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}