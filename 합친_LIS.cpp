//
// Created by Yujin Park on 2019-09-04.
//
#include <iostream>
using namespace std;
int a[101];
int b[101];
int dp[101][101];
int main() {
    int tc;
    cin>>tc;
    for(int _=1; _<=tc; _++) {
        int asize, bsize;
        cin>>asize>>bsize;
        for(int i=0; i<asize; i++) {
            cin>>a[i];
        }
        for(int i=0; i<bsize; i++) {
            cin>>b[i];
        }
        fill(dp, dp+asize, 1);
        for(int i=1; i<asize; i++) {
            if(a[i]>a[i-1]) {
                dp[0][i] = dp[0][i-1] + 1
            }
        }
        for(int i=1; i<=asize; i++) {
            for(int j=1; j<=bsize; j++) {
                
            }
        }
    }
}