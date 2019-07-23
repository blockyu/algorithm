//
// Created by Yujin Park on 2019-05-24.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

struct Pos {
    Pos(int cc,int rr) {c=cc;r=rr;}
    int c;
    int r;
};
int N,M,MIN=2e9;
vector<Pos> chick;
vector<Pos> house;
int dis(Pos lhs, Pos rhs) {
    return abs(lhs.c-rhs.c) + abs(lhs.r-rhs.r);
}
void check(vector<int> s) {
    int sum=0;
    for(int i=0; i<house.size(); i++) {
        if(sum > MIN) return;
        int minimum=2e9;
        for(int j=0; j<chick.size(); j++) {
            if(s[j]==0) continue;
            minimum = min(minimum, dis(house[i], chick[j]));
        }
        sum += minimum;
    }
   // cout<<"sum="<<sum<<endl;
    MIN=min(MIN, sum);

}
int main() {
    cin>>N>>M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            int d;
            cin>>d;
            if(d==1) house.push_back(Pos(i,j));
            if(d==2) chick.push_back(Pos(i,j));
        }
    }
    vector<int> selector(chick.size());
    for(int i=0; i<M; i++) {
        selector[i]=1;
    }

    do {
       // if(selector[M-1]==0) break;
//        for(int i=0; i<selector.size(); i++) {
//            cout<<selector[i]<<" ";
//        }cout<<endl;
        check(selector);
    }while(prev_permutation(selector.begin(), selector.end()));
    cout<<MIN<<endl;
}
