#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<double> vd;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<int, int> pii;

template<typename T>
void print(T it) {
    for (auto i = it.begin(); i != it.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
}

vector<vi> adj, transposed;
vector<bool> visited;
stack<int> order;
int curr;

void dfs(int n) {
    visited[n] = true;
    for (int i: adj[n])if (!visited[i])dfs(i);
    order.push(n);
}

void kosaraju(int n) {
    curr++;
    visited[n] = true;
    for (int i: transposed[n])if (!visited[i])kosaraju(i);
}

int main() {
    int n;
    cin >> n;
    adj.resize(2 * n, vi()), transposed.resize(2 * n, vi()), visited.resize(2 * n);
    unordered_map<string, int> mapper;
    int index = 0;
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> a >> b;
        auto p1 = mapper.emplace(a, index);
        if (p1.second)index++;
        auto p2 = mapper.emplace(b, index);
        if (p2.second)index++;
        adj[(*p1.first).second].push_back((*p2.first).second);
        transposed[(*p2.first).second].push_back((*p1.first).second);
    }
    for (int i = 0; i < n; i++)if (!visited[i])dfs(i);
    fill(visited.begin(), visited.end(), false);
    int res = 0;
    while (!order.empty()) {
        int i = order.top();
        order.pop();
        curr = 0;
        if (!visited[i])kosaraju(i);
        res = max(res, curr);
    }
    res >= 2 ? cout << res : cout << "No trades possible";
    return 0;
}
