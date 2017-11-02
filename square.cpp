#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;
int n;
long long arr[1001];
bool isZero = true;
ifstream ifile;
ofstream ofile;
void init(int &s,int &l,int idx) {
    s = 0;
    l = idx-1;
}
void check(){
    int s = 0;
    int l = n-1;
    for(int i=1; i<n;){
        long long tmp = arr[s]*arr[s] + arr[l]*arr[l];
        if(arr[i] == tmp) {
            ofile<<arr[i]<<" ";
            isZero = false;
            init(s,l,i+1);
            i++;
        }
        else if(arr[i] < tmp) {
            l = l-1;
        }else if(arr[i] > tmp) {
            s = s+1;
        }
        if(s==l) {
            init(s,l,i+1);
            i++;
        }
    }

}
int main() {
    ifile.open("square.inp");
    ofile.open("square.out");
    ifile>>n;
    for(int i=0; i<n; i++){
        ifile>>arr[i];
    }
    sort(arr, arr+n);
    check();
    if(isZero) ofile<<0<<endl;

}
