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
#define nl "\n";

template<typename T>
inline void print(T it) {
    for (auto i = it.begin(); i != it.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
}

template<typename T>
inline void print_p(T v) {
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << "(" << (*it).first << "," << (*it).second << ") ";
    }
    cout << endl;
}

/*struct SegmentTree {                              // OOP style
    int n;                                         // n = (int)A.size()
    vi A, st, lazy;                                // the arrays

    inline int l(int p) { return p << 1; }                 // go to left child
    inline int r(int p) { return (p << 1) + 1; }              // go to right child

    inline int conquer(int a, int b) {
        return a + b;                            // RMQ
    }

    void build(int p, int L, int R) {              // O(n)
        if (L == R)
            st[p] = A[L];                              // base case
        else {
            int m = (L + R) / 2;
            build(l(p), L, m);
            build(r(p), m + 1, R);
            st[p] = conquer(st[l(p)], st[r(p)]);
        }
    }

    inline void propagate(int p, int L, int R) {
        if (lazy[p] == 0) {                         // has a lazy flag
            st[p] = lazy[p];                           // [L..R] has same value
            if (L != R) {                               // not a leaf
                lazy[l(p)] = lazy[p];       // propagate downwards
                lazy[r(p)] = lazy[p];
            } else                                       // L == R, a single index
                A[L] = lazy[p];                          // time to update this
            lazy[p] = -1;                              // erase lazy flag
        }
    }

    int RMQ(int p, int L, int R, int i, int j) {   // O(log n)
        propagate(p, L, R);                          // lazy propagation
        if (i > j) return 0;                        // infeasible
        if ((L >= i) && (R <= j)) return st[p];      // found the segment
        int m = (L + R) / 2;
        return conquer(RMQ(l(p), L, m, i, min(m, j)),
                       RMQ(r(p), m + 1, R, max(i, m + 1), j));
    }

    void update(int p, int L, int R, int i, int j, int val) { // O(log n)
        propagate(p, L, R);                          // lazy propagation
        if (i > j) return;
        if ((L >= i) && (R <= j)) {                  // found the segment
            lazy[p] = val;                             // update this
            propagate(p, L, R);                        // lazy propagation
        } else {
            int m = (L + R) / 2;
            update(l(p), L, m, i, min(m, j), val);
            update(r(p), m + 1, R, max(i, m + 1), j, val);
            st[p] = conquer(st[l(p)], st[r(p)]);
        }
    }

    SegmentTree(int sz) : n(sz), A(n), st(4 * n), lazy(4 * n, -1) {}

    SegmentTree(const vi &initialA) : SegmentTree((int) initialA.size()) {
        A = initialA;
        build(1, 0, n - 1);
    }

    void update(int i, int j, int val) { update(1, 0, n - 1, i, j, val); }

    int RMQ(int i, int j) { return RMQ(1, 0, n - 1, i, j); }
};*/
bitset<30000>visited;
vector<unordered_set<int>>adj;
vector<vi>transpose,sccs;
stack<int>order;
vector<bitset<30000>>cache;
void topo(int i){
    visited.set(i);
    for(int j:adj[i])if(!visited.test(j))topo(j);
    order.push(i);
}
void kosaraju(int i){
    visited.set(i);
    sccs.back().push_back(i);
    for(int j:transpose[i])if(!visited.test(j))kosaraju(j);
}
void breakscc(int i){
    visited.set(i);
    for(int j:adj[i])if(!visited.test(j))breakscc(j);
}
bitset<30000> dfs(int i){
    if(cache[i].test(i))return cache[i];
    cache[i].set(i);
    for(int j:adj[i])cache[i]|=dfs(j);
    return cache[i];
}
inline void solve() {
    int n,x;
    cin>>n;
    vs arr(n);
    unordered_map<string,int>mapper;
    vector<vs>adjs(n);
    adj.resize(n);
    transpose.resize(n);
    cache.resize(n);
    string s1,s2;
    forloop(0,n){
        cin>>s1>>x;
        mapper[s1]=i;
        arr[i]=s1;
        auto& hashset=adjs[i];
        for(int j=0;j<x;j++){
            cin>>s2;
            if(isupper(s2[0]))hashset.push_back(s2);
        }
    }
    forloop(0,n)for(string s:adjs[i])adj[i].insert(mapper[s]);
    forloop(0,n)for(int j:adj[i])transpose[j].push_back(i);
    forloop(0,n)if(!visited.test(i))topo(i);
    visited.reset();
    while(!order.empty()){
        int i=order.top();
        if(!visited.test(i)){
            sccs.push_back(vi());
            kosaraju(i);
        }
        order.pop();
    }
    for(auto v:sccs){
        if(v.size()>1){
            visited.reset();
            breakscc(v[0]);
            for(int i:v){
                adj[i]=unordered_set<int>();
                cache[i]=visited;
            }
        }
    }
    forloop(0,n)cout<<dfs(i).count()<<nl;
}

int main() {
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}