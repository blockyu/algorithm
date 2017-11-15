#include <iostream>
#include <algorithm>
using namespace std;
int N;
long long DP[100000];
struct Conf {
    int s;
    int e;
};Conf conf[100000];
bool compareConf(Conf lhs, Conf rhs) {
    if(lhs.s == rhs.s) return lhs.e<rhs.e;
    return lhs.s < rhs.s;
}
long long checkInclude(int cur) {
    int end_ = conf[cur].s;
    long long val = 1;
    for(int i=cur-1; i>-1; i--) {
        if(conf[i].e <= end_) {
            val++;
            end_ = conf[i].s;
        }
    }
    return val;
}
//long long check(int cur) {
//    long long& ret = DP[cur];
//    if(ret > 0) return ret;
//    DP[cur] = max(check(cur-1), checkInclude(cur));
//}
int main() {
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>conf[i].s>>conf[i].e;
    }
    sort(conf, conf+N, compareConf);
    DP[0] = 1;
    //check(N-1);
    long long x = checkInclude(N-1);
    cout<<x;
}
