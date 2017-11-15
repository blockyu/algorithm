#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int N;
int arr[41], dp0[41], dp1[41];
void fib(int n) {
    if(n==0) return ;
    else if(n==1) return ;
    if(dp0[n] > 0) return ;
    else {
        fib(n-1);
        dp0[n] = dp0[n-1] + dp0[n-2];
        dp1[n] = dp1[n-1] + dp1[n-2];
    }
}
int main() {
    cin>>N;
    dp0[0] = 1; dp1[0] = 0;
    dp0[1] = 0; dp1[1] = 1;
    for(int i=0; i<N; i++) {
        int x;
        cin>>x;
        fib(x);
        cout<<dp0[x]<<" "<<dp1[x]<<endl;
    }
}

