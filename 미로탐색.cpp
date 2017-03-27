#include <iostream>
using namespace std;
int N,M;
char arr[101][101];
bool isVisited[101][101];
int DP[101][101];
int min(int a, int b, int c, int d){
    return min(a,min(b,min(c,d)));
}
int findDes(int x, int y) {
    if(x < 1 || y < 1 || x > N || y > M) return 0;
    if(x == N && y == M) return 1;

    int &ret = DP[x][y];
    if(ret != 2e9) return ret;

    int up,right,down,left;
    up=right=down=left=2e9;

    if(arr[x-1][y]=='1' && !isVisited[x-1][y]) {
        isVisited[x-1][y] = true;
        up = findDes(x-1, y);
        isVisited[x-1][y] = false;
    }
    if(arr[x][y+1]=='1' && !isVisited[x][y+1]) {
        isVisited[x][y+1] = true;
        right = findDes(x, y+1);
        isVisited[x][y+1] = false;
    }
    if(arr[x+1][y]=='1' && !isVisited[x+1][y]) {
        isVisited[x+1][y] = true;
        down = findDes(x+1, y);
        isVisited[x+1][y] = false;
    }
    if(arr[x][y-1]=='1' && !isVisited[x][y-1]) {
        isVisited[x][y-1] = true;
        left = findDes(x, y-1);
        isVisited[x][y-1] = false;
    }
    return ret = min(up, right, down, left) + 1;
}
int main() {
    cin>>N>>M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++) {
            cin>>arr[i][j];
        }
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++) {
            DP[i][j] = 2e9;
        }
    }
    isVisited[1][1] = true;
    cout<<findDes(1,1);
}
