#include <iostream>
#include <algorithm>
using namespace std;
int map[14][21];
int cmap[14][21];
int C,R,MIN,K;
int const A=0;
int const B=1;

bool checkFinish() {
    for(int r=1; r<R; r++) {
        bool isFind=false;
        for(int c=1; c<C-K+1; c++) {
            int cal=0;
            for(int k=0; k<K; k++) {
                cal += map[c+k][r];
            }
            if(cal==0 || cal==K) {
                isFind=true;
                break;
            }
        }
        if(!isFind) return false;
    }
    return true;
}
void changeA(int line) {
    for(int r=1; r<R; r++) {
        map[line][r] = A;
    }
}
void changeB(int line) {
    for(int r=1; r<R; r++) {
        map[line][r] = B;
    }
}
void recovery(int line) {
    for(int r=1; r<R; r++) {
        map[line][r] = cmap[line][r];
    }
}
void dfs(int curC, int cnt) {
    if(curC >= C || cnt > MIN) return ;

    if(checkFinish()) {
        MIN=min(MIN, cnt);
        return ;
    }
    dfs(curC+1, cnt);

    changeA(curC+1);
    dfs(curC+1, cnt+1);
    recovery(curC+1);

    changeB(curC+1);
    dfs(curC+1, cnt+1);
    recovery(curC+1);
}
int main() {
    int tc;
    cin>>tc;
    for(int _=1; _<=tc; _++) {
        cin>>C>>R>>K;
        C++; R++;
        MIN=2e9;
        for(int i=1; i<C; i++) {
            for(int j=1; j<R; j++) {
                cin>>map[i][j];
                cmap[i][j]=map[i][j];
            }
        }
        dfs(0,0);
        cout<<"#"<<_<<" "<<MIN<<endl;
    }
}
