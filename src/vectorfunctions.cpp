#include <bits/stdc++.h>
using namespace std;

void backwards(std::vector<int>& vec){
    int n=vec.size();
    for(int i=0;i<n>>1;i++){
        swap(vec[i],vec[n-1-i]);
    }
}

std::vector<int> everyOther(const std::vector<int>& vec){
    vector<int>res;
    for(int i=0;i<vec.size();i+=2)res.push_back(vec[i]);
    return res;
}

int smallest(const std::vector<int>& vec){
    int res=INT_MAX;
    for(int i:vec)res=min(res,i);
    return res;
}

int sum(const std::vector<int>& vec){
    int res=0;
    for(int i:vec)res+=i;
    return res;
}

int veryOdd(const std::vector<int>& suchVector){
    int res=0;
    for(int i=1;i<suchVector.size();i+=2)if(suchVector[i]&1)res++;
    return res;
}