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
int inf = 1e9;
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
    int n;
    cin>>n;
    vs arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    unordered_map<string,int> table;
    int mn=INT_MAX;
    for(int i=0;i<n;i++){
        if(table.contains(arr[i])){
            mn=min(mn,i-table[arr[i]]);
        }
        table[arr[i]]=i;
    }
    mn==INT_MAX?cout<<0:cout<<n-mn;
}


int main() {
    int t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
