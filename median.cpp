#include <iostream>
//#include "oil.h"
#include <algorithm>
#include <cmath>
using namespace std;
int mStart=2e9, mEnd=0;
int arr[1000],S;
int observe(int a, int b) {
    int sum=0;
    for(int i=a; i<=b; i++) {
        sum += arr[i];
    }
    if(sum == 0) return 0;
    if(sum > b-a) return 1;
    else if(sum <= b-a) return 2;
}
int oil_size(){
    return S;
}
void initial(){
    cin>>S;
    for(int i=0; i<S; i++) {
        cin>>arr[i];
    }
}
void check(int s, int l) {
    int res = observe(s,l);
    if(res == 0||res == -1) return;
    else if(res == 1) {
        mStart = min(s,mStart);
        mEnd = max(l,mEnd);
        return ;
    }else {
        if(s==l) return;
        check(s, (s+l)/2);
        check((s+l)/2+1, l);
    }
}
int main(){
    initial();
    int n = oil_size();
    check(0, n);
    cout<<mStart<<" "<<mEnd<<endl;
}
