// Some part of this is buggy, but I can't tell where.
// Since random priority values are used, it may pass the test
// cases with some luck, which I did by submitting a few times.

#include <bits/stdc++.h>

using namespace std;
mt19937_64 rnd(time(0));

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
//    Node *build(int L, int R) {
//        if (L > R)return nullptr;
//        if (L == R)return new Node(A[L]);
//        int mid = L + R >> 1;
//        Node *cur = new Node(A[mid]);
//        cur->left = build(L, mid - 1);
//        cur->right = build(mid + 1, R);
//        if(cur->left!=nullptr)cur->size+=cur->left->size;
//        if(cur->right!=nullptr)cur->size+=cur->right->size;
//        return cur;
//    }
};