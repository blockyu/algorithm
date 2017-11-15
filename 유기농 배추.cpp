#include <iostream>
#include <algorithm>
using namespace std;
int N;
int ROW,COL,K, res;
int arr[51][51];
bool vis[51][51];
int moveR[] = {1,0,-1,0};
int moveC[] = {0,1,0,-1};
void check(int c, int r) {
    if(r==ROW || c==COL) return ;
    vis[c][r]=true;
    for(int i=0; i<4; i++) {
        int nextC=c+moveC[i];
        int nextR=r+moveR[i];
        if(nextC<0 || nextC==COL) continue;
        if(nextR<0 || nextR==ROW) continue;
        if(arr[nextC][nextR]>0 && !vis[nextC][nextR]) {
            check(nextC, nextR);
        }
    }

}
int main() {
    cin>>N;
    for(int i=0; i<N; i++) {
        cin>>ROW>>COL>>K;
        for(int j=0; j<K; j++) {
            int r, c;
            cin>>r>>c;
            arr[c][r] = 1;
        }
        for(int c=0; c<COL; c++) {
            for(int r=0; r<ROW; r++) {
                if(arr[c][r]>0 && !vis[c][r]) {
                    check(c,r);
                    res++;
                }
            }
        }
        cout<<res<<endl;
        res=0;
        fill(&arr[0][0], &arr[COL][ROW], 0);
        fill(&vis[0][0], &vis[COL][ROW], false);
    }
}
