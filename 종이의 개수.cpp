#include <iostream>
#include <algorithm>
using namespace std;
int N, tzero, tone, tmone;
int arr[2200][2200];
int check(int x, int y, int N) {
    int checking = arr[x][y];
    for(int i=x; i<x+N; i++){
        for(int j=y; j<y+N; j++) {
            if(checking != arr[i][j]) {
                checking = -2;
                break;
            }
        }
    }
    if(checking==0) tzero++;
    else if(checking==1) tone++;
    else if(checking==-1) tmone++;
    else {
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                check(x+((N/3)*i), y+((N/3)*j), N/3);
            }
        }
    }
}
int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) {
            cin>>arr[i][j];
        }
    }
    check(0,0,N);
    cout<<tmone<<endl<<tzero<<endl<<tone<<endl;
}
