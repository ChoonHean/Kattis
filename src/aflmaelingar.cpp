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
typedef pair<ll, ll> pll;
int inf = 1e9;
int mod = 1e9 + 7;
#define all(a) a.begin(),a.end()
#define read(n) vi arr(n);for(int i=0;i<n;i++)cin>>arr[i]
#define readarr(n, arr) for(int i=0;i<n;i++)cin>>arr[i]
#define forloop(a, n) for(int i=a;i<n;i++)

template<typename T>
inline void print(T it) {
    for (auto i = it.begin(); i != it.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
}

template<typename T>
inline void print_p(T v) {
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << "(" << (*it).first << "," << (*it).second << ") ";
    }
    cout << endl;
}


inline void solve() {
    int n = 300, k, q;
    cin >> k >> q;
    vi arr(n), percent(n);
    if (k == 2) {
        percent[0] = 1;
        print(percent);
        cin >> arr[0];
        forloop(1, n) {
            percent[i - 1] = 0;
            percent[i] = 1;
            print(percent);
            cin >> arr[i];
        }
    } else if (k == 4) {
        percent[0] = 100;
        percent[1] = 1;
        print(percent);
        int x;
        cin >> x;
        arr[0] = x / 100;
        arr[1] = x % 100;
        for (int i = 2; i < n; i += 2) {
            percent[i - 2] = 0;
            percent[i - 1] = 0;
            percent[i] = 100;
            percent[i + 1] = 1;
            print(percent);
            cin >> x;
            arr[i] = x / 100;
            arr[i + 1] = x % 100;
        }
    } else {
        percent[0] = 1;
        percent[1] = 100;
        print(percent);
        int x, a, b, c;
        cin >> x;
        a = x % 100;
        b = x / 100;
        percent[0] = 0;
        percent[1] = 10;
        percent[2] = 1;
        print(percent);
        cin >> x;
        c = x % 100 - b * 10;
        if (c < 0) {
            c += 100;
            b += (x / 100 - 1) * 10;
        } else {
            b += x / 100 * 10;
        }
        if (b < 0)b += 100;
        arr[0] = a;
        arr[1] = b;
        arr[2] = c;
        for (int i = 3; i < n; i += 3) {
            percent[i - 2] = 0;
            percent[i - 1] = 0;
            percent[i] = 1;
            percent[i + 1] = 100;
            print(percent);
            cin >> x;
            a = x % 100;
            b = x / 100;
            percent[i] = 0;
            percent[i + 1] = 10;
            percent[i + 2] = 1;
            print(percent);
            cin >> x;
            c = x % 100 - b * 10;
            if (c < 0) {
                c += 100;
                b += (x / 100 - 1) * 10;
            } else {
                b += x / 100 * 10;
            }
            if (b < 0)b += 100;
            arr[i] = a;
            arr[i + 1] = b;
            arr[i + 2] = c;
        }
    }
    print(arr);
}

int main() {
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}