#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,res=0;
    cin>>n>>m;
    string s;
    vector<pair<int,int>>arr;
    for(int i=1;i<=n;i++){
        cin>>s;
        for(int j=0;j<m;j++)if(s[j]=='*')arr.push_back({i,j+1});
    }
    cout<<arr.size()<<endl;
    for(auto[x,y]:arr)cout<<x<<' '<<y<<endl;
    return 0;
}