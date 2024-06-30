#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int mod = 1e9 + 7;

template<typename T>
void print(T it) {
    for (auto i = it.begin(); i != it.end(); i++) {
        cout << *i << " ";
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

inline void solve() {
    int hi, lo = 1, first, second, isfirst, issecond, split, remain, third, fourth;
    cin >> hi;
    int n = hi;
    while (true) {
        if (hi - lo == 1) {
            cout << "Q " << lo << ' ' << lo << ' ' << hi << ' ' << hi << endl;
            cout.flush();
            cin >> isfirst >> issecond;
            if (isfirst)cout << "A " << lo;
            else cout << "A " << hi;
            return;
        } else if (hi - lo == 2) {
            cout << "Q " << lo << ' ' << lo << ' ' << hi << ' ' << hi << endl;
            cout.flush();
            cin >> isfirst >> issecond;
            if (isfirst)cout << "A " << lo;
            else if (issecond)cout << "A " << hi;
            else cout << "A " << hi - 1;
            return;
        } else if (hi - lo == 3) {
            cout << "Q " << lo << ' ' << lo + 1 << ' ' << lo + 1 << ' ' << lo + 2 << endl;
            cout.flush();
            cin >> isfirst >> issecond;
            if (isfirst) {
                if (issecond) {
                    cout << "A " << lo + 1;
                } else cout << "A " << lo;
            } else if (issecond) {
                cout << "A " << lo + 2;
            } else cout << "A " << hi;
            return;
        }
        split = (hi - lo + 1) >> 2;
        remain = (hi - lo + 1) % 4;
        first = lo;
        second = lo + (split << 1);
        third = lo + split;
        fourth = hi - split;
        if (remain) {
            third++;
        }
        if (remain > 1) {
            fourth--;
        }
        //cout<<lo<<' '<<hi<<endl;
        cout << "Q " << first << ' ' << second << ' ' << third << ' ' << fourth << endl;
        cout.flush();
        cin >> isfirst >> issecond;
        if (isfirst) {
            if (issecond) {
                lo = third - 1;
                hi = second + 1;
            } else {
                lo = max(1, lo - 1);
                hi = third;
            }
        } else if (issecond) {
            lo = second;
            hi = fourth + 1;
        } else {
            lo = fourth;
            hi = min(n, hi + 1);
        }
    }
}


int main() {
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
