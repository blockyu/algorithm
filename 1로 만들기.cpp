#include <iostream>
#include <algorithm>
using namespace std;
int dp[1000001];
int check(int n) {
    if(n == 1) return 0;
    int &res = dp[n];
    if(res > 0) return res;
    if(n%3==0) return res = min(1+check(n-1), 1+check(n/3));
    else if(n%2 == 0) return res = min(1+check(n-1), 1+check(n/2));
    else return res = 1+check(n-1);

}
int main(){
    int n, cnt;
    cin>>n;
    cnt = check(n);
    cout<<cnt;
}
