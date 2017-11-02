#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
char arr[100] = {'a','b','c','d','e','f'};
int arrSize;
bool isVisited[100];
void permutation(int cur, vector<char> v) {
    if(v.size() == arrSize) {
            for(int i=0; i<v.size(); i++) {
                cout<<v[i]<<" ";
            }
            cout<<endl;
            return;
    }
    for(int i=0; i<arrSize; i++){
        if(!isVisited[i]) {
            isVisited[i] = true;
            v.push_back(arr[i]);
            permutation(i, v);
            isVisited[i] = false;
            v.pop_back();
        }
    }

}
int main() {
    ::arrSize = 6;
    vector<char> v;
    for(int i=0; i<arrSize; i++){
            v.push_back(arr[i]);
            isVisited[i] = true;
            permutation(i, v);
            isVisited[i] = false;
            v.clear();
    }
}
