#include <iostream>
#include <algorithm>
using namespace std;
int binarySearch(int arr[], int x, int size) {
    int left = 0, right = size-1;
    int middle;
    while(left <= right) {
        middle = (left + right)/2;
        if(x > arr[middle]) {
            left = middle + 1;
        }else if(x < arr[middle]) {
            right = middle - 1;
        }else {
            return middle;
        }
    }
    return -1;

}
int main(){
    int arr[] = {1,3,2,5,4,8,9};
    sort(arr, arr+sizeof(arr)/sizeof(arr[0]));
    cout<<binarySearch(arr, 3, sizeof(arr)/sizeof(arr[0]));
}
