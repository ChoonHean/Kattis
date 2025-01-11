// From CP4 (Steven Halim, Felix Halim, Suhendry Effendy) (with my own edits)
// https://github.com/stevenhalim/cpbook-code

#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
const int inf = 1e9;

struct LCA {
    int n;
    vpii A, st;

    inline int l(int p) { return p << 1; }

    inline int r(int p) { return (p << 1) + 1; }

    inline pii conquer(pii a, pii b) {
        if (a.first < b.first)return a;
        else return b;
    }

    void build(int p, int L, int R) {
        if (L == R)
            st[p] = A[L];
        else {
            int m = (L + R) / 2;
            build(l(p), L, m);
            build(r(p), m + 1, R);
            st[p] = conquer(st[l(p)], st[r(p)]);
        }
    }

    pii RMQ(int p, int L, int R, int i, int j) {
        if (i > j) return {inf, inf};
        if ((L >= i) && (R <= j)) return st[p];
        int m = (L + R) / 2;
        return conquer(RMQ(l(p), L, m, i, min(m, j)),
                       RMQ(r(p), m + 1, R, max(i, m + 1), j));
    }

    LCA(int sz) : n(sz), A(n) {
        int mx = (1 << (33 - __builtin_clz(n - 1))) + 1;
        st.resize(mx);
    }

    LCA(const vpii &initialA) : LCA((int) initialA.size()) {
        A = initialA;
        build(1, 0, n - 1);
    }

    inline int query(int i, int j) {
        if (i > j)swap(i, j);
        return RMQ(1, 0, n - 1, i, j).second;
    }
};


int main() {
    int n = 0;
    vi par(n), heavy(n), group(n), pos(n);
    vector<vpii> adj(n);
    auto dfs = [&](auto &self, int i) -> int {
        int size = 1, mx = 0;
        for (auto &[j, w]: adj[i]) {
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
        for (auto &[j, w]: adj[i]) {
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
        for (auto &[j, w]: adj[i]) {
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