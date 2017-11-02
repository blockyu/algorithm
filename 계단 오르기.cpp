#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int N;
int arr[301];
pair<int,int> dp[301];
int check(int n) {
    if(n==0) return 0;
    check(n-1);
    dp[n].first = dp[n-1].second + arr[n];
    dp[n].second = max(dp[n-2].first, dp[n-2].second) + arr[n];
}
int main() {
    cin>>N;
    for(int i=1; i<=N; i++) {
        cin>>arr[i];
    }
    dp[1] = make_pair(arr[1],0);
    dp[2] = make_pair(arr[1]+arr[2],arr[2]);
    check(N);
    int res = max(dp[N].first, dp[N].second);
    cout<<res;
}
