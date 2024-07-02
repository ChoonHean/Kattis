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
    int n,k,cost,perf,counter=0;
    ll p;
    cin>>n>>k>>p;
    vector<map<int,int>>trees(k);
    unordered_map<string,int>mapper;
    string s;
    forloop(0,k){
        cin>>s;
        mapper[s]=counter++;
    }
    set<int>unique;
    forloop(0,n){
        cin>>s>>cost>>perf;
        unique.insert(perf);
        auto& tree=trees[mapper[s]];
        auto higher=tree.lower_bound(perf);
        if(higher==tree.end())tree[perf]=cost;
        else if(higher->second>cost)tree[perf]=cost;
    }
    vi arr{-1};
    arr.reserve(unique.size());
    for(int i:unique)arr.push_back(i);
    int lo=0,hi=arr.size()-1;
    ll total=0;
    while(lo<hi){
        int mid=(lo+hi+1)/2;
        int curr=arr[mid];
        total=0;
        for(auto& tree:trees){
            auto a=tree.lower_bound(curr);
            if(a==tree.end()){
                total=1e9+1;
                break;
            }
            total+=a->second;
        }
        if(total>p)hi=mid-1;
        else lo=mid;
    }
    if(lo==0)cout<<"O nei!";
    else cout<<arr[lo];
}

int main() {
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}