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
    ll n, k;
    double a, b;
    cin >> n >> k >> a >> b;
    if (floor(n * b / a - n) <= 0) {
        cout << -1 << endl;
        return;
    }
    int res = 0;
    while (k > 0) {
        double shift = floor(n * b / a - n);
        int next = ceil(a * (shift + 1) / (b - a));
        int tonext = next - n;
        //cout<<n<<' '<<k<<' '<<shift<<' '<<next<<endl;
        if (tonext > k) {
            res += ceil(k / shift);
            break;
        }
        int runs = ceil(tonext / shift);
        shift *= runs;
        res += runs;
        n += shift;
        k -= shift;
    }
    cout << res << endl;
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}