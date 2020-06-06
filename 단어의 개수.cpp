//
// Created by Yujin Park on 2019-08-06.
//
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    getline(cin,str);
    int cnt=1;
    for(int i=0; i<str.length(); i++) {
        char c = str[i];
        if(c != ' ') continue;
        if(i==0 || i==str.length()-1) continue;
        cnt++;
    }
    if(str.length() ==1 && str[0] == ' ') cout<<0<<endl;
    else cout<<cnt<<endl;
}