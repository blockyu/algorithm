#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int N, C, LIM;
char moaum[25];
char arr[15];
bool vis[15];
bool compareStr(char lhs, char rhs) {
    return lhs<rhs;
}
void printStr(string str) {
    int mcnt = 0, gcnt=0;
    for(int i=0; i<str.length(); i++) {
        if(moaum[str[i]-'a']) mcnt++;
        else gcnt++;
    }
    if(mcnt>=1 && gcnt>=2) cout<<str<<endl;
}
void check(string str, int cur) {
    str += arr[cur];
    if(str.length() == N) {
        printStr(str);
        return ;
    }
    vis[cur] = true;
    for(int i=cur+1; i<C; i++) {
        if(!vis[i]) {
            check(str, i);
        }
    }
    vis[cur] = false;
}
int main() {
    cin>>N>>C;
    int n = C, idx=0;
    char c;
    moaum[0] = moaum[4] = moaum[8] = moaum[14] = moaum[20] = 1;
    while(n) {
        cin>>c;
        if(c!=' ') {
            arr[idx++]=c;
            n--;
        }
    }
    sort(arr, arr+C, compareStr);
    for(int i=0; i<C-3; i++) {
        check("", i);
        fill(vis, vis+C, false);
    }
}
