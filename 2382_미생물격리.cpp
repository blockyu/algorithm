//
// Created by Yujin Park on 2019-02-16.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int map[101][101];
int moveC[5]={0,-1,1,0,0};
int moveR[5]={0,0,0,-1,1};
struct Bug {
    Bug(int cc, int rr, int aamt, int ddir) {
        c=cc; r=rr; amt=aamt; dir=ddir;
    }
    int c;
    int r;
    int amt;
    int dir;
};
int N,K,M;
vector<Bug> vec;

int changDir(int dir) {
    if(dir==1) return 2;
    else if(dir==2) return 1;
    else if(dir==3) return 4;
    else return 3;
}
void startMake() {
    for(int i=0; i<vec.size(); i++) {
        int nextC=vec[i].c+moveC[vec[i].dir];
        int nextR=vec[i].r+moveR[vec[i].dir];
        vec[i].c=nextC;
        vec[i].r=nextR;
        if(nextC==0 || nextR==0 || nextC==N-1 || nextR==N-1) {
            vec[i].amt/=2;
            vec[i].dir=changDir(vec[i].dir);
            if(vec[i].amt==0) {
                vec.erase(vec.begin()+i);
                i--;
            }
        } // 0 제거
        else map[nextC][nextR]=1;

    }
    for(int i=1; i<N-1; i++) {
        for(int j=1; j<N-1; j++) {
            if(map[i][j]==0) continue;
            int maxAmt=0, dir=0, sum=0;
            for(int idx=0; idx<vec.size(); idx++) {
                if(vec[idx].c==i && vec[idx].r==j) {
                    if(vec[idx].amt > maxAmt) {
                        maxAmt=vec[idx].amt;
                        dir=vec[idx].dir;
                    }
                    sum += vec[idx].amt;
                    vec.erase(vec.begin()+idx);
                    idx--;
                }
            }
            vec.push_back(Bug(i,j,sum,dir));
            map[i][j]=0;
        }
    }
}
int main() {
    int tc;
    cin>>tc;
    for(int _=1; _<=tc; _++) {
        cin>>N>>M>>K;
        vec.clear();
        for(int i=0; i<K; i++) {
            int c,r,amt,dir;
            cin>>c>>r>>dir>>amt;
            vec.push_back(Bug(c,r,dir,amt));
        }
        for(int m=1; m<=M; m++) {
            startMake();
        }
        int ans=0;
        for(int i=0; i<vec.size(); i++) {
            if(vec[i].amt==0) continue;
            ans += vec[i].amt;
        }
        cout<<"#"<<_<<" "<<ans<<endl;
    }
}