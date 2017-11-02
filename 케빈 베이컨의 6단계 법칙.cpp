#include <iostream>
#include <algorithm>
using namespace std;
int N, E;
int dp[101][101];
const int INF = 2e7;
int main(){
    cin>>N>>E;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            dp[i][j] = INF;
        }
    }
    for(int i=0; i<E; i++){
        int x,y;
        cin>>x>>y;
        dp[x][y] = dp[y][x] = 1;
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
    int msum = INF, res = 0;
    for(int i=1; i<=N; i++) {
        int sum=0;
        for(int j=1; j<=N; j++){
            if(i==j) continue;
            sum += dp[i][j];
        }
        if(sum < msum) {
            msum = sum;
            res = i;
        }
    }
    cout<<res;
}
