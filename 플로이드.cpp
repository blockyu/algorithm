#include <iostream>
using namespace std;
int v,e;
int w[101][101];
int d[101];
bool isVisited[101];
void init() {
    for(int i=1; i<=v; i++) {
        d[i] = 2e9;
        isVisited[i] = false;
    }
}
void findMin(int cur) {
    isVisited[cur] = true;
    int des;
    for(int des=1; des<=v; des++) {
        if(d[des] > d[cur]+w[cur][des]) {
            d[des] = d[cur]+w[cur][des];
        }
    }
    for(int des=1; des<=v; des++) {
        if(!isVisited[des] && w[cur][des] < 100001) {
            findMin(des);
        }
    }
}
int main(){
    cin>>v>>e;
    for(int i=1; i<=v; i++) {
        for(int j=1; j<=v; j++) {
            w[i][j] = 100001;
        }
    }
    for(int j=1; j<=e; j++) {
        int a,b,c;
        cin>>a>>b>>c;
        w[a][b] = min(w[a][b], c);
    }
    for(int i=1; i<=v; i++) {
        init();
        d[i] = 0;
        findMin(i);
        for(int j=1; j<=v; j++) {
            cout<<d[j]<<" ";
        }
        cout<<endl;
    }
}
