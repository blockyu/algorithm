#include <iostream>
#include <algorithm>
using namespace std;
int N;
const int INF = 2e5;
int dp[101][101];
int main(){
    cin>>N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin>>dp[i][j];
            if(dp[i][j]==0) dp[i][j] = INF;
        }
    }
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(dp[i][j] > dp[i][k] + dp[k][j])
                    dp[i][j] = dp[i][k] + dp[k][j];
            }
        }
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(dp[i][j]==INF) cout<<0<<" ";
            else cout<<1<<" ";
        }
        cout<<endl;
    }
}
