#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vl;

int main() {
    int n, k;
    cin >> n >> k;
    vl times(n);
    for (int i = 0; i < n; i++)cin >> times[i];
    sort(times.begin(), times.end());
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    for (int i = 0; i < min(k, n); i++)pq.push(pair<ll, ll>(times[i], times[i]));
    pair<ll, ll> ans(times[0], times[0]);
    while (n > 0) {
        ans = pq.top();
        pq.pop();
        if (ans.first == ans.second)n -= 5;
        else n -= 4;
        pq.push(pair(ans.first + ans.second * 2, ans.second));
    }
    cout << ans.first;
    return 0;
}
