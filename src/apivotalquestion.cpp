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
    int n;
    cin>>n;
    vi arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    vi pre(n),post(n);
    pre[0]=arr[0];
    for(int i=1;i<n;i++){
        pre[i]=max(pre[i-1],arr[i]);
    }
    post[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
        post[i]=min(post[i+1],arr[i]);
    }
    int m=0;
    vi res;
    for(int i=0;i<n;i++){
        if(arr[i]>=pre[i]&&arr[i]<=post[i]){
            m++;
            res.push_back(arr[i]);
        }
    }
    cout<<m<<' ';
    for(int i=0;i<min(m,100);i++)cout<<res[i]<<' ';
}


int main() {
    int t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
