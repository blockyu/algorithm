//
// Created by Yujin Park on 2019-08-06.
//
#include <iostream>
#include <string>
using namespace std;
int alpha[26];
int main() {
    string str;
    getline(cin, str);
    for(int i=0; i<str.length(); i++) {
        char c = str[i];
        if(c >= 'A' && c<= 'Z') c = c-'A'+'a';
        alpha[c-'a']++;
    }
    int maax=-1, maxid=-1;
    for(int i=0; i<26; i++) {
        if(alpha[i] > maax) {
            maax=alpha[i];
            maxid=i;
        }
    }
    for(int i=0; i<26; i++) {
        if(i != maxid && alpha[i] >= maax) {
            cout<<"?"<<endl;
            return 0;
        }
    }
    cout<<(char)(maxid+'A')<<endl;
}