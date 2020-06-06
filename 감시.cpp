//
// Created by Yujin Park on 2019-07-31.
//
#include <iostream>
#include <vector>
using namespace std;
int map[9][9];
int cmap[9][9];
int CC,RR;
int MIN=2e9;
struct Pos {
    Pos(int cc, int rr, int ttype){
        c=cc; r=rr; type=ttype;
    }
    int c, r, type;
};
vector<Pos> vec;

void cpArr() {
    for(int i=1; i<=CC; i++) {
        for(int j=1; j<=RR; j++) {
            cmap[i][j] = map[i][j];
        }
    }
}

void rcArr() {
    for(int i=1; i<=CC; i++) {
        for(int j=1; j<=RR; j++) {
            map[i][j] = cmap[i][j];
        }
    }
}
void fillUp(int cc, int cr) {
    for(int c=cc-1; c>0; c--) {
        if(map[c][cr]==6) return;
        if(map[c][cr]>0 && map[c][cr]<6) continue;
        map[c][cr]=-1;
    }
}
void fillRight(int cc, int cr) {
    for(int r=cr+1; r<=RR; r++) {
        if(map[cc][r]==6) return;
        if(map[cc][r]>0 && map[cc][r]<6) continue;
        map[cc][r]=-1;
    }
}
void fillDown(int cc, int cr) {
    for(int c=cc+1; c<=CC; c++) {
        if(map[c][cr]==6) return;
        if(map[c][cr]>0 && map[c][cr]<6) continue;
        map[c][cr]=-1;
    }
}
void fillLeft(int cc, int cr) {
    for(int r=cr-1; r>0; r--) {
        if(map[cc][r]==6) return;
        if(map[cc][r]>0 && map[cc][r]<6) continue;
        map[cc][r]=-1;
    }
}
// 1 ->

// 2 <- ->

// 3 | ->

// 4 <- | ->

// 5 all
void prtArr() {
    cout<<endl;
    for(int i=1; i<=CC; i++) {
        for(int j=1; j<=RR; j++) {
            cout<<map[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;
}
void checkArr() {
    int cnt=0;
    for(int i=1; i<=CC; i++) {
        for(int j=1; j<=RR; j++) {
            if(map[i][j]==0) cnt++;
            if(cnt>MIN) return;
        }
    }
    MIN=min(MIN,cnt);
    prtArr();
}
const int U=1;
const int R=2;
const int D=3;
const int L=4;
void dfs(int cur, int dir) {
    if(cur>=vec.size()) {
        checkArr();
        return ;
    }
    int cc =vec[cur].c;
    int cr=vec[cur].r;
    int ctype=vec[cur].type;
    if(dir == U) { // up
        //dfs(cur+1, U);
        //cpArr();
        if(ctype == 1) {
            fillUp(cc, cr);
            //dfs(cur, R);
        } else if (ctype == 2) {
            fillLeft(cc, cr);
            fillRight(cc, cr);
            //dfs(cur, R);
        } else if (ctype == 3) {
            fillUp(cc,cr);
            fillRight(cc,cr);
            //dfs(cur, R);
        } else if (ctype == 4) {
            fillLeft(cc, cr);
            fillUp(cc,cr);
            fillRight(cc,cr);
            //dfs(cur, R);
        } else {
            fillUp(cc,cr);
            fillRight(cc,cr);
            fillDown(cc, cr);
            fillLeft(cc, cr);
            //dfs(cur, R);
        }
        //rcArr();
    } else if(dir == R) { // right
        //dfs(cur+1, U);
        //cpArr();
        if(ctype == 1) {
            fillRight(cc, cr);
            //dfs(cur, D);
        } else if (ctype == 2) {
            fillUp(cc, cr);
            fillDown(cc, cr);
            //dfs(cur, D);
        } else if (ctype == 3) {
            fillRight(cc,cr);
            fillDown(cc,cr);
            //dfs(cur, D);
        } else if (ctype == 4) {
            fillUp(cc, cr);
            fillRight(cc,cr);
            fillDown(cc,cr);
            //dfs(cur, D);
        } else {
            fillUp(cc,cr);
            fillRight(cc,cr);
            fillDown(cc, cr);
            fillLeft(cc, cr);
            //dfs(cur, D);
        }
        rcArr();
    } else if(dir == D) { //  down
        //dfs(cur+1, U);
        //cpArr();
        if(ctype == 1) {
            fillDown(cc, cr);
            //dfs(cur, L);
        } else if (ctype == 2) {
            fillLeft(cc, cr);
            fillRight(cc, cr);
            //dfs(cur, L);
        } else if (ctype == 3) {
            fillDown(cc,cr);
            fillLeft(cc,cr);
            //dfs(cur, L);
        } else if (ctype == 4) {
            fillRight(cc, cr);
            fillDown(cc,cr);
            fillLeft(cc,cr);
            //dfs(cur, L);
        } else {
            fillUp(cc,cr);
            fillRight(cc,cr);
            fillDown(cc, cr);
            fillLeft(cc, cr);
            //dfs(cur, L);
        }
        //rcArr();
    } else  { // left
        //dfs(cur+1, U);
        //cpArr();
        if(ctype == 1) {
            fillLeft(cc, cr);
        } else if (ctype == 2) {
            fillUp(cc, cr);
            fillDown(cc, cr);
        } else if (ctype == 3) {
            fillLeft(cc,cr);
            fillUp(cc,cr);
        } else if (ctype == 4) {
            fillDown(cc, cr);
            fillLeft(cc,cr);
            fillUp(cc,cr);
        } else {
            fillUp(cc,cr);
            fillRight(cc,cr);
            fillDown(cc, cr);
            fillLeft(cc, cr);
        }
        // TODO validation
        //checkArr();
        //rcArr();
    }
    for(int i=1; i<=4; i++) {
        cpArr();
        dfs(cur+1, i);
        rcArr();
    }
}
int main() {
    cin>>CC>>RR;
    for(int i=1; i<=CC; i++) {
        for(int j=1; j<=RR; j++) {
            int v;
            cin>>v;
            map[i][j] = cmap[i][j] = v;
            if(v==0 || v==6) continue;
            vec.push_back(Pos(i,j,v));
        }
    }
    for(int i=1; i<=4; i++) {
        cpArr();
        dfs(0, i);
        rcArr();
    }
    cout<<MIN<<endl;
}
