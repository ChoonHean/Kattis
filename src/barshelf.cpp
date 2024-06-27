#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<double> vd;
typedef long long ll;
typedef vector<ll> vl;

template<typename T>
void print(T it) {
    for (auto i = it.begin(); i != it.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
}

class FenwickTree {
public:
    vl ft;
    ll count = 0;

    int lsb(int i) { return i & -i; }

    FenwickTree(int n) { ft.assign(n + 1, 0); }

    void update(int pos, int val) {
        count += val;
        for (; pos < (int) ft.size(); pos += lsb(pos))ft[pos] += val;
    }

    ll query(int pos) {
        ll ans = 0;
        for (; pos; pos -= lsb(pos)) {
            ans += ft[pos];
        }
        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    ll ans = 0, curr, highest = 0;
    vi heights;
    set<int> distinct;
    for (int i = 0; i < n; i++) {
        cin >> curr;
        highest = max(highest, curr);
        heights.push_back(curr);
        distinct.insert(curr);
    }
    map<int, int> mapper;
    int index = 1;
    for (auto it = distinct.begin(); it != distinct.end(); it++)mapper[*it] = index++;
    FenwickTree ft1(index), ft2(index);
    for (int i = 0; i < n; i++) {
        curr = heights[i];
        curr = curr * 2 - 1;
        curr = (--mapper.upper_bound(curr))->second;
        if (curr < index) {
            ans += ft2.count - ft2.query(curr);
            ft2.update(mapper[heights[i]], ft1.count - ft1.query(curr));
        }
        ft1.update(mapper[heights[i]], 1);
    }
    cout << ans;
    return 0;
}
