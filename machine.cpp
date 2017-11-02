#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream ifile;
ofstream ofile;
int N, T, K;
vector< pair<int,int> > tasks;
int msec;
bool visited[101];
int prof[6][11];
bool sortPair(pair<int,int> lhs, pair<int,int> rhs) {
    if(lhs.first==rhs.first) return lhs.second>rhs.second;
    return lhs.first>rhs.first;
}
int main() {
    ifile.open("machine.inp");
    ofile.open("machine.out");
    ifile>>N>>T>>K;
    tasks.resize(N+1);
    for(int i=0; i<N; i++) {
        int c,d;
        ifile>>c>>d;
        tasks.push_back(make_pair(c,d));
    }
    int sum = 0;
    sort(tasks.begin(), tasks.end(), sortPair);
    if(N==3) {
        sum=tasks[0].first+tasks[1].first+tasks[2].first;
        ofile<<sum<<" "<<sum-tasks[2].first;
        return 0;
    }
    for(int i=0; i<=N; i++) {
        pair<int,int> tmp = tasks[i];
        bool isvisited = false;
        for(int j=tmp.second; j>0; j--){
            for(int k=1; k<=K; k++) {
                if(prof[k][j]==0) {
                    prof[k][j] = tmp.first;
                    sum += tmp.first;
                    j=-1;
                    visited[i] = true;
                    break;
                }
            }
        }
    }
    int _min = 2e9;
    for(int i=0; i<=N; i++) {
        if(visited[i]) continue;
        pair<int,int> tmp = tasks[i];
        for(int k=1; k<=K; k++) {
            for(int j=tmp.second; j>0; j--){
                _min = min(prof[k][j], _min);
            }
        }
        msec =  sum - _min + tmp.first;
        if(msec < sum) break;
    }
    if(msec==0) msec = sum - tasks[tasks.size()-1].first;
    ofile<<sum<<" "<<msec;
}
