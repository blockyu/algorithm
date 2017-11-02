#include <iostream>
#include <algorithm>
using namespace std;
int N;
long long arr[100002];
int check(int idxl, int idxr, int N) {
    if(idxl == idxr) return arr[idxl];
    long long _left = check(idxl, (idxl+idxr)/2, N/2);
    long long _mid = min(arr[(idxl+idxr)/2], arr[(idxl+idxr)/2+1])*(idxr-idxl);
    long long _right = check((idxl+idxr)/2+1, idxr, N/2);
    cout<<"left "<<_left<<"  mid "<<_mid<<"  right"<<_right<<endl;
    return max(_mid,max(_left,_right));
}
int main(){
    while(1) {
        cin>>N;
        if(N==0) break;
        fill(arr,arr+N+1,0);
        for(int i=0; i<N; i++){
            cin>>arr[i];
        }
        int res;
        if(N%2!=0) {
            arr[N]=0;
            res = check(0,N,N+1);
        }else {
            res = check(0,N-1,N);
        }
        cout<<res<<endl;
    }
    return 0;
}
