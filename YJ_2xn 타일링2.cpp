//
// Created by Yujin Park on 2019-08-07.
//
#include <iostream>
#include <algorithm>
using namespace std;
int N;
int dp[1001];
int main() {
    cin>>N;
    dp[1]=1; dp[2]=3;
    for(int i=3; i<=N; i++) {
        dp[i]=dp[i-1]+dp[i-2]*2;
        dp[i]%=10007;
    }
    cout<<dp[N];
}