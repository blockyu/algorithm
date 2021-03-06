#include <iostream>
#include <algorithm>
using namespace std;
int N, E;
const int INF = 2e8;
int dp[101][101];
int main(){
    cin>>N>>E;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            dp[i][j] = INF;
        }
    }
    for(int i=0; i<E; i++) {
        int s,l;
        cin>>s>>l;
        dp[s][l] = dp[l][s] = 1;
    }
    for(int k=1; k<=N; k++) {
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(dp[i][j] > dp[i][k] + dp[k][j]) {
                    dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }
    }
    int sum =0;
    for(int i=2; i<=N; i++) {
        if(dp[1][i] != INF &&dp[1][i] > 0) {
            sum ++;
        }
    }
    cout<<sum;
}
