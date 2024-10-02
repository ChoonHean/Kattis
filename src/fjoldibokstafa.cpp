#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int res=0;
    for(char c:s)if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))res++;
    cout<<res;
    return 0;
}