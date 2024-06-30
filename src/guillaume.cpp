#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vl;

int main() {
    int n, a = 0, total = 0;
    double rate = 0, g = 0;
    vi ans(2, 0);
    string s;
    cin >> n >> s;
    while (n) {
        total++;
        n--;
        if (s[n] == 'A')a++;
        else if (s[n] == 'G')g++;
        else total--;
        if (g / total > rate) {
            rate = g / total;
            ans[0] = g;
            ans[1] = a;
        }
        if (!rate)
            if (total) {
                ans[1] = a;
                rate = DBL_MIN;
            }
    }
    cout << ans[0] << '-' << ans[1];
    return 0;
}
