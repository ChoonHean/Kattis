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
    int n,l;
    cin>>n>>l;
    n++;
    vi adj(n),req(n),curr(n),indeg(n);
    for(int u=1;u<n;u++){
        cin>>adj[u]>>req[u]>>curr[u];
        indeg[adj[u]]++;
    }
    int res=l;
    vi topo;
    queue<int> q;
    for(int i=0;i<n;i++)if(indeg[i]==0)q.push(i);
    while(!q.empty()){
        topo.push_back(q.front());
        int next=adj[q.front()];
        indeg[next]--;
        if(indeg[next]==0)q.push(next);
        q.pop();
    }
    vi dp(n);
    dp[0]=l;
    for(auto it=topo.rbegin();it!=topo.rend();it++){
        int i=*it;
        dp[i]=max(req[i],dp[adj[i]])-curr[i];
        res=min(res,dp[i]);
    }
    cout<<res;
}


int main() {
    int t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
