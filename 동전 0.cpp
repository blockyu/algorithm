#include <iostream>
#include <algorithm>
using namespace std;
int N, K;
int arr[10];
int main() {
    cin>>N>>K;
    for(int i=N-1; i>-1; i--) {
        cin>>arr[i];
    }
    int cnt=0, idx=0;
    while(K>0) {
        if(arr[idx] > K) idx++;
        else {
            K -= arr[idx];
            cnt++;
        }
    }
    cout<<cnt;
}
