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

struct SegmentTree {                              // OOP style
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
        if (lazy[p] != 0) {                         // has a lazy flag
            st[p] += lazy[p];                           // [L..R] has same value
            if (L != R) {                               // not a leaf
                lazy[l(p)] += lazy[p];       // propagate downwards
                lazy[r(p)] += lazy[p];
            } else                                       // L == R, a single index
                A[L] = lazy[p];                          // time to update this
            lazy[p] = 0;                              // erase lazy flag
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
            lazy[p] += val;                             // update this
            propagate(p, L, R);                        // lazy propagation
        } else {
            int m = (L + R) / 2;
            update(l(p), L, m, i, min(m, j), val);
            update(r(p), m + 1, R, max(i, m + 1), j, val);
        }
    }

    SegmentTree(int sz) : n(sz), A(n), st(4 * n), lazy(4 * n) {}

    SegmentTree(const vi &initialA) : SegmentTree((int) initialA.size()) {
        A = initialA;
        build(1, 0, n - 1);
    }

    void update(int i, int j, int val) { update(1, 0, n - 1, i, j, val); }

    int RMQ(int i, int j) { return RMQ(1, 0, n - 1, i, j); }
};

int counts = 0;

void bubbleSort(vi arr, int n) {
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                counts++;
                swapped = true;
            }
        }

        // If no two elements were swapped
        // by inner loop, then break
        if (swapped == false)
            break;
    }
}

inline void solve() {
    int n;
    cin >> n;
    vi arr(n);
    unordered_map<int, int> positions(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        positions[arr[i]] = i;
    }
    ll curr = 0;
    SegmentTree st(n);
    vi sorted(arr);
    sort(sorted.begin(), sorted.end());
    for (int i = 0; i < n - 1; i++) {
        int pos = positions[sorted[i]];
        int add = st.RMQ(pos, pos);
        int loc = pos + add;
        //cout<<sorted[i]<<' '<<loc<<' '<<i<<' ';
        if (loc == i)continue;
        curr += loc - i;
        st.update(0, loc - add, 1);
        //cout<<curr<<' '<<endl;
    }
    cout << curr << ' ';
    //bubbleSort(arr,n);
    //cout<<counts;
}


int main() {
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
