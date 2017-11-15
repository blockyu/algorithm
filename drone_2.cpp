#include <iostream>
#include <fstream>
#include <algorithm>
#include <stack>
#include <cmath>
using namespace std;
int N;
int DP[13][1<<12][130];
struct Pos {
    int w;
    int x;
    int y;
};
Pos pos[13];
ifstream ifile;
ofstream ofile;
int dist(int lhs, int rhs) {
    return abs(pos[lhs].x - pos[rhs].x) + abs(pos[lhs].y - pos[rhs].y);
}
int check(int cur, int vis, int weight) {
    if(vis & ((1<<13)-1)) == 1)
        return dist(cur, 1);
    int& ret = DP[cur][vis]
    for(int i=1; i<=N; i++) {

    }
}
int main() {
    ifile.open("drone.inp");
    ofile.open("drone.out");
    ifile>>N;
    for(int i=1; i<=N; i++) {
        int idx;
        ifile>>idx;
        ifile>>pos[idx].w>>pos[idx].x>>pos[idx].y;
    }

}
