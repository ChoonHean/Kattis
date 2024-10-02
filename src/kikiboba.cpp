#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int b=0,k=0;
    for(char c:s){
        if(c=='b')b++;
        else if(c=='k')k++;
    }
    if(b+k==0)cout<<"none";
    else if(b==k)cout<<"boki";
    else if(b>k)cout<<"boba";
    else cout<<"kiki";
    return 0;
}