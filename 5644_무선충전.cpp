
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int M, A, N=11, MAX=-1;
struct Bc {
    int c;
    int r;
    int range;
    int weight;
};
int ac=1, ar=1;
int bc=10, br=10;
int map[11][11];
int movingA[101];
int movingB[101];
int moveC[]={0,-1,0,1,0};
int moveR[]={0,0,1,0,-1};
Bc charge[8];
int calcDist(int c, int r, int cc, int rr) {
    return abs(c-cc)+abs(r-rr);
}
bool compareSort(Bc lhs, Bc rhs) {
    return lhs.weight>rhs.weight;
}
void check(int t, int sum) {
    if(t>M) {
        MAX = max(MAX, sum);
        return ;
    }
    ac += moveC[movingA[t]];
    ar += moveR[movingA[t]];
    bc += moveC[movingB[t]];
    br += moveR[movingB[t]];

    int indxA=-1, weightA=0, weightA2=0;
    int indxB=-1, weightB=0, weightB2=0;
    for(int i=0; i<A; i++) {
        //a부터
        if(weightA2 == 0 && charge[i].range >= calcDist(ac,ar,charge[i].c,charge[i].r)) {
            if(weightA==0) {
                indxA = i;
                weightA = charge[i].weight;
            }else {
                weightA2 = charge[i].weight;
            }

        }
        if(weightB2 == 0 && charge[i].range >= calcDist(bc,br,charge[i].c,charge[i].r)) {
            if(weightB==0) {
                indxB = i;
                weightB = charge[i].weight;
            }else {
                weightB2 = charge[i].weight;
            }
        }

    }
    if(indxA >= 0 && indxA == indxB) {

        int tmp = max(weightA+weightB2, weightB+weightA2);
        check(t+1, sum+tmp);
    }else  {

        check(t+1, sum+weightB+weightA);
    }
}

int main() {
    int tc;
    cin>>tc;
    for(int _=1; _<=tc; _++) {
        cin>>M>>A;
        MAX=-1;
        ac=1, ar=1;
        bc=10, br=10;
        for(int i=1; i<=M; i++) {
            cin>>movingA[i];
        }
        for(int i=1; i<=M; i++) {
            cin>>movingB[i];
        }

        for(int i=0; i<A; i++) {
            cin>>charge[i].r>>charge[i].c>>charge[i].range>>charge[i].weight;
        }
        sort(charge, charge+A, compareSort);
        check(0,0);
        cout<<"#"<<_<<" "<<MAX<<endl;
    }

}
