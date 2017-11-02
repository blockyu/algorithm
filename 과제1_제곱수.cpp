#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int n, arr[1001];
int DP[1001][1001];
long long arr_pow[1001];
bool isZero = true;
void check(int r){
    for(int i=0; i<r; i++) {
        DP[i][r-1] = arr_pow[i] + arr_pow[r-1];
    }
    for(int i=0; i<r; i++){
        for(int j=i+1; j<r; j++) {
            if(arr[r] == DP[i][j]) {
                cout<<arr[r]<<" ";
                isZero = false;
                return;
            }
        }
    }
}
void DPcheck(int r) {
    for(int i=0; i<r; i++) {
        DP[i][r-1] = arr_pow[i] + arr_pow[r-1];
    }
}
int main() {
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    for(int i=0; i<n; i++){
        arr_pow[i] = arr[i]*arr[i];
    }
     for(int i=1; i<n; i++){
        for(int j=1; j<n; j++) {
            DP[i][j] = 2e9;
        }
    }
    for(int i=2; i<n; i++){
        check(i);
        //DPcheck(i);
    }
//    for(int i=0; i<n; i++){
//        for(int j=0; j<n; j++){
//            cout<<DP[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    //if(isZero) cout<<0<<endl;

}
