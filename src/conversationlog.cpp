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
#define forloop(a, n) for(int i=a;i<n;i++)
#define nl "\n"

template<typename T>
inline void print(T it) {
    for (auto i = it.begin(); i != it.end(); i++) {
        cout << *i << " ";
    }
    cout << nl;
}

template<typename T>
inline void print_p(T v) {
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << "(" << (*it).first << "," << (*it).second << ") ";
    }
    cout << nl;
}

inline void solve() {
    int n;
    cin >> n;
    unordered_set<string> users;
    unordered_map<string, int> cnts;
    unordered_map<string, unordered_set<string>> usages;
    string user, words, word;
    while (n--) {
        cin >> user;
        getline(cin, words);
        istringstream iss(words);
        users.insert(user);
        while (iss >> word) {
            cnts[word]++;
            usages[word].insert(user);
        }
    }
    vector<pair<int, string>> arr;
    for (auto it: cnts)arr.push_back(pair(it.second, it.first));
    sort(all(arr), [](pair<int, string> a, pair<int, string> b) {
        if (a.first == b.first)return a.second < b.second;
        return a.first > b.first;
    });
    int num = users.size();
    bool clear = true;
    for (auto it = arr.begin(); it != arr.end(); it++) {
        if (usages[it->second].size() == num) {
            cout << it->second << nl;
            clear = false;
        }
    }
    if (clear)cout << "ALL CLEAR";
}

int main() {
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}