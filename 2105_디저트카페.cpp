#include <iostream>
#include <algorithm>
using namespace std;
int moveC[4]={1,1,-1,-1};
int moveR[4]={1,-1,-1,1};
bool checkNum[101];
int map[21][21];
int N, Max, sc, sr;
bool checkGo(int cc, int cr) {
    if(cc<0 || cr<0 || cc>=N || cr>=N || cc<sc) return false;
    else if(checkNum[map[cc][cr]]) return false;
    return true;
}
void dfs(int curC, int curR, int cnt, int flag) {
    int nextC, nextR, curN;
    curN=map[curC][curR];
    checkNum[curN]=true;
    if(flag<3) {
        nextC=curC+moveC[flag];
        nextR=curR+moveR[flag];
        if(checkGo(nextC,nextR)) dfs(nextC, nextR, cnt+1, flag);
        nextC=curC+moveC[flag+1];
        nextR=curR+moveR[flag+1];
        if(nextC==sc && nextR==sr) {
            Max = max(Max, cnt);
            checkNum[curN]=false;
            return;
        }
        if(checkGo(nextC,nextR)) dfs(nextC, nextR, cnt+1, flag+1);
    } else {
        nextC=curC+moveC[flag];
        nextR=curR+moveR[flag];
        if(checkGo(nextC,nextR)) dfs(nextC, nextR, cnt+1, flag);
        if(nextC==sc && nextR==sr) {
            Max = max(Max, cnt);
            checkNum[curN]=false;
            return;
        }
    }
    checkNum[curN]=false;

}
int main() {
    int tc;
    cin>>tc;
    for(int _=1; _<=tc; _++) {
        cin>>N;
        Max=-1;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                cin>>map[i][j];
            }
        }
        for(int i=0; i<N-2; i++) {
            for(int j=1; j<N-1; j++) {
                sc=i, sr=j;
                dfs(i,j,1,0);
            }
        }
        cout<<"#"<<_<<" "<<Max<<endl;

    }
}
