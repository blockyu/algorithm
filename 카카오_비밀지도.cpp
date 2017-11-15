#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int N;
int arr1[16], arr2[16];
void convertBinary(int x) {
    for(int i=N-1; i>-1; i--){
        int tmp = x & (1<<i);
        tmp == 0 ? cout<<"#" : cout<<"1";
    }
    cout<<endl;
}
void convertBinary(int x) {
    for(int i=N-1; i>-1; i--) {
        int tmp =
    }
}
int main() {
    cin>>N;
    for(int i=0; i<N; i++) {
        cin>>arr1[i];
    }
    for(int i=0; i<N; i++) {
        cin>>arr2[i];
    }
    for(int i=0; i<N; i++) {
        convertBinary(arr1[i] | arr2[i]);
    }
}
