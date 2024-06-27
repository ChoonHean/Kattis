#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int inf = 1e9;
int mod = 1e9 + 7;
#define all(a) a.begin(),a.end()
#define read(n) vi arr(n);for(int i=0;i<n;i++)cin>>arr[i]
#define readarr(n, arr) for(int i=0;i<n;i++)cin>>arr[i]
#define forloop(a, n) for(int i=a;i<n;i++)

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


string curr;
vc arr;
vector<vi> adj;
vector<bool> visited;

inline bool open(char c) { return c == '{' || c == '[' || c == '('; }

inline bool match(char a, char b) { return a == '(' ? b == ')' : a == '{' ? b == '}' : b == ']'; }

int dfs(int n) {
    visited[n] = true;
    int res = 0;
    if (open(arr[n])) {
        curr.push_back(arr[n]);
        for (int i: adj[n])if (!visited[i])res += dfs(i);
        curr.pop_back();
    } else {
        if (curr.empty())return 0;
        if (match(curr.back(), arr[n])) {
            char c = curr.back();
            curr.pop_back();
            if (curr.empty())res++;
            for (int i: adj[n])if (!visited[i])res += dfs(i);
            curr.push_back(c);
        }
    }
    return res;
}

inline void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    arr.resize(n);
    forloop(0, n)arr[i] = s[i];
    adj.resize(n);
    int u, v;
    int res=0;
    forloop(1, n) {
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    forloop(0, n) {
        visited.assign(n, false);
        res+=dfs(i);
    }
    cout<<res;
}

int main() {
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}