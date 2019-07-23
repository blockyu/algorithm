#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int N, R, K;
vector<char> num;
vector<long long> rst;
int convertHex(char c) {
    if(c>='0' && c<='9') {
        return c-'0';
    }else {
        return c-'A'+(10);
    }
}
long long makeDigit(string str) {
    long long rst = 0;
    int factor = 1;
    for(int i=str.size()-1; i>=0; i--) {
        rst += convertHex(str[i]) * factor;
        factor *= 16;
    }
    return rst;
}
void moveVec() {
    char end = num[num.size()-1];
    for(int i=num.size()-1; i>=1; i--) {
        num[i]=num[i-1];
    }
    num[0]=end;
}
int main() {
    int tc;
    cin>>tc;
    for(int _=1; _<=tc; _++) {
        cin>>N>>K;
        R=N/4;
        num.clear();
        rst.clear();
        for(int i=0; i<N; i++) {
            char c;
            cin>>c;
            num.push_back(c);
        }
        //check
        for(int i=0; i<R; i++) {
            for(int j=0; j<N-R+1; j++) {
                string str="";
                for(int k=0; k<R; k++) {
                    str += num[j+k];
                }
                rst.push_back(makeDigit(str));
            }
            moveVec();
        }
        sort(rst.begin(), rst.end(), greater<long long>() );
        for(int i=0; i<rst.size(); i++) {
            for(int j=i+1; j<rst.size(); j++) {
                if(rst[i]==rst[j]) {
                    rst.erase(rst.begin()+j);
                    j--;
                }
            }
        }
        cout<<"#"<<_<<" "<<rst[K-1]<<endl;
    }
}