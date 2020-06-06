//
// Created by Yujin Park on 2019-09-07.
//

#include <string>
#include <vector>
using namespace std;
vector<vector<int>> board_cp;
bool arr[1001][1001];
int const R=0, D=1, L=2, U=3;
int SIZE, MIN=2e9;
bool isWall(int c, int r) {
    if(c<0 || r<0 || c>=SIZE || r>=SIZE) return true;
    if(board_cp[c][r] == 1) return true;
    return false;
}
void check(int cc, int cr, int dir, int sum) {
    if(cc==SIZE-1 && cr==SIZE-1) {
        MIN=min(MIN, sum);
        return;
    }
    if(dir==R) {
        // ->
        if(!isWall(cc, cr+1)) {
            arr[cc][cr+1]=true;
            check(cc, cr+1, R, sum+1);
            arr[cc][cr+1]=false;
        }
        // U
        if(!isWall(cc-1, cr+1) && !isWall(cc-1, cr)){
            arr[cc-1][cr]=true;
            check(cc-1,cr, U, sum+1);
            arr[cc-1][cr]=false;
        }
        // D
        if(!isWall(cc+1, cr+1) && !isWall(cc+1, cr)) {
            arr[cc+1][cr]=true;
            check(cc+1, cr, D, sum+1);
            arr[cc+1][cr]=false;
        }
    }
    if(dir==D) {
        // D
        if(!isWall(cc+1, cr)) {
            arr[cc+1][cr]=true;
            check(cc+1, cr, D, sum+1);
            arr[cc+1][cr]=false;
        }
        // -> R
        if(!isWall(cc+1, cr+1) && !isWall(cc, cr+1)) {
            arr[cc][cr+1]=true;
            check(cc, cr+1, R, sum+1);
            arr[cc][cr+1]=false;
        }
        // <- L
        if(!isWall(cc+1, cr-1) && !isWall(cc, cr-1)) {
            arr[cc][cr-1]=true;
            check(cc, cr-1, L, sum+1);
            arr[cc][cr-1]=false;
        }
    }
    if(dir==L) {
        // L
        if(!isWall(cc, cr-1)) {
            arr[cc][cr-1]=true;
            check(cc, cr-1, L, sum+1);
            arr[cc][cr-1]=false;
        }
        // D
        if(!isWall(cc+1, cr-1) && !isWall(cc+1, cr)) {
            arr[cc+1][cr]=true;
            check(cc+1, cr, D, sum+1);
            arr[cc+1][cr]=false;
        }
        // U
        if(!isWall(cc-1, cr-1) && !isWall(cc-1, cr)) {
            arr[cc-1][cr]=true;
            check(cc-1, cr, U, sum+1);
            arr[cc-1][cr]=false;
        }
    }
    if(dir==U) {
        // U
        if(!isWall(cc-1, cr)) {
            arr[cc-1][cr]=true;
            check(cc-1, cr, U, sum+1);
            arr[cc-1][cr]=false;
        }
        // L
        if(!isWall(cc-1, cr-1) && !isWall(cc, cr-1)) {
            arr[cc][cr-1]=true;
            check(cc, cr-1, L, sum+1);
            arr[cc][cr-1]=false;
        }
        // R
        if(!isWall(cc-1, cr+1) && !isWall(cc, cr+1)) {
            arr[cc][cr+1]=true;
            check(cc, cr+1, R, sum+1);
            arr[cc][cr+1]=false;
        }
    }

}
int solution(vector<vector<int>> board) {
    int answer = 0;
    board_cp = board;
    SIZE = board[0].size();
    for(int i=0; i<board.size(); i++) {
        for(int j=0; j<board[i].size(); j++) {
            if(board[i][j] == 1) arr[i][j]=true;
        }
    }
    check(0,1,R,0);
    answer = MIN;

    return answer;
}
