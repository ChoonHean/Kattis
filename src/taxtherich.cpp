#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vl;
class FenwickTree {
public:
    vi ft;
    FenwickTree(int n){ft.assign(n+1,0);}
    int lsb(int i){return i&-i;}
    void update(int pos,int val){for(;pos<(int)ft.size();pos+=lsb(pos))ft[pos]+=val;}
    int query(int pos){
        int ans=0;
        for(;pos;pos-=lsb(pos))ans+=ft[pos];
        return ans;
    }
};
int main() {
    int n,curr,ans=0;
    cin>>n;
    double total=0,avg=0,eps=1e-9;
    FenwickTree ft(10000);
    for(int i=1;i<=n;i++){
        cin>>curr;
        total+=curr;
        ft.update(curr,1);
        avg=total/i;
        //cout<<ft.query(((int)(avg-eps))*2)<<" ";
        if(ft.query(((int)(avg-eps)))*2>i)ans++;
        //cout<<ans<<" ";
    }
    cout<<ans;
    return 0;
}
