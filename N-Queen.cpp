#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int N, cnt=0;
int col[16];
bool checkSafe(int next) {
    for(int i=1; i<next; i++) {
        if(col[i] == col[next]) { //같은 열인지 확인
            return false;
        }else if(abs(col[i]-col[next])==abs(i-next)) { // 대각선 확인
            return false;
        }
    }
    return true;
}
void check(int curRow) {
    if(curRow == N) {
        cnt++;
        return ;
    }
    for(int i=1; i<=N; i++) {
        col[curRow+1] = i;
        if(checkSafe(curRow+1)) {
            check(curRow+1);
            col[curRow+1] = 0;
        }
    }

}
int main() {
    cin>>N;
    for(int i=1; i<=N; i++) {
        col[1] = i;
        check(1);
        fill(col, col+N+1, 0);
    }
    cout<<cnt;
}
