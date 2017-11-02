#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#define EEE 0.01
using namespace std;
int n;
double x[3],y[3],z[3], v1 ,v2, v3, h;
ifstream ifile;
ofstream ofile;
double calc(double t) {
    double sx = pow(x[1]*t + x[0]*(1-t) - x[2],2.0);
    double sy = pow(y[1]*t + y[0]*(1-t) - y[2],2.0);
    double sz = pow(z[1]*t + z[0]*(1-t) - z[2],2.0);
    return sqrt(sx + sy + sz);
}
double check(double t1, double t2) {
    double _v1 = calc(t1+EEE);
    double _v2 = calc(t2-EEE);
    v1 = calc(t1);
    v2 = calc(t2);
    if((v1-_v1) * (v2-_v2) < 1){ // line
        if(abs(v1-v2)) return v1;
        if(v1>v2) check((t1+t2)/2 , t2);
        else check(t1, (t1+t2)/2);
    }else {
        double a = sqrt(pow(x[0]-x[1],2)+pow(y[0]-y[1],2)+pow(z[0]-z[1],2));
        double b = sqrt(pow(x[2]-x[1],2)+pow(y[2]-y[1],2)+pow(z[2]-z[1],2));
        double c = sqrt(pow(x[2]-x[0],2)+pow(y[2]-y[0],2)+pow(z[2]-z[0],2));
        double s = sqrt(4*a*a*b*b-pow((a*a+b*b-c*c),2)) /4;
        h = s * 2 / a;
        return h;
    }

}

int main() {
    ifile.open("connect.inp");
    ofile.open("connect.out");
    for(int i=0; i<3; i++) {
            ifile>>x[i]>>y[i]>>z[i];
    }
    ofile<<ceil(check(0,1));

}
;
