#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<pll> vpll;
typedef vector<pdd> vpdd;
typedef tree<pair<int, ll>, null_type, greater<pair<int, ll>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int inf = 1e9;
const int mod = 1e9 + 7;
#define all(a) a.begin(),a.end()
#define read(n) vi arr(n);for(int _=0;_<n;_++)cin>>arr[_]
#define readarr(n, arr) for(int _=0;_<n;_++)cin>>arr[_]
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
inline void pr(deque<T> q) {
    deque<T> copy(q);
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

struct BSTVertex {
    // all these attributes remain public to slightly simplify the code although this may not be the best practice
    BSTVertex *parent;
    BSTVertex *left;
    BSTVertex *right;
    int key;
    int height; // will be used in AVL lecture
    int size;
};

// This is just a sample implementation
// There are other ways to implement BST concepts...
struct BST {
    BSTVertex *root;

    BSTVertex *insert(BSTVertex *T, int v) {
        if (T == NULL) {                             // insertion point is found
            T = new BSTVertex;
            T->key = v;
            T->parent = T->left = T->right = NULL;
            T->height = 0;                             // used in AVL lecture
        } else if (T->key < v) {                       // search to the right
            T->right = insert(T->right, v);
            T->right->parent = T;
        } else {                                       // search to the left
            T->left = insert(T->left, v);
            T->left->parent = T;
        }
        return T;                                    // return the updated BST
    }

    void inorder(BSTVertex *T) {
        if (T == NULL) return;
        inorder(T->left);                            // recursively go to the left
        printf("(%d, %d) ", T->key, T->size);                       // visit this BST node
        inorder(T->right);                           // recursively go to the right
    }

    void preorder(BSTVertex *T) {
        if (T == NULL) return;
        printf(" %d", T->key);                       // visit this BST node
        preorder(T->left);                           // recursively go to the left
        preorder(T->right);                          // recursively go to the right
    }

    int findMin(BSTVertex *T) {
        if (T == NULL) return -1;         // BST is empty, no minimum
        else if (T->left == NULL) return T->key;     // this is the min
        else return findMin(T->left); // go to the left
    }

    int findMax(BSTVertex *T) {
        if (T == NULL) return -1;        // BST is empty, no maximum
        else if (T->right == NULL) return T->key;    // this is the max
        else return findMax(T->right); // go to the right
    }

    BSTVertex *search(BSTVertex *T, int v) {
        if (T == NULL) return T;              // not found
        else if (T->key == v) return T;              // found
        else if (T->key < v) return search(T->right, v); // search to the right
        else return search(T->left, v); // search to the left
    }

    int successor(BSTVertex *T) {
        if (T->right != NULL)                        // we have right subtree
            return findMin(T->right);                  // this is the successor
        else {
            BSTVertex *par = T->parent;
            BSTVertex *cur = T;
            // if par(ent) is not root and cur(rent) is its right children
            while ((par != NULL) && (cur == par->right)) {
                cur = par;                               // continue moving up
                par = cur->parent;
            }
            return par == NULL ? -1 : par->key;        // this is the successor of T
        }
    }

    int predecessor(BSTVertex *T) {
        if (T->left != NULL)                         // we have left subtree
            return findMax(T->left);                   // this is the predecessor
        else {
            BSTVertex *par = T->parent;
            BSTVertex *cur = T;
            // if par(ent) is not root and cur(rent) is its left children
            while ((par != NULL) && (cur == par->left)) {
                cur = par;                               // continue moving up
                par = cur->parent;
            }
            return par == NULL ? -1 : par->key;        // this is the successor of T
        }
    }

    BSTVertex *remove(BSTVertex *T, int v) {
        if (T == NULL) return T;                    // cannot find the item

        if (T->key == v) {                           // the node to be deleted
            if (T->left == NULL && T->right == NULL)   // this is a leaf
                T = NULL;                                // simply erase this node
            else if (T->left == NULL && T->right != NULL) { // only one child at right
                T->right->parent = T->parent;            // ma, take care of my child
                T = T->right;                            // bypass T
            } else if (T->left != NULL && T->right == NULL) { // only one child at left
                T->left->parent = T->parent;             // ma, take care of my child
                T = T->left;                             // bypass T
            } else { // has two children, find successor to avoid quarrel
                int successorV = successor(v);           // predecessor is also OK btw
                T->key = successorV;                     // replace with successorV
                T->right = remove(T->right, successorV); // delete the old successorV
            }
        } else if (T->key < v)                         // search to the right
            T->right = remove(T->right, v);
        else                                         // search to the left
            T->left = remove(T->left, v);
        return T;                                    // return the updated BST
    }

    // will be used in AVL lecture
    int getHeight(BSTVertex *T) {
        if (T == NULL) return -1;
        else return max(getHeight(T->left), getHeight(T->right)) + 1;
    }

    BST() { root = NULL; }

    void insert(int v) { root = insert(root, v); }

    void inorder() {
        inorder(root);
        printf("\n");
    }

    void preorder() {
        preorder(root);
        printf("\n");
    }

    int findMin() { return findMin(root); }

    int findMax() { return findMax(root); }

    int search(int v) {
        BSTVertex *res = search(root, v);
        return res == NULL ? -1 : res->key;
    }

    int successor(int v) {
        BSTVertex *vPos = search(root, v);
        return vPos == NULL ? -1 : successor(vPos);
    }

    int predecessor(int v) {
        BSTVertex *vPos = search(root, v);
        return vPos == NULL ? -1 : predecessor(vPos);
    }

    void remove(int v) { root = remove(root, v); }

    // will be used in AVL lecture
    int getHeight() { return getHeight(root); }
};

struct AVL : public BST { // another example of C++ inheritance
    int h(BSTVertex *T) { return T == NULL ? -1 : T->height; }

    BSTVertex *rotateLeft(BSTVertex *T) {
        // T must have a right child

        BSTVertex *w = T->right;
        w->parent = T->parent;
        T->parent = w;
        T->right = w->left;
        if (w->left != NULL) w->left->parent = T;
        w->left = T;

        T->height = max(h(T->left), h(T->right)) + 1;
        w->height = max(h(w->left), h(w->right)) + 1;
        T->size = 1 + (T->left == nullptr ? 0 : T->left->size) + (T->right == nullptr ? 0 : T->right->size);

        return w;
    }

    BSTVertex *rotateRight(BSTVertex *T) {
        // T must have a left child

        BSTVertex *w = T->left;
        w->parent = T->parent;
        T->parent = w;
        T->left = w->right;
        if (w->right != NULL) w->right->parent = T;
        w->right = T;

        T->height = max(h(T->left), h(T->right)) + 1;
        w->height = max(h(w->left), h(w->right)) + 1;
        T->size = 1 + (T->left == nullptr ? 0 : T->left->size) + (T->right == nullptr ? 0 : T->right->size);

        return w;
    }

    BSTVertex *rebalance(BSTVertex *T) {
        int balance = h(T->left) - h(T->right);
        if (balance == 2) { // left heavy
            int balance2 = h(T->left->left) - h(T->left->right);
            if (balance2 >= 0) {
                T = rotateRight(T);
            } else { // -1
                T->left = rotateLeft(T->left);
                T = rotateRight(T);
            }
        } else if (balance == -2) { // right heavy
            int balance2 = h(T->right->left) - h(T->right->right);
            if (balance2 <= 0)
                T = rotateLeft(T);
            else { // 1
                T->right = rotateRight(T->right);
                T = rotateLeft(T);
            }
        }

        T->height = max(h(T->left), h(T->right)) + 1;
        T->size = 1 + (T->left == nullptr ? 0 : T->left->size) + (T->right == nullptr ? 0 : T->right->size);
        return T;
    }

    BSTVertex *insert(BSTVertex *T, int v, int val) {       // override insert in BST class
        if (T == NULL) {                             // insertion point is found
            T = new BSTVertex;
            T->key = val;
            T->parent = T->left = T->right = NULL;
            T->height = 0; // will be used in AVL lecture
        } else {
            int size = T->left == nullptr ? 0 : T->left->size;
            if (v > size) {                       // search to the right
                T->right = insert(T->right, v - size - 1, val);
                T->right->parent = T;
            } else {                                       // search to the left
                T->left = insert(T->left, v, val);
                T->left->parent = T;
            }
        }
        T = rebalance(T);
        return T;                                    // return the updated AVL
    }

    BSTVertex *remove(BSTVertex *T, int v) {
        if (T == NULL) return T;                    // cannot find the item

        if (T->key == v) {                           // the node to be deleted
            if (T->left == NULL && T->right == NULL)   // this is a leaf
                T = NULL;                                // simply erase this node
            else if (T->left == NULL && T->right != NULL) { // only one child at right
                T->right->parent = T->parent;
                T = T->right;                            // bypass T
            } else if (T->left != NULL && T->right == NULL) { // only one child at left
                T->left->parent = T->parent;
                T = T->left;                             // bypass T
            } else {                                     // find successor
                int successorV = successor(v);
                T->key = successorV;                     // replace with successorV
                T->right = remove(T->right, successorV); // delete the old successorV
            }
        } else if (T->key < v)                         // search to the right
            T->right = remove(T->right, v);
        else                                         // search to the left
            T->left = remove(T->left, v);

        if (T != NULL) {
            T = rebalance(T);
        }

        return T;                                    // return the updated BST
    }

    int select(BSTVertex *T, int k) {
        int size = T->left == nullptr ? 0 : T->left->size;
        if (size == k) {
            return T->key;
        } else if (size > k) {
            return select(T->left, k);
        } else {
            return select(T->right, k - size - 1);
        }
    }

    int select(int k) { return select(root, k); }

    AVL() { root = NULL; }

    void insert(int v, int val) { root = insert(root, v, val); }

    void remove(int v) { root = remove(root, v); }
};

inline void solve() {
    int q, c, x, i = 1;
    cin >> q;
    AVL tree;
    while (q--) {
        cin >> c >> x;
        if (c == 1) {
            tree.insert(x - 1, i++);
        } else {
            pnl(tree.select(x - 1));
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}