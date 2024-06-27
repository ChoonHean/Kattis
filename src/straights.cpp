#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
int main() {
    int n,highest=0;
    cin>>n;
    vi cards;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        highest=max(x,highest);
        cards.push_back(x);
    }
    vi counts(highest);
    for(int i:cards)counts[i-1]++;
    int res=0,curr=0;
    for(int i=0;i<highest;i++){
        if(counts[i]>curr){
            res+=counts[i]-curr;
        }
        curr=counts[i];
    }
    cout<<res;
    return 0;
}
