#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int mod = 1e9 + 7;
ll inf = LLONG_MAX;

template<typename T>
void print(T v) {
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
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

void solve() {
    int n;
    cin >> n;
    vi fib(n + 1);
    fib[1] = 1;
    for (int i = 2; i <= n; i++)fib[i] = fib[i - 1] + fib[i - 2];
    cout << fib[n - 1] << ' ' << fib[n];
}

int main() {
    int t = 1;
    while (t--) solve();
    return 0;
}