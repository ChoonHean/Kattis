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
    int n,m,k;
    cin>>n>>m>>k;
    vi circle(m),square(k);
    read(n);
    readarr(m,circle);
    readarr(k,square);
    sort(all(arr));
    for(int i=0;i<k;i++)square[i]=floor(sqrt(square[i]*square[i]/2.0));
    vi houses;
    houses.reserve(m+k);
    for(int i:circle)houses.push_back(i);
    for(int i:square)houses.push_back(i);
    sort(all(houses));
    int j=0;
    int res=0;
    forloop(0,n){
        if(houses[j]<arr[i]){
            res++;
            j++;
            if(j>=houses.size())break;
        }
    }
    cout<<res;
}

int main() {
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}