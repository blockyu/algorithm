#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
bool compare_(int lhs, int rhs) {
    return lhs>rhs;
}
int main() {
    vector<int> v;
    cin>>N;
    while(N>0) {
        int dec = N%10;
        N /= 10;
        v.push_back(dec);
    }
    sort(v.begin(), v.end(), compare_);
    for(int i=0; i<v.size(); i++) {
        cout<<v[i];
    }
}
