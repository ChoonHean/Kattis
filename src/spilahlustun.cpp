#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// Sometimes fails as Treap is buggy, but the random priority values makes it pass with luck
using namespace std;
using namespace __gnu_pbds;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pdd> vpdd;
typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int inf = 1e9;
const int mod = 1e9 + 7;
#define all(a) a.begin(),a.end()
#define read(n) vi arr(n);for(int i=0;i<n;i++)cin>>arr[i]
#define readarr(n, arr) for(int i=0;i<n;i++)cin>>arr[i]
#define rep(a, n) for(int i=a;i<n;i++)
#define nl "\n"
#define sz(v) ((int)v.size())
#define PQ priority_queue
#define hmap unordered_map
#define hset unordered_set
#define pb push_back
#define clz(i) __builtin_clz(i)
#define ctz(i) __builtin_ctz(i)
#define popcount(i) __builtin_popcount(i)
#define lsb(i) (i&-i)
mt19937_64 rnd(time(0));


template<typename T>
inline void pr(T t) { cout << t << ' '; }

template<typename T>
inline void pnl(T t) {
    pr(t);
    cout << nl;
}

template<typename T, typename U>
inline void pr(pair<T, U> pa) {
    cout << '(';
    pr(pa.first);
    cout << ',';
    pr(pa.second);
    cout << ") ";
}

template<typename T>
inline void pr(vector<T> v) {
    for (auto i: v) pr(i);
    cout << nl;
}

template<typename T>
inline void pr(set<T> s) {
    for (auto t: s)pr(t);
    cout << nl;
}

template<typename T>
inline void pr(unordered_set<T> s) {
    for (auto t: s)pr(t);
    cout << nl;
}

template<typename T, typename U>
inline void pr(map<T, U> m) {
    for (auto [t, u]: m) {
        cout << '(';
        pr(t);
        pr('-');
        pr(u);
        pr(')');
    }
    cout << nl;
}

template<typename T, typename U>
inline void pr(unordered_map<T, U> m) {
    for (auto [t, u]: m) {
        cout << '(';
        pr(t);
        pr('-');
        pr(u);
        pr(')');
    }
    cout << nl;
}

template<typename T>
inline void pr(queue<T> q) {
    queue<T> copy(q);
    while (!copy.empty()) {
        pr(copy.front());
        copy.pop();
    }
    cout << nl;
}

template<typename T>
inline void pr(stack<T> s) {
    stack<T> copy(s);
    while (!copy.empty()) {
        pr(copy.top());
        copy.pop();
    }
    cout << nl;
}

template<typename T>
inline void pr(PQ<T> pq) {
    PQ<T> copy(pq);
    vector<T> arr;
    while (!copy.empty()) {
        arr.pb(copy.top());
        copy.pop();
    }
    pr(arr);
    cout << nl;
}

template<typename T>
inline void pr(PQ<T, vector<T>, greater<T>> pq) {
    auto copy(pq);
    vector<T> arr;
    while (!copy.empty()) {
        arr.pb(copy.top());
        copy.pop();
    }
    pr(arr);
    cout << nl;
}

inline int euclid(int a, int b, int &x, int &y) { // pass x and y by ref
    int xx = y = 0;
    int yy = x = 1;
    while (b) { // repeats until b == 0
        int q = a / b;
        int t = b;
        b = a % b;
        a = t;
        t = xx;
        xx = x - q * xx;
        x = t;
        t = yy;
        yy = y - q * yy;
        y = t;
    }
    return a; // returns gcd(a, b)
}

inline ll binpow(ll a, int p, int m) {
    ll res = 1;
    while (p) {
        if (p & 1)res = (res * a) % m;
        a = (a * a) % m;
        p >>= 1;
    }
    return res;
}

struct Node {
    int size, prio, val;
    Node *left;
    Node *right;
    bool reverse, up;

    Node(int val) : size(1), left(nullptr), right(nullptr), reverse(false), up(false), prio(rnd()), val(val) {};
};

struct Treap {
    Node *root;

    Treap(vector<int> &arr) {
        build(arr);
    }

    Treap(vector<Node *> A) {
        sort(A.begin(), A.end(), [](Node *a, Node *b) {
            return a->prio > b->prio;
        });
        root = A[0];
        for (int i = 1; i < A.size(); i++) insert(A[i], root);
    }

    Treap(Node *root) : root(root) {};

    void build(vector<int> &arr) {
        int n = arr.size();
        vector<Node *> A(n);
        for (int i = 0; i < n; i++) A[i] = new Node(arr[i]);
        sort(A.begin(), A.end(), [](Node *a, Node *b) {
            return a->prio > b->prio;
        });
        root = A[0];
        for (int i = 1; i < n; i++) insert(A[i], root);
    }

    inline void propogate(Node *cur) {
        if (cur->left != nullptr)
            cur->left->reverse ^= cur->reverse;
        if (cur->right != nullptr)
            cur->right->reverse ^= cur->reverse;
        if (cur->reverse) {
            swap(cur->left, cur->right);
            cur->up ^= 1;
        }
        cur->reverse = false;
    }

    void insert(Node *node, Node *cur) {
        if (node->val < cur->val) {
            if (cur->left == nullptr) cur->left = node;
            else insert(node, cur->left);
        } else {
            if (cur->right == nullptr) cur->right = node;
            else insert(node, cur->right);
        }
        cur->size += 1;
    }

    pair<Treap, Treap> split(int val) { return split(root, val); }

    pair<Treap, Treap> split(Node *cur, int val) {
        propogate(cur);
        int size = cur->left == nullptr ? 0 : cur->left->size;
        if (val < size) {//Split in left subtree
            cur->size -= size;
            pair<Treap, Treap> res = split(cur->left, val);
            cur->left = nullptr;
            Treap large(cur);
            res.second.merge(large);
            return res;
        } else if (val == size) {//Split this from left subtree
            Treap small(cur->left), large(cur);
            cur->size -= val;
            cur->left = nullptr;
            return pair(small, large);
        } else if (val == size + 1) {//Split this from right subtree
            Treap small(cur), large(cur->right);
            cur->size = val;
            cur->right = nullptr;
            return pair(small, large);
        } else {//Split in right subtree
            pair<Treap, Treap> res = split(cur->right, val - size - 1);
            cur->size = 1 + size;
            cur->right = nullptr;
            Treap small(cur);
            small.merge(res.first);
            res.first = small;
            return res;
        }
    }

    void merge(Node *small, Node *large) {
        propogate(small);
        propogate(large);
        if (small->right == nullptr) {
            if (large->left == nullptr) {
                if (small->prio > large->prio) {
                    small->size += large->size;
                    small->right = large;
                } else {
                    large->size += small->size;
                    large->left = small;
                }
            } else {
                if (small->prio > large->prio) {
                    small->size += large->size;
                    small->right = large;
                } else if (small->prio > large->left->prio) {
                    large->size += small->size;
                    small->size += large->left->size;
                    small->right = large->left;
                    large->left = small;
                } else {
                    large->size += small->size;
                    merge(small, large->left);
                }
            }
        } else if (large->left == nullptr) {
            if (large->prio > small->prio) {
                large->size += small->size;
                large->left = small;
            } else if (large->prio > small->right->prio) {
                small->size += large->size;
                large->size += small->right->size;
                large->left = small->right;
                small->right = large;
            } else {
                small->size += large->size;
                merge(small->right, large);
            }
        } else {
            if (small->prio > large->prio) {
                small->size += large->size;
                if (small->right->prio > large->prio) {
                    merge(small->right, large);
                } else {
                    Node *nextsmall = small->right;
                    small->right = large;
                    merge(nextsmall, large);
                }
            } else {
                large->size += small->size;
                if (large->left->prio > small->prio) {
                    merge(small, large->left);
                } else {
                    Node *nextlarge = large->left;
                    large->left = small;
                    merge(small, nextlarge);
                }
            }
        }
    }

    void merge(Treap other) {
        Node *newroot = root->prio > other.root->prio ? root : other.root;
        merge(root, other.root);
        root = newroot;
    }

    void inorder() { inorder(root); }

    void inorder(Node *cur) {
        propogate(cur);
        if (cur->left != nullptr)inorder(cur->left);
        cur->up ? cout << -cur->val << ' ' : cout << cur->val << ' ';
        if (cur->right != nullptr)inorder(cur->right);
    }
};

inline void solve() {
    int n, q, x, y;
    cin >> n >> q;
    vi arr;
    arr.reserve(n);
    rep(1, n + 1)arr.pb(i);
    Treap treap(arr);
    while (q--) {
        cin >> x >> y;
        Treap a = nullptr, b = nullptr, c = nullptr;
        bool hasa = false, hasc = false;
        if (x != 1) {
            auto ret = treap.split(x - 1);
            a = ret.first;
            b = ret.second;
            hasa = true;
        } else b = treap;
        if (y != n) {
            auto ret = b.split(y - x + 1);
            b = ret.first;
            c = ret.second;
            hasc = true;
        }
        b.propogate(b.root);
        b.root->reverse = true;
        if (hasa)a.merge(b);
        else a = b;
        if (hasc)a.merge(c);
        treap = a;
    }
    treap.inorder();
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}