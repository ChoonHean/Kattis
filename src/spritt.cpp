#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x,tot=0,a;
    cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>a;
        tot+=a;
    }
    tot<=x?cout<<"Jebb":cout<<"Neibb";
    return 0;
}