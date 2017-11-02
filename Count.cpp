#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int arr[] = {2,3,4,5,6,1,2,3,4,53,2,3,2};
    int size_ = sizeof(arr)/sizeof(arr[0]);
    int count_ = count(arr, arr+size_, 2);
    cout<<count_;

}
