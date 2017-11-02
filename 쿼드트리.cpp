#include <iostream>
#include <algorithm>
using namespace std;
int N;
char arr[65][65];
void check(int x, int y, int N) {
    int sum = 0;
    for(int i=x; i<x+N; i++) {
        for(int j=y; j<y+N; j++) {
            sum += arr[i][j]-'0';
        }
    }
    if(sum == 0) { cout<<"0"; }
    else if(sum == N*N) { cout<<"1"; }
    else {
        cout<<"(";
        check(x,y,N/2);
        check(x,y+N/2,N/2);
        check(x+N/2,y,N/2);
        check(x+N/2,y+N/2,N/2);
        cout<<")";
    }
}
int main(){
    cin>>N;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cin>>arr[i][j];
        }
    }
    check(1,1,N);
}
