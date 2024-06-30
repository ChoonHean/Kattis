#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<int, int> pii;

template<typename T>
void print(T it) {
    for (auto i = it.begin(); i != it.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
}

int main() {
    vector<vs> counts(5, vs(4));
    for (int j = 0; j < 3; j += 2) {
        for (int i = 0; i < 5; i++) {
            for (int k = 0; k < 2; k++) {
                cin >> counts[i][j + k];
            }
        }
    }
    vector<vd> ratios(4, vd(4));
    for (int h = 0; h < 4; h++) {
        for (int k = 0; k < 5; k++) {
            for (int i = 0; i < 4; i++) {
                if (counts[k][i] == "_")continue;
                for (int j = i + 1; j < 4; j++) {
                    if (counts[k][j] == "_")continue;
                    ratios[i][j] = stod(counts[k][i]) / stod(counts[k][j]);
                }
            }
        }
        for (int k = 0; k < 5; k++) {
            for (int i = 0; i < 4; i++) {
                if (counts[k][i] == "_") {
                    for (int j = 0; j < 4; j++) {
                        if (counts[k][j] == "_")continue;
                        if (i < j) {
                            if (ratios[i][j] == 0)continue;
                            counts[k][i] = to_string((int) round(ratios[i][j] * stod(counts[k][j])));
                            break;
                        } else {
                            if (ratios[j][i] == 0)continue;
                            counts[k][i] = to_string((int) round(stod(counts[k][j]) / ratios[j][i]));
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < 3; i += 2) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 2; k++) {
                cout << counts[j][i + k] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
