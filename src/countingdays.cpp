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

//inline void solve() {
//    string s1, s2;
//    cin >> s1 >> s2;
//    int a = stoi(s1.substr(0, 2)) * 3600 + stoi(s1.substr(3, 2)) * 60 + stoi(s1.substr(6, 2));
//    int b = stoi(s2.substr(0, 2)) * 3600 + stoi(s2.substr(3, 2)) * 60 + stoi(s2.substr(6, 2));
//    b -= a;
//    if (b < 0)b += 86400;
//    int secs = b % 60;
//    b /= 60;
//    int mins = b % 60;
//    b /= 60;
//    if (secs == 0 && mins == 0 && b == 0)b = 24;
//    printf("%02d:%02d:%02d", b, mins, secs);
//}
//
//int main() {
//    int t = 1;
//    //cin >> t;
//    while (t--) {
//        solve();
//    }
//    return 0;
//}
int elapsed = 3600, pre = 0;

void lookAtClock(int hours, int minutes) {
    int min = hours * 60 + minutes - pre;
    pre = hours * 60 + minutes;
    if (min < 0)min += 3600;
    elapsed += min;
}

int getDay() {
    return elapsed / 3600;
}