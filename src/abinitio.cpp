#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;
int main() {
    int v, e, q;
    cin >> v >> e >> q;
    vector<vector<int>> mat(4000, vector<int>(4000, 0)), t(4000, vector<int>(4000, 0)), c(4000, vector<int>(4000, 0)), tc(4000, vector<int>(4000, 0));
    while (e--) {
        int a, b;
        cin >> a >> b;
        mat[a][b] = 1;
        t[b][a] = 1;
    }
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (mat[i][j] == 0) {
                c[i][j] = 1;
                tc[j][i] = 1;
            }
        }
    }
    while (q--) {
        int query;
        cin >> query;
        switch (query) {
            case 1: {
                for (int i = 0; i < v; i++) {
                    c[i][v] = 1;
                    c[v][i] = 1;
                    tc[i][v] = 1;
                    tc[v][i] = 1;
                }
                v++;
                break;
            }
            case 2: {
                int a, b;
                cin >> a >> b;
                mat[a][b] = 1;
                t[b][a] = 1;
                c[a][b] = 0;
                tc[b][a] = 0;
                break;
            }
            case 3: {
                int a;
                cin >> a;
                for (int i = 0; i < v; i++) {
                    mat[i][a] = 0;
                    mat[a][i] = 0;
                    t[i][a] = 0;
                    t[a][i] = 0;
                    c[i][a] = 1;
                    c[a][i] = 1;
                    tc[i][a] = 1;
                    tc[a][i] = 1;
                }
                break;
            }
            case 4: {
                int a, b;
                cin >> a >> b;
                mat[a][b] = 0;
                t[b][a] = 0;
                c[a][b] = 1;
                tc[b][a] = 1;
                break;
            }
            case 5: {
                swap(mat, t);
                swap(c, tc);
                break;
            }
            case 6: {
                swap(mat, c);
                swap(t, tc);
                break;
            }
        }
    }
    cout << v << endl;
    int mod = 1000000007;
    for (int i = 0; i < v; i++) {
        int curr = 0;
        long long ans = 0;
        for (int j = v - 1; j >= 0; j--) {
            if (i == j) continue;
            if (mat[i][j] == 1) {
                curr++;
                ans *= 7;
                ans += j;
                ans %= mod;
            }
        }
        cout << curr << " " << ans << endl;
    }
    return 0;
}