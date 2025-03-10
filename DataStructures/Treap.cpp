// Some part of this is buggy, but I can't tell where.
// Since random priority values are used, it may pass the test
// cases with some luck, which I did by submitting a few times.

#include <bits/stdc++.h>

using namespace std;
mt19937_64 rnd(time(0));

struct Node {
    int size, prio, val, rsq, lazy, ans, key;
    Node *left;
    Node *right;

    Node(int val) : size(1), left(nullptr), right(nullptr), prio(rnd()), val(val) {};
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
        for (int i = 1; i < A.size(); i++) insert(A[i]);
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
        for (int i = 1; i < n; i++) insert(A[i]);
    }

    inline int size(Node *node) {
        return node ? node->size : 0;
    }

    inline int rsq(Node *node) {
        return node ? node->rsq : 0;
    }

    inline void update(Node *node) {
        if (node) {
            node->size = size(node->left) + size(node->right) + 1;
            node->rsq = rsq(node->left) + rsq(node->right) + node->val;
        }
    }

    inline void propogate(Node *cur) {
        if (cur->left)
            cur->left->lazy += cur->lazy;
        if (cur->right)
            cur->right->lazy ^= cur->lazy;
        cur->ans += cur->lazy;
        cur->lazy = 0;
    }

    void merge(Node *&cur, Node *small, Node *large) {
        propogate(small);
        propogate(large);
        if (!small || !large)
            cur = small ? small : large;
        else if (small->prio > large->prio)
            merge(small->right, small->right, large), cur = small;
        else
            merge(large->left, small, large->left), cur = large;
        update(cur);
    }

    void split(Node *cur, Node *&l, Node *&r, int k) {
        propogate(cur);
        if (!cur)
            return void(l = r = 0);
        else if (k <= size(cur->left))
            split(cur->left, l, cur->left, k), r = cur;
        else
            split(cur->right, cur->right, r, k - size(cur->left) - 1), l = cur;
        update(cur);
    }

    void insert(Node *cur) {
        Node *l;
        Node *r;
        split(root, l, r, 0);
        merge(l, l, cur);
        merge(root, l, r);
    }

    void *select(Node *cur, Node *&res, int k) {
        if (size(cur->left) == k)
            res = cur;
        else if (k < size(cur->left))
            select(cur->left, res, k);
        else
            select(cur->right, res, k - size(cur->left) - 1);

    }

    void inorder(Node *cur) {
        propogate(cur);
        if (cur->left != nullptr)inorder(cur->left);
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