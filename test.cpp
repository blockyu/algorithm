#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    // 0 + arr[] 의 모든 원소
    cout<<"accumulate 예시 1 : "<<accumulate(arr, arr+size, 0)<<endl;
    // 1 * arr[] 의 모든 원소
    cout<<"accumulate 예시 2 : "<<accumulate(arr, arr+size, 1, multiplies<int>())<<endl;

    vector<int> v = {1,2,3,4,5,6};
    int carr[10];
    // deep copy , 하지만 vector 에서 array로는 복사 불가능
    copy(arr, arr+size, carr);

    for(int i=0; i<size; i++) {
        cout<<carr[i]<<" ";
    }cout<<endl;

    // value의 개수를 세어준다
    int count_ = count(arr, arr+size, 2);
    cout<<count_<<endl;

    // value로 초기화 시켜준다.
    fill(arr, arr+size, 0);

     for(int i=0; i<size; i++) {
        cout<<arr[i]<<" ";
    }cout<<endl;
}
