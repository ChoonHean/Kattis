#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vl;

int main() {
    ll n, k;
    cin >> n >> k;
    set<ll> pages;
    vector<bool> used(n);
    for (ll i = 1; i < n; i++)pages.insert(i);
    vl ans(n);
    int count = 1;
    while (k) {
        auto it = *(--pages.upper_bound(k));
        ans[it] = count++;
        used[it]=true;
        pages.erase(it);
        k -= it;
    }
    for (int i=0;i<n;i++)if(!used[i])ans[i]=count++;
    for (auto i: ans)cout << i << " ";
    return 0;
}
