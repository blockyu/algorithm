#include <iostream>
#include "oil.h"
#include <algorithm>
using namespace std;
int mStart, mEnd;
int flag = 1;
//
int ocheckL(int s, int l) {
    if(flag==1){
    int res = observe(s,l);
    if(res == 0) { return 0; }
    if(res == 1) { mStart = min(s,mStart); mEnd = max(l,mEnd);flag=2; return 1;}
    if(res == 2) { if(ocheckL(s, (s+l)/2) == 0) { return ocheckL((s+l)/2+1, l); }}
    }
}
int ocheckR(int s, int l) {
    if(flag==1) {
    int res = observe(s,l);
    if(res == 0) { return 0; }
    if(res == 1) { mStart = min(s,mStart); mEnd = max(l,mEnd);flag=2; return 1;}
    if(res == 2) { if(ocheckR((s+l)/2+1, l) == 0) { return ocheckR(s, (s+l)/2); }}
    }
}
//////
int checkL(int s, int l) {
    if(flag==1) {
    int res = observe(s,l);
    if(res == 0) { flag = 0;return 0; }
    if(res == 1) { mStart = min(s,mStart); mEnd = max(l,mEnd); return 1;}
    if(res == 2) { if(checkL((s+l)/2+1, l) == 1) { return checkL(s, (s+l)/2); }}
    }
}

int checkR(int s, int l) {
    if(flag==1){
    int res = observe(s,l);
    if(res == 0) { flag = 0;return 0; }
    if(res == 1) { mStart = min(s,mStart); mEnd = max(l,mEnd); return 1;}
    if(res == 2) { if(checkR(s, (s+l)/2) == 1) { return checkR((s+l)/2+1, l); }}
    }
}
int main(){
    initial();
    int n = oil_size();
    int res = observe(0,(n-1)/2), res2 = observe((n-1)/2+1, n-1);
    mStart=2e9;
    mEnd=0;
    if(res == 0) {
        ocheckL((n-1)/2+1, n-1);
        flag=1;
        ocheckR(mStart+1, n-1);
    }else if (res2 == 0) {
        ocheckL(0, (n-1)/2);
        flag=1;
        ocheckR(mStart+1, (n-1)/2);
    } else {
        checkL(0, (n-1)/2);
        flag=1;
        checkR((n-1)/2+1, n-1);
    }
    oil_report(mStart, mEnd);
}
