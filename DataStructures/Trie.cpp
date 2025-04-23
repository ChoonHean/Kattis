#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
#define sz(v) ((int)v.size())
#define pb push_back

struct Node {
    bool present;
    vi child;

    Node() : present(false), child(26, -1) {}
};

struct Trie {
    vector<Node> arr;

    void insert(string s) {
        int i = 0;
        for (const char &c: s) {
            if (arr[i].child[c - 'a'] == -1)arr[i].child[c - 'a'] = newNode();
            i = arr[i].child[c - 'a'];
        }
        arr[i].present = true;
    }

    bool search(string s) {
        int i = 0;
        for (const char &c: s) {
            if (arr[i].child[c - 'a'] == -1)return false;
            i = arr[i].child[c - 'a'];
        }
        return arr[i].present;
    }

    int prefix(string s) {
        int i = 0, cnt = 0;
        for (const char &c: s) {
            if (arr[i].child[c - 'a'] == -1)return cnt;
            i = arr[i].child[c - 'a'];
            cnt += arr[i].present;
        }
        return cnt;
    }

    int newNode() {
        arr.emplace_back();
        return sz(arr) - 1;
    }

    Trie() : arr(1) {};
};