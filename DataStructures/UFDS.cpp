#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

struct UFDS {
    vi p, size;
    int sets;

    UFDS(int n) {
        p.resize(n);
        sets = n;
        iota(p.begin(), p.end(), 0);
        size.assign(n, 1);
    }

    int find(int n) {
        if (n == p[n])return n;
        return p[n] = find(p[n]);
    }

    inline bool sameset(int x, int y) { return find(x) == find(y); }

    inline void unionset(int x, int y) {
        sets--;
        x = find(x);
        y = find(y);
        p[y] = x;
        size[x] += size[y];
    }

    inline int setsize(int n) { return size[find(n)]; }
};