#include <iostream>
#include <algorithm>
using namespace std;
int N;
int a[50], b[50];
int comp(int lhs, int rhs) {
    return lhs>rhs;
}
int main() {
    cin>>N;
    for(int i=0; i<N; i++) {
        cin>>a[i];
    }
    for(int i=0; i<N; i++) {
        cin>>b[i];
    }
    sort(a, a+N, comp);
    int tmp[50] = {};
    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {
            if(b[i]>b[j]) tmp[i]++;
            else tmp[j]++;
        }
    }
    int sum=0;
    for(int i=0; i<N; i++) {
        sum += a[tmp[i]]*b[i];
    }
    cout<<sum;
}
