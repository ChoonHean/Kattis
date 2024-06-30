#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int inf = 1e9;
int mod = 1e9 + 7;
#define all(a) a.begin(),a.end()
#define read(n, arr) for(int i=0;i<n;i++)cin>>arr[i]
#define forloop(a, n) for(int i=a;i<n;i++)

template<typename T>
void print(T it) {
    for (auto i = it.begin(); i != it.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
}

template<typename T>
void print_p(T v) {
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << "(" << (*it).first << "," << (*it).second << ") ";
    }
    cout << endl;
}

inline void solve() {
    int n, s;
    cin >> n >> s;
    vi a(n), b(n);
    forloop(0, n)cin >> a[i] >> b[i];
    forloop(0, n) {
        if (a[i] <= s && s <= b[i])s++;
    }
    cout << s;
}


int main() {
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
