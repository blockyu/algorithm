//
// Created by Yujin Park on 2019-02-15.
//

#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int map[21][21];
int fee[22];
bool checkRange(int cc, int cr) {
    return !(cc < 0 || cr < 0 || cc >= N || cr >= N);
}
int checkPos(int sc, int sr, int k) {
    int cnt=0;
    int iter ;
    int rStartUp ;
    for(int i=1; i<k; i++) {
        int upEdge = sc-k+i;
        int downEdge = sc+k-i;
        iter = i*2-1;
        rStartUp = sr-(iter/2);

        for(int j=0; j<iter; j++) {
            if(checkRange(upEdge, rStartUp+j)) {
                if (map[upEdge][rStartUp + j] == 1) cnt++;
            }
            if(checkRange(downEdge, rStartUp+j)) {
                if (map[downEdge][rStartUp + j] == 1) cnt++;
            }
        }
    }
    iter = 2*k -1;
    rStartUp = sr-(iter/2);
    for(int j=0; j<iter; j++) {
        if(checkRange(sc, rStartUp + j)) {
            if (map[sc][rStartUp + j] == 1) cnt++;
        }
    }
    if(cnt*M-fee[k] >= 0) {
        return cnt;
    }
    else return 0;
}
int main() {
    int tc;
    cin>>tc;
    for(int _=1; _<=tc; _++) {
        cin>>N>>M;
        for(int i=0; i<N; i++) {
          for(int j=0; j<N; j++) {
              cin>>map[i][j];
          }
        }
        for(int i=1; i<=N+1; i++) {
            fee[i]=i*i + (i-1)*(i-1);
        }
        int ans = 0;
        for(int k=1; k<=N+1; k++) {
            for(int i=0; i<N; i++) {
                for(int j=0; j<N; j++) {
                    ans=max(ans,checkPos(i,j,k));
                }
            }
        }
        cout<<"#"<<_<<" "<<ans<<endl;
    }
}