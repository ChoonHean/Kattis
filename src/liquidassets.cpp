#include <iostream>

using namespace std;

int main() {
    int n;
    string s, res;
    cin >> n;
    getline(cin, s);
    getline(cin, s);
    int len = s.size();
    res.push_back(s[0]);
    for (int i = 1; i < len; i++) {
        if (s[i] == s[i - 1]) {
            continue;
        }
        res.push_back(s[i]);
    }
    s = res;
    res = s[0];
    for (int i = 1; i < s.size() - 1; i++) {
        if (s[i - 1] == ' ' || s[i + 1] == ' ') {
            res.push_back(s[i]);
            continue;
        }
        char c = s[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'u' || c == 'o') {
            continue;
        }
        res.push_back(s[i]);
    }
    res.push_back(s[s.size() - 1]);
    cout << res;
    return 0;
}
