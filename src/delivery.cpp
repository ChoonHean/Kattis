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
    int n,x,t;
    double c;
    cin>>n>>c;
    map<int,int>tree;
    forloop(0,n){
        cin>>x>>t;
        tree[x]+=t;
    }
    int res=0;
    for(auto it=tree.begin();it->first<0&&it!=tree.end();){
        int trips=ceil(it->second/c);
        res+=trips*-it->first;
        int remainder=trips*c-it->second;
        if(remainder==0)it++;
        while(remainder>0){
            it++;
            if(it->first>0||it==tree.end())break;
            int dec=min(remainder,it->second);
            it->second-=dec;
            remainder-=dec;
        }
    }
    for(auto it=tree.rbegin();it->first>0&&it!=tree.rend();){
        int trips=ceil(it->second/c);
        res+=trips*it->first;
        int remainder=trips*c-it->second;
        if(remainder==0)it++;
        while(remainder>0){
            it++;
            if(it->first<0||it==tree.rend())break;
            int dec=min(remainder,it->second);
            it->second-=dec;
            remainder-=dec;
        }
    }
    cout<<(res<<1);
}

int main() {
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}