#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vl;

int main() {
    int n,a,b;
    string op;
    cin>>n;
    vector<string> ans;
    for(int i=0;i<n;i++) {
        cin >> a >> op >> b;
        if(op=="+")ans.push_back(to_string(a+b));
        else if (op=="-")ans.push_back(to_string(a-b));
        else ans.push_back(to_string(a*b));
    }
    int longest=0;
    for (auto s: ans)if(s.size()>longest)longest=s.size();
    int col=50/(longest+1);
    int row=ceil((double)n/col);
    for (auto& s:ans)s.insert(0,longest-s.size(),' ');
    int curr=0;
    for (int i=0;i<row-1;i++) {
        for(int j=0;j<col-1;j++) {
            cout<<ans[curr++]<<" ";
        }
        cout<<ans[curr++]<<endl;
    }
    while(curr<n-1){
        cout<<ans[curr++]<<" ";
    }
    cout<<ans[curr]<<endl;
    while(true){
        cin>>n;
        if(!n)break;
        cout<<endl;
        ans.resize(0);
        for(int i=0;i<n;i++) {
            cin >> a >> op >> b;
            if(op=="+")ans.push_back(to_string(a+b));
            else if (op=="-")ans.push_back(to_string(a-b));
            else ans.push_back(to_string(a*b));
        }
        longest=0;
        for (auto s: ans)if(s.size()>longest)longest=s.size();
        col=50/(longest+1);
        row=ceil((double)n/col);
        for (auto& s:ans)s.insert(0,longest-s.size(),' ');
        curr=0;
        for (int i=0;i<row-1;i++) {
            for(int j=0;j<col-1;j++) {
                cout<<ans[curr++]<<" ";
            }
            cout<<ans[curr++]<<endl;
        }
        while(curr<n-1){
            cout<<ans[curr++]<<" ";
        }
        cout<<ans[curr]<<endl;
    }
    return 0;
}
