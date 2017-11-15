#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n, rex,rey;
int pos;
int main(){
    cin>>n>>rex>>rey;
    int N=pow(2,n);
    rex++; rey++;
    while(N>0) {
        int val = (N/2)*(N/2);
        if(rex>(N/2) && rey>(N/2)){
            pos += val*3;
            rex -= (N/2);
            rey -= (N/2);
        }
        else if(rex>(N/2)) {
            pos += val*2;
            rex -= (N/2);
        }else if(rey>(N/2)) {
            pos += val;
            rey -= (N/2);
        }
        N /= 2;
    }
    cout<<pos;
}
