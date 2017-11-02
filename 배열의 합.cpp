#include <iostream>
#include <algorithm>
using namespace std;
int N,M;
int arr[301][301], DP[301][301], t;
int msum(int a1, int a2, int b1, int b2) {
    return DP[b1][b2]-DP[a1][a2-1];
}
int main(){
    cin>>N>>M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin>>arr[i][j];
        }
    }

    cout << *(*(arr+1)) << endl;
    cin>>t;
    DP[1][1] = arr[1][1];
    for(int i=1; i<=N*M; i++){
       cout<<(*(DP+i));
    }
    for(int i=0; i<t; i++){
        int s1,s2,l1,l2;
        cin>>s1>>s2>>l1>>l2;
        cout<<msum(s1,s2,l1,l2)<<endl;
    }
}
