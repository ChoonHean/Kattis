#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
typedef pair<double, double> pdd;
vector<pdd> prob(30);
vector<int> cost(30);

ll f(int current, int target) {
    if (current == target)return 0;
    auto &[success, boom] = prob[current];
    double clicks = 1 / success;
    ll costIfBoom = boom ? boom * clicks * f(12, current) : 0;
    ll costToNextStar = clicks * cost[current];
    return costIfBoom + costToNextStar + f(current + 1, target);
}

int main() {
    prob[12] = {0.42, 0};
    prob[13] = {0.3675, 0};
    prob[14] = prob[15] = prob[16] = {0.315, 0};
    prob[17] = {0.1575, 0};
    prob[18] = {0.1575, 0.0472};
    prob[19] = {0.1575, 0.059};
    prob[20] = {0.315, 0.0719};
    prob[21] = {0.1575, 0.0885};
    cost[12] = 52018400;
    cost[13] = 86609950;
    cost[14] = 153102670;
    cost[15] = 376080570;
    cost[16] = 442964160;
    cost[17] = 689175810;
    cost[18] = 443052750;
    cost[19] = 791565600;
    cost[20] = 203180320;
    cost[21] = 368595570;
    for (int i = 16; i < 23; i++)cout << "15 to " << i << ": " << f(15, i) << endl;
}