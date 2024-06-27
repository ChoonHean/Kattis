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

inline void solve() {
    int n=300,k,q;
    cin>>k>>q;
    vi arr(n),percent(n);
    if(k==2){
        percent[0]=1;
        print(percent);
        cin>>arr[0];
        forloop(1,n){
            percent[i-1]=0;
            percent[i]=1;
            print(percent);
            cin>>arr[i];
        }
    }else if(k==4){
        percent[0]=100;
        percent[1]=1;
        print(percent);
        int x;
        cin>>x;
        arr[0]=x/100;
        arr[1]=x%100;
        for(int i=2;i<n;i+=2){
            percent[i-2]=0;
            percent[i-1]=0;
            percent[i]=100;
            percent[i+1]=1;
            print(percent);
            cin>>x;
            arr[i]=x/100;
            arr[i+1]=x%100;
        }
    }else{
        percent[0]=1;
        percent[1]=100;
        print(percent);
        int x,a,b,c;
        cin>>x;
        a=x%100;
        b=x/100;
        percent[0]=0;
        percent[1]=10;
        percent[2]=1;
        print(percent);
        cin>>x;
        c=x%100-b*10;
        if(c<0){
            c+=100;
            b+=(x/100-1)*10;
        }else{
            b+=x/100*10;
        }
        if(b<0)b+=100;
        arr[0]=a;
        arr[1]=b;
        arr[2]=c;
        for(int i=3;i<n;i+=3){
            percent[i-2]=0;
            percent[i-1]=0;
            percent[i]=1;
            percent[i+1]=100;
            print(percent);
            cin>>x;
            a=x%100;
            b=x/100;
            percent[i]=0;
            percent[i+1]=10;
            percent[i+2]=1;
            print(percent);
            cin>>x;
            c=x%100-b*10;
            if(c<0){
                c+=100;
                b+=(x/100-1)*10;
            }else{
                b+=x/100*10;
            }
            if(b<0)b+=100;
            arr[i]=a;
            arr[i+1]=b;
            arr[i+2]=c;
        }
    }
    print(arr);
}

int main() {
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}