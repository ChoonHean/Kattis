#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef pair<int, int> pii;
ll inf = LLONG_MAX;

template<typename T>
void print(T it) {
    for (auto i = it.begin(); i != it.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
}

struct UFDS {
    vi p;

    UFDS(int n) {
        p.resize(n + 1);
        for (int i = 1; i <= n; i++) p[i] = i;
    }

    int find(int n) {
        if (n == p[n]) return n;
        p[n] = find(p[n]);
        return p[n];
    }

    void unionSet(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        p[y] = x;
    }
};

vi dist, adj;

int dfs(int n) {
    if (n == -1)return 0;
    if (dist[n] != INT_MAX)return dist[n];
    dist[n] = 1 + dfs(adj[n]);
    return dist[n];
}

int main() {
    int n, q;
    cin >> n;
    adj.resize(n);
    UFDS ufds(n);
    for (int i = 0; i < n; i++) {
        cin >> adj[i];
        if (adj[i] != -1)ufds.unionSet(i, adj[i]);
    }
    dist.resize(n, INT_MAX);
    for (int i = 0; i < n; i++)dfs(i);
    vector<pii> res(n, pair(INT_MAX, INT_MAX));
    vector<bool> ispipe(n, true);
    for (int i = 0; i < n; i++) {
        if (adj[i] == -1)continue;
        ispipe[adj[i]] = false;
    }
    for (int i = 0; i < n; i++) {
        if (!ispipe[i])continue;
        int location = ufds.find(i);
        pii curr = res[location];
        if (dist[i] < curr.first)res[location] = pair(dist[i], i);
        else if (dist[i] == curr.first)res[location] = pair(dist[i], min(i, curr.second));
    }
    cin >> q;
    int x;
    while (q--) {
        cin >> x;
        cout << res[ufds.find(x)].second << endl;
    }
    return 0;
}