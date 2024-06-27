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
#define nl "\n";

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


bitset<30000>visited;
vector<unordered_set<int>>adj;
vector<vi>transpose,sccs;
stack<int>order;
vector<bitset<30000>>cache;
void topo(int i){
    visited.set(i);
    for(int j:adj[i])if(!visited.test(j))topo(j);
    order.push(i);
}
void kosaraju(int i){
    visited.set(i);
    sccs.back().push_back(i);
    for(int j:transpose[i])if(!visited.test(j))kosaraju(j);
}
void breakscc(int i){
    visited.set(i);
    for(int j:adj[i])if(!visited.test(j))breakscc(j);
}
bitset<30000> dfs(int i){
    if(cache[i].test(i))return cache[i];
    cache[i].set(i);
    for(int j:adj[i])cache[i]|=dfs(j);
    return cache[i];
}
inline void solve() {
    int n,x;
    cin>>n;
    vs arr(n);
    unordered_map<string,int>mapper;
    vector<vs>adjs(n);
    adj.resize(n);
    transpose.resize(n);
    cache.resize(n);
    string s1,s2;
    forloop(0,n){
        cin>>s1>>x;
        mapper[s1]=i;
        arr[i]=s1;
        auto& hashset=adjs[i];
        for(int j=0;j<x;j++){
            cin>>s2;
            if(isupper(s2[0]))hashset.push_back(s2);
        }
    }
    forloop(0,n)for(string s:adjs[i])adj[i].insert(mapper[s]);
    forloop(0,n)for(int j:adj[i])transpose[j].push_back(i);
    forloop(0,n)if(!visited.test(i))topo(i);
    visited.reset();
    while(!order.empty()){
        int i=order.top();
        if(!visited.test(i)){
            sccs.push_back(vi());
            kosaraju(i);
        }
        order.pop();
    }
    for(auto v:sccs){
        if(v.size()>1){
            visited.reset();
            breakscc(v[0]);
            for(int i:v){
                adj[i]=unordered_set<int>();
                cache[i]=visited;
            }
        }
    }
    forloop(0,n)cout<<dfs(i).count()<<nl;
}

int main() {
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}