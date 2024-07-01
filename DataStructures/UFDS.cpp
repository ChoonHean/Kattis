#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

struct UFDS {
    vi p;
    int sets;

    UFDS(int n) {
        p.reserve(n + 1);
        sets = n + 1;
        for (int i = 0; i <= n; i++)p.push_back(i);
    }

    int find(int n) {
        if (n == p[n])return n;
        return p[n] = find(p[n]);
    }

    inline bool sameset(int x, int y) { return find(x) == find(y); }

    inline void unionset(int x, int y) {
        sets--;
        p[find(x)] = p[find(y)];
    }
};