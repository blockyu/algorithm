#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int N;
int SUM=-1;
struct Element{
    int c;
    int r;
    int dir;
    int weight;
};
int map[4001][4001];
Element element[1000];
queue<Element> qu;
int moveC[]={1,-1,0,0};
int moveR[]={0,0,-1,1};
bool exceedRange(int c, int r) {
    if(c<0 || c>4000 || r<0 || r>4000) return true;
    return false;
}
void check() {
    for(int t=0; t<4001; t++) {
        int qsize = qu.size();
        for(int i=0; i<qsize; i++) {
            auto cur = qu.front();
            qu.pop();
            if(map[cur.c][cur.r]>cur.weight) {
                SUM += cur.weight;
                map[cur.c][cur.r]=0;
                continue;
            }
            map[cur.c][cur.r]=0;
            int nextC = cur.c + moveC[cur.dir];
            int nextR = cur.r + moveR[cur.dir];
            if(exceedRange(nextC, nextR)) continue;
            if(map[nextC][nextR]>0) {
                SUM += cur.weight;
                map[nextC][nextR]+=cur.weight;
            }else {
                map[nextC][nextR]=cur.weight;
                qu.push(Element{nextC,nextR,cur.dir,cur.weight});
            }
        }


    }
}
int main() {
    int tc;
    cin>>tc;
    for(int _=1; _<=tc; _++) {
        SUM=0;
        while(!qu.empty()) qu.pop();
        cin>>N;
        for(int i=0; i<N; i++) {
            int c, r, d, w;
            cin>>r>>c>>d>>w;
            map[c*2+2000][r*2+2000]=w;
            qu.push(Element{c*2+2000, r*2+2000, d, w});
        }
        check();
        cout<<"#"<<_<<" "<<SUM<<endl;
    }
}