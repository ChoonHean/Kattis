#include <bits/stdc++.h>

using namespace std;
#define sz(v) ((int)v.size())

struct Node {
    bool present;
    vector<Node *> child;

    Node() : present(false), child(26, nullptr) {};
};

struct Trie {
    Node *root = new Node();

    void insert(string s) {
        Node *curr = root;
        for (char c: s) {
            if (curr->child[c - 'a'] == nullptr)curr->child[c - 'a'] = new Node();
            curr = curr->child[c - 'a'];
            curr->present = true;
        }
    }

    bool search(string s) {
        Node *curr = root;
        for (char c: s) {
            if (curr->child[c - 'a'] == nullptr)return false;
            curr = curr->child[c - 'a'];
            if (!curr->present)return false;
        }
        return true;
    }

    int prefix(string s) {
        Node *curr = root;
        int cnt = 0;
        for (int i = 0; i < sz(s); i++) {
            char c = s[i];
            if (curr->child[c - 'a'] == nullptr)return cnt;
            curr = curr->child[c - 'a'];
            if (!curr->present)return cnt;
            cnt++;
        }
        return cnt;
    }

    Trie() {};
};