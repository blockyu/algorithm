#include <iostream>
#include <algorithm>
using namespace std;
int N, E;
int dp[101][101];
const int INF = 2e8;
int main(){
    cin>>N>>E;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            dp[i][j] = INF;
        }
    }
    for(int i=0; i<E; i++){
        int x,y,c;
        cin>>x>>y>>c;
        dp[x][y] = min(dp[x][y], c);
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
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(i==j) cout<<0<<" ";
            else {
                if(dp[i][j]==INF) cout<<0<<" ";
                else cout<<dp[i][j]<<" ";
            }
        }
        cout<<endl;
    }

}
