#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream ifile;
ofstream ofile;
int n, dp[101], d[101];
struct Work{
    int s,l,w,date;
};
Work works[101];
bool mCompare(Work lhs, Work rhs) { return lhs.l < rhs.l; }
int mFind(int idx) {
    for(int i=idx-1; i>=1; i--){
        if(works[idx].s > works[i].l) {
            d[idx] = works[idx].date + d[i];
            return works[idx].w + dp[i] - 10;
        }
    }
    return 0;
}
void mCheck(int idx){
    if(idx>n) return ;
    int res = 0;
    if(works[idx].s <= works[1].l) {
        if((res = works[idx].w) > dp[idx-1]) {d[idx] = works[idx].date; dp[idx] = res;}
        else if(res == dp[idx-1]) {d[idx] = min(d[idx], d[idx-1]); dp[idx] = res;}
        else {d[idx] = d[idx-1]; dp[idx] = dp[idx-1];}
    } else {
        if((res = mFind(idx)) > dp[idx-1]) {dp[idx] = res;}
        else if(res == dp[idx-1]) {d[idx] = min(d[idx], d[idx-1]); dp[idx] = res;}
        else {d[idx] = d[idx-1]; dp[idx] = dp[idx-1];}
    }
    mCheck(idx+1);
}
int main(){
    ifile.open("freelance.inp");
    ofile.open("freelance.out");
    ifile>>n;
    for(int i=1; i<=n; i++) {
        ifile>>works[i].s>>works[i].l>>works[i].w;
        works[i].date = works[i].l - works[i].s + 1;
    }
    sort(&works[1], &works[1]+n, mCompare);
    for(int i=1; i<=n; i++) {
        cout<<works[i].s<<" "<<works[i].l<<" "<<works[i].w<<endl;
    }
    dp[1]=works[1].w;
    d[1] = works[1].date;
    mCheck(2);
    ofile<<dp[n]<<" "<<d[n]<<endl;
}
