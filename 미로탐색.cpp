#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int C,R;
queue<pair <int,int> > myqueue;
char arr[101][101];
bool vis[101][101];
int DP[101][101];
int moveR[] = {1,0,-1,0};
int moveC[] = {0,1,0,-1};
void check(pair<int,int> p) {
    myqueue.push(p);
    vis[p.first][p.second]=true;
    DP[1][1] = 1;
    while(!myqueue.empty()) {
        pair<int,int> cur = myqueue.front();
        myqueue.pop();
        int c = cur.first;
        int r = cur.second;
        for(int i=0; i<4; i++) {
            int nextC = c+moveC[i];
            int nextR = r+moveR[i];
            if(nextC<1 || nextC>C || nextR<1 || nextR>R) continue;
            if(arr[nextC][nextR]>0 && !vis[nextC][nextR]) {
                DP[nextC][nextR]=min(DP[nextC][nextR], DP[c][r]+1);
                vis[nextC][nextR]=true;
                myqueue.push(make_pair(nextC,nextR));
            }
        }
    }
}
int main() {
    cin>>C>>R;
    for(int i=1; i<=C; i++){
        for(int j=1; j<=R; j++) {
            cin>>arr[i][j];
            arr[i][j] -= '0';
        }
    }
    for(int i=1; i<=C; i++){
        for(int j=1; j<=R; j++) {
            DP[i][j] = 2e9;
        }
    }
    fill(&DP[0][0], &DP[C][R]+1, 2e9);
    check(make_pair(1,1));
    cout<<DP[C][R];

}
