#include <iostream>
#include <algorithm>
using namespace std;
int N;
int dp[11];
int check(int n){
    int &res = dp[n];
    if(res > 0) return res;
    int sum = 0;
    for(int i=1; i<=3; i++) {
        sum += check(n-i);
    }
    return dp[n]=sum;
}
int main(){
    cin>>N;
    dp[1] = 1; dp[2] = 2; dp[3] = 4;
    for(int i=0; i<N; i++) {
        int x;
        cin>>x;
        int res = check(x);
        cout<<res<<endl;
    }
}
