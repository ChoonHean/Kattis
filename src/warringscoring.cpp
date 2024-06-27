#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    int yscore=0,nscore=0,ystreak=0,nstreak=0,yhigh1=0,nhigh1=0,yhigh2=0,nhigh2=0;
    while(n-->0){
        cin >> s;
        if (s.starts_with('Y')) {
            yhigh1=max(yhigh1,++ystreak);
            nstreak=0;
            yhigh2=max(yhigh2,++yscore-nscore);
        }else{
            nhigh1=max(nhigh1,++nstreak);
            ystreak=0;
            nhigh2=max(nhigh2,++nscore-yscore);
        }
    }
    if (nhigh1>yhigh1&&nhigh2>yhigh2) cout << "Agree";
    else if (nhigh1<yhigh1&&nhigh2<yhigh2) cout << "Agree";
    else if (nhigh1==yhigh1&&nhigh2==yhigh2) cout << "Agree";
    else cout << "Disagree";
    return 0;
}
