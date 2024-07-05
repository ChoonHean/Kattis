#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
const int inf = 1e9;
const int mod = 1e9 + 7;
#define all(a) a.begin(),a.end()
#define read(n) vi arr(n);for(int i=0;i<n;i++)cin>>arr[i]
#define readarr(n, arr) for(int i=0;i<n;i++)cin>>arr[i]
#define forloop(a, n) for(int i=a;i<n;i++)
#define nl "\n"

template<typename T>
inline void print(T it) {
    for (auto i = it.begin(); i != it.end(); i++) {
        cout << *i << " ";
    }
    cout << nl;
}

template<typename T>
inline void print_p(T v) {
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << "(" << (*it).first << "," << (*it).second << ") ";
    }
    cout << nl;
}

bool c = true;

inline void solve() {
    string str;
    cin >> str;
    if (str == "0") {
        c = false;
        return;
    }
    for (int p = 0; p < 2; p++)
        for (int q = 0; q < 2; q++)
            for (int r = 0; r < 2; r++)
                for (int s = 0; s < 2; s++)
                    for (int t = 0; t < 2; t++) {
                        stack<int> st;
                        for (int a = str.size() - 1; a >= 0; a--) {
                            if (str[a] == 'p')st.push(p);
                            else if (str[a] == 'q')st.push(q);
                            else if (str[a] == 'r')st.push(r);
                            else if (str[a] == 's')st.push(s);
                            else if (str[a] == 't')st.push(t);
                            else if (str[a] == 'K') {
                                int b = st.top();
                                st.pop();
                                b &= st.top();
                                st.pop();
                                st.push(b);
                            } else if (str[a] == 'A') {
                                int b = st.top();
                                st.pop();
                                b |= st.top();
                                st.pop();
                                st.push(b);
                            } else if (str[a] == 'N') {
                                int b = st.top() ^ 1;
                                st.pop();
                                st.push(b);
                            } else if (str[a] == 'C') {
                                int b = st.top();
                                st.pop();
                                if (b == 1 && st.top() == 0)b = 0;
                                else b = 1;
                                st.pop();
                                st.push(b);
                            } else {
                                int b = st.top();
                                st.pop();
                                b = b == st.top();
                                st.pop();
                                st.push(b);
                            }
                        }
                        if (!st.top()) {
                            cout << "not" << nl;
                            return;
                        }
                    }
    cout << "tautology" << nl;
}

int main() {
    int t = 1;
    //cin >> t;
    while (c) {
        solve();
    }
    return 0;
}