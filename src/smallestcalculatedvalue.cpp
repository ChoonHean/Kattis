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

int main() {
    int a, b, c, d;
    cin >> a >> b >> c;
    int res = INT_MAX;
    vi ls;
    ls.push_back(a + b);
    ls.push_back(a - b);
    ls.push_back(a * b);
    if (a % b == 0)ls.push_back(a / b);
    for (int i: ls) {
        d = i + c;
        if (d >= 0)res = min(res, d);
        d = i - c;
        if (d >= 0)res = min(res, d);
        if (i % c == 0) {
            d = i / c;
            if (d >= 0)res = min(res, d);
        }
    }
    cout << res;
    return 0;
}
