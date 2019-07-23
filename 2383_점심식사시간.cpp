//
// Created by Yujin Park on 2019-02-17.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
vector< pair<int,int> > vec;
queue<int> moveToStairA, moveToStairB, onTheStairA, onTheStairB, goDownStairA, goDownStairB;;
int N,P,K;
int fc,fr,sc,sr;
int checkTime() {
    int t;
    for(t=1; t<1000000; t++) {
        //check go Down Stair A
        int gdsASize = goDownStairA.size();
        for(int i=0; i<gdsASize; i++) {
            int cur = goDownStairA.front()-1;
            goDownStairA.pop();
            if(cur>0) goDownStairA.push(cur);
        }
        int gdsBSize = goDownStairB.size();
        for(int i=0; i<gdsBSize; i++) {
            int cur = goDownStairB.front()-1;
            goDownStairB.pop();
            if(cur>0) goDownStairB.push(cur);
        }
        //check on stair A
        int otsASize = onTheStairA.size();
        for(int i=0; i<otsASize; i++) {
            int cur = onTheStairA.front()-1;
            onTheStairA.pop();
            if(cur<=0 && goDownStairA.size()<3) goDownStairA.push(3);
            else onTheStairA.push(cur);
        }
        //check on stair B
        int otsBSize = onTheStairB.size();
        for(int i=0; i<otsBSize; i++) {
            int cur = onTheStairB.front()-1;
            onTheStairB.pop();
            if(cur<=0 && goDownStairB.size()<3) goDownStairB.push(3);
            else onTheStairB.push(cur);
        }
        //moveStair A
        int mtsASize = moveToStairA.size();
        for(int i=0; i<mtsASize; i++) {
            int cur = moveToStairA.front()-1;
            moveToStairA.pop();
            if(cur==0) onTheStairA.push(1);
            else moveToStairA.push(cur);
        }
        //moveStair B
        int mtsBSize = moveToStairB.size();
        for(int i=0; i<mtsBSize; i++) {
            int cur = moveToStairB.front()-1;
            moveToStairB.pop();
            if(cur==0) onTheStairB.push(1);
            else moveToStairB.push(cur);
        }


        if(moveToStairA.size() + moveToStairB.size()
        + onTheStairA.size() + onTheStairB.size()
        + goDownStairA.size() + goDownStairB.size() == 0) return t;
    }
}
int main() {
    int tc;
    cin>>tc;
    for(int _=1; _<=tc; _++) {
        cin>>N;
        fc=-1,fr=-1,sc=-1,sr=-1;
        P=0;
        vec.clear();
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                int tmp;
                cin>>tmp;
                if(tmp==1) {
                    vec.push_back(make_pair(i,j));
                    P++;
                }
                else if(tmp>1) {
                    if(fc+fr < 0) {
                        fc=i, fr=j;
                    }else {
                        sc=i, sr=j;
                    }
                }
            }
        }
        vector<int> selector(P*2);
        for(int i=P; i<(2*P); i++) {
            selector[i]=1;
        }
        int ans=2e9;
        do {
            //if(selector[P-1]==1) break;
            //while(!moveToStairA.empty()) moveToStairA.pop();
            //while(!moveToStairB.empty()) moveToStairB.pop();
            for(int i=0; i<P; i++) {
                if(selector[i]==0) moveToStairA.push(abs(fc-vec[i].first)+abs(fr-vec[i].second));
                else moveToStairB.push(abs(sc-vec[i].first)+abs(sr-vec[i].second));
            }
            ans = min(ans,checkTime());
        }while(next_permutation(selector.begin(), selector.end()));
        cout<<"#"<<_<<" "<<ans<<endl;
    }

}
