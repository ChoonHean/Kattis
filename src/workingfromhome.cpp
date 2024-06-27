#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vl;

int main() {
    int m,n,curr,res=0;
    double p,change;
    cin>>m>>p>>n;
    p/=100;
    for(int i=0;i<n;i++){
        cin>>curr;
        if(curr>=m+change){
            res++;
        }
        change=(ceil(m+change)-curr)*p;
    }
    cout<<res;
    return 0;
}
