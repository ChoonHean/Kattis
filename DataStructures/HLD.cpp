// From CP4 (Steven Halim, Felix Halim, Suhendry Effendy) (with my own edits)
// https://github.com/stevenhalim/cpbook-code

#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
const int inf = 1e9;

//struct LCA {
//    int n;
//    vpii A, st;
//
//    inline int l(int p) { return p << 1; }
//
//    inline int r(int p) { return (p << 1) + 1; }
//
//    inline pii conquer(pii a, pii b) {
//        if (a.first < b.first)return a;
//        else return b;
//    }
//
//    void build(int p, int L, int R) {
//        if (L == R)
//            st[p] = A[L];
//        else {
//            int m = (L + R) / 2;
//            build(l(p), L, m);
//            build(r(p), m + 1, R);
//            st[p] = conquer(st[l(p)], st[r(p)]);
//        }
//    }
//
//    pii RMQ(int p, int L, int R, int i, int j) {
//        if (i > j) return {inf, inf};
//        if ((L >= i) && (R <= j)) return st[p];
//        int m = (L + R) / 2;
//        return conquer(RMQ(l(p), L, m, i, min(m, j)),
//                       RMQ(r(p), m + 1, R, max(i, m + 1), j));
//    }
//
//    LCA(int sz) : n(sz), A(n) {
//        int mx = (1 << (33 - __builtin_clz(n - 1))) + 1;
//        st.resize(mx);
//    }
//
//    LCA(const vpii &initialA) : LCA((int) initialA.size()) {
//        A = initialA;
//        build(1, 0, n - 1);
//    }
//
//    inline int query(int i, int j) {
//        if (i > j)swap(i, j);
//        return RMQ(1, 0, n - 1, i, j).second;
//    }
//};

struct LCA {                              // OOP style
    vi P2, L2;
    vpii A;
    vector<vi> SpT;                                // the Sparse Table
    LCA() {}                               // default constructor

    LCA(vpii &initialA) {                    // pre-processing routine
        A = initialA;
        int n = (int) A.size();
        int L2_n = (int) log2(n) + 1;
        P2.assign(L2_n + 1, 0);
        L2.assign((1 << L2_n) + 1, 0);
        for (int i = 0; i <= L2_n; ++i) {
            P2[i] = (1 << i);                            // to speed up 2^i
            L2[(1 << i)] = i;                            // to speed up log_2(i)
        }
        for (int i = 2; i < P2[L2_n]; ++i)
            if (L2[i] == 0)
                L2[i] = L2[i - 1];                         // to fill in the blanks

        // the initialization phase
        SpT = vector<vi>(L2[n] + 1, vi(n));
        for (int j = 0; j < n; ++j)
            SpT[0][j] = j;                             // RMQ of sub array [j..j]

        // the two nested loops below have overall time complexity = O(n log n)
        for (int i = 1; P2[i] <= n; ++i)             // for all i s.t. 2^i <= n
            for (int j = 0; j + P2[i] - 1 < n; ++j) {      // for all valid j
                int x = SpT[i - 1][j];                     // [j..j+2^(i-1)-1]
                int y = SpT[i - 1][j + P2[i - 1]];             // [j+2^(i-1)..j+2^i-1]
                SpT[i][j] = A[x] <= A[y] ? x : y;
            }
    }

    int query(int i, int j) {
        int k = L2[j - i + 1];                           // 2^k <= (j-i+1)
        int x = SpT[k][i];                           // covers [i..i+2^k-1]
        int y = SpT[k][j - P2[k] + 1];                   // covers [j-2^k+1..j]
        return A[x] <= A[y] ? A[x].second : A[y].second;
    }
};
int main() {
    int n = 0;
    vi par(n), heavy(n), group(n), pos(n);
    vector<vpii> adj(n);
    auto dfs = [&](auto &self, int i) -> int {
        int size = 1, mx = 0;
        for (const auto &[j, w]: adj[i]) {
            if (j == par[i])continue;
            par[j] = i;
            int child = self(self, j);
            if (child > mx) {
                heavy[i] = j;
                mx = child;
            }
            size += child;
        }
        return size;
    };

    auto decompose = [&](auto &self, int i, int p) -> void {
        group[i] = p;
        for (const auto &[j, w]: adj[i]) {
            if (j == par[i])continue;
            if (j == heavy[i]) {
                pos[j] = pos[i] + 1;
                self(self, j, p);
            } else self(self, j, j);
        }
    };

    vi first(n);
    vpii order(n << 1);
    int idx = 0;
    auto processlca = [&](auto &self, int i, int d) -> void {
        first[i] = idx;
        order[idx++] = {d, i};
        for (const auto &[j, w]: adj[i]) {
            if (j == par[i])continue;
            self(self, j, d + 1);
            order[idx++] = {d, i};
        }
    };
    dfs(dfs, 0);
    decompose(decompose, 0, 0);
    processlca(processlca, 0, 0);
    LCA lca(order);
}