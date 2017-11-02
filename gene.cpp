#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int DP[1001][1001], aw, gw, tw, cw, asize, bsize;
string a, b, mstr[1001][1001];
ifstream ifile;
ofstream ofile;
int getSize(char c) {
    switch(c) {
        case 'A': return aw;
        case 'G': return gw;
        case 'T': return tw;
        case 'C': return cw;
    }
}
void mFind() {
    int res = 0;
    string str = "";
    for(int i=0; i<asize; i++) {
        for(int j=0; j<bsize; j++) {
            if(a[i]==b[j]) {
                DP[i+1][j+1] = DP[i][j]+getSize(a[i]);
                mstr[i+1][j+1] = mstr[i][j]+a[i];
            }
            else {
                if(DP[i+1][j]>DP[i][j+1]) {
                    DP[i+1][j+1]=DP[i+1][j];
                    mstr[i+1][j+1]=mstr[i+1][j];
                } else if(DP[i+1][j]==DP[i][j+1]) {
                    DP[i+1][j+1] = DP[i][j+1];
                    mstr[i+1][j+1] = min(mstr[i+1][j],mstr[i][j+1]);
                } else {
                    DP[i+1][j+1]=DP[i][j+1];
                    mstr[i+1][j+1]=mstr[i][j+1];
                }
            }
        }
    }
}
void mPrint() {

}
int main() {
    ifile.open("gene.inp");
    ofile.open("gene.out");
    ifile>>a>>b;
    ifile>>aw>>gw>>tw>>cw;
    if(a<b) swap(a,b);
    asize = a.size(); bsize = b.size();
    mFind();
    ofile<<mstr[asize][bsize];
}
