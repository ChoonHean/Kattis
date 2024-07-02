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

string s = "aababbabbabbabbabbab";
int n;
unordered_set<string> hashset;

void h(int i) { //scroll through element in position i
    char c = s[i];
    while (s[i] < 'z') {
        if (hashset.size() == n)return;
        s[i]++;
        if (s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')s[i]++;
        hashset.insert(s);
    }
    s[i] = c;
}

void g(int i) { //scroll through positions i to 20
    for (int j = i; j < 20; j++) {
        if (hashset.size() == n)return;
        if (j % 3 == 0)j++;
        h(j);
    }
}

void f(int i) { //scroll through element in position i
    char c = s[i];
    if (hashset.size() == n)return;
    h(i);
    while (s[i] <= 'z') {
        g(i + 1);
        s[i]++;
        if (s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')s[i]++;
    }
    s[i] = c;
}

inline void solve() {
    cin >> n;
    for (int i = 1; i < 20; i++) {
        if (i % 3 == 0)i++;
        if (hashset.size() == n) {
            for (string ss: hashset)cout << ss << nl;
            return;
        }
        f(i);
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