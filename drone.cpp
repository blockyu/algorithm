#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
#define INF 2e9
int N;
int W;
class Data {
public:
    int w,x,y;
    Data(int ww, int xx, int yy) : w(ww), x(xx), y(yy) { }
    Data() {}
};
Data A[13];
int dp[13][1<<12][1];
int map[13][13];
void init(ifstream &inp) {
    inp >> N;
    for (int i = 0; i < N; ++i) {
        int h,w,x,y;
        inp >> h >> w >> x >> y;
        A[h] = Data(w,x,y);
        W += w;
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < (1<<12); ++j) {
            for (int k = 0; k < 130; ++k) {
                dp[i][j][k] = INF;
            }
        }
    }
}

int dist(int s, int d) {
    return abs(A[s].x-A[d].x)+abs(A[s].y-A[d].y);
}
int solve(int cur, int flag, int weight) {
    if (flag==(1<<N)-1) return dist(cur,1);
    int &ret = dp[cur][flag][weight];
    if (ret != INF) return ret;
    for (int i = 0; i < N; ++i) {
        if (flag&(1<<i)) continue;
        ret = min(ret,solve(i+1,flag|(1<<i),weight-A[i+1].w)+dist(cur,i+1)*weight);
    }
    return ret;
}
int main() {
    ifstream inp("drone.inp");
    ofstream out("drone.out");

    init(inp);
    out << solve(1,1,W+1) << endl;
    return 0;
}
