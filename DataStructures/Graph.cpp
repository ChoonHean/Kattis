#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vector<pair<int, int>>> vvpii;
typedef vector<bool> vb;
const int inf = 1e9;
const ll llinf = 4e18;
const int mod = 1e9 + 7;
const double eps = 1e-9;
#define all(a) a.begin(),a.end()
#define rep(i, a, n) for(int i=a;i<n;i++)
#define pb push_back
#define sz(a) ((int)a.size())

template<typename T>
inline vector<T> dijkstra(const vector<vector<pair<int, T>>> &adj, int s) {
    int n = sz(adj);
    vector<T> dist(n, numeric_limits<T>::max());
    dist[s] = T();
    set<pair<T, int>> pq;
    pq.emplace(T(), s);
//    vi p(n, -1);
    while (!pq.empty()) {
        auto [d, u] = *pq.begin();
        pq.erase(pq.begin());
        for (const auto &[v, w]: adj[u]) {
            T next = d + w;
            if (next < dist[v]) {
                pq.erase({dist[v], v});
                pq.emplace(dist[v] = next, v);
//                p[v] = u;
            }
        }
    }
//    return p;
    return dist;
}

struct TwoSat {
    int N;
    vector<vi> gr;
    vi values; // 0 = false, 1 = true

    TwoSat(int n = 0) : N(n), gr(2 * n) {}

    int addVar() { // (optional)
        gr.emplace_back();
        gr.emplace_back();
        return N++;
    }

    void either(int f, int j) {
        f = max(2 * f, -1 - 2 * f);
        j = max(2 * j, -1 - 2 * j);
        gr[f].push_back(j ^ 1);
        gr[j].push_back(f ^ 1);
    }

    void setValue(int x) { either(x, x); }

    void atMostOne(const vi &li) { // (optional)
        int cur = ~li[0];
        rep(i, 2, sz(li)) {
            int next = addVar();
            either(cur, ~li[i]);
            either(cur, next);
            either(~li[i], next);
            cur = ~next;
        }
        either(cur, ~li[1]);
    }

    void equal(int f, int j) {
        either(~f, j);
        either(f, ~j);
    }

    void exactlyOne(int f, int j) {
        either(f, j);
        either(~f, ~j);
    }

    vi val, comp, z;
    int time = 0;

    int dfs(int i) {
        int low = val[i] = ++time, x;
        z.push_back(i);
        for (int e: gr[i])
            if (!comp[e])
                low = min(low, val[e] ?: dfs(e));
        if (low == val[i])
            do {
                x = z.back();
                z.pop_back();
                comp[x] = low;
                if (values[x >> 1] == -1)
                    values[x >> 1] = x & 1;
            } while (x != i);
        return val[i] = low;
    }

    bool solve() {
        values.assign(N, -1);
        val.assign(2 * N, 0);
        comp = val;
        rep(i, 0, 2 * N) if (!comp[i]) dfs(i);
        rep(i, 0, N) if (comp[2 * i] == comp[2 * i + 1]) return 0;
        return 1;
    }
};

template<typename T>
inline T kruskal(vector<tuple<T, int, int>> edges, int n) {
    struct UFDS {
        vi p;

        UFDS(int n) {
            p.resize(n);
            iota(p.begin(), p.end(), 0);
        }

        int find(int n) {
            if (n == p[n])return n;
            return p[n] = find(p[n]);
        }

        inline bool sameset(int x, int y) { return find(x) == find(y); }

        inline void unionset(int x, int y) {
            x = find(x);
            y = find(y);
            p[y] = x;
        }
    };
    UFDS uf(n);
    sort(all(edges));
    T res = T();
//    vpii connections;
    for (const auto &[w, i, j]: edges) {
        if (uf.sameset(i, j))continue;
        uf.unionset(i, j);
        res += w;
//        connections.eb(i, j);
    }
    return res;
}

inline vi toposort(const vvi &adj, vi &deg) {
    int n = sz(deg);
    vi res;
    queue<int> q;
    rep(i, 0, n)if (!deg[i])q.push(i);
    while (!q.empty()) {
        res.pb(q.front());
        for (const auto &j: adj[q.front()])if (!--deg[j])q.push(j);
        q.pop();
    }
    return res;
}

inline vi toposort(const vvpii &adj, vi &deg) {
    int n = sz(deg);
    vi res;
    queue<int> q;
    rep(i, 0, n)if (!deg[i])q.push(i);
    while (!q.empty()) {
        res.pb(q.front());
        for (const auto &[j, d]: adj[q.front()])if (!--deg[j])q.push(j);
        q.pop();
    }
    return res;
}

inline vi kosaraju(const vvi &adj, const vvi &t) {
    int n = sz(adj);
    vb vis(n);
    vi ord, scc(n, -1);
    auto dfs = [&](auto &self, int i, int p) -> void {
        vis[i] = true;
        for (const int &j: adj[i]) {
            if (j == p)continue;
            if (!vis[j])self(self, j, i);
        }
        ord.pb(i);
    };
    auto kos = [&](auto &self, int i, int p) -> void {
        scc[i] = scc[p];
        for (const int &j: t[i]) {
            if (j == p)continue;
            if (scc[j] == -1)self(self, j, i);
        }
    };
    rep(i, 0, n)if (!vis[i])dfs(dfs, i, i);
    int cnt = 0;
    reverse(all(ord));
    for (const int &i: ord)if (scc[i] == -1)scc[i] = cnt++, kos(kos, i, i);
    return scc;
}

