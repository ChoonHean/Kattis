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
    int n,m,k;
    cin>>n>>m>>k;
    string s;
    vi arr(n);
    ll tix=0;
    forloop(0,n){
        cin>>s>>arr[i];
        tix+=arr[i];
    }
    sort(all(arr));
    auto curr=arr.begin();
    ll pass=0;
    int pass_ans=0;
    ll res=m*tix;
    while(curr<arr.end()){
        int inc=*curr-pass;
        pass=*curr;
        tix-=inc*(arr.end()-curr);
        ll total=tix*m+pass*k;
        if(total<res){
            res=total;
            pass_ans=pass;
        }
        curr=upper_bound(curr,arr.end(),pass);
    }
    cout<<pass_ans<<' '<<res;
}

int main() {
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}