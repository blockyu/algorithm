#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
vector<pair<int,int> > v;
double dis(pair<int,int> lhs, pair<int,int> rhs) {
    double a = pow((rhs.first-lhs.first),2);
    double b = pow((rhs.second-lhs.second),2);
    return a+b;
}
bool sortPair(pair<int,int> lhs, pair<int,int> rhs) {
    if(lhs.first==rhs.first) return lhs.second<rhs.second;
    return lhs.first<rhs.first;
}
long long check(int _start, int _end) {
    if(_end - _start == 1) {return dis(v[_start], v[_end]); }
    else if(_end - _start == 2) {return min(dis(v[_start], v[_start+1]), dis(v[_start+1], v[_start+2]));}
    long long _min = min(check(_start, (_start+_end)/2), check((_start+_end)/2+1, _end));
    int midLine = (v[_start].first + v[_end].first)/2;
    vector<pair<int,int> > midV;
    for(int i=_start; i<=_end; i++) {

        if(v[i].first >= midLine-_min && v[i].first <= midLine+_min)
            midV.push_back(make_pair(v[i].first, v[i].second));
    }

    for(int i=0; i<midV.size(); i++) {
        for(int j=i+1; j<midV.size(); j++) {
            long long res = dis(midV[i],midV[j]);
            if(res > _min) break;
            else _min = res;
        }
    }

    return _min;
}
int main() {
    cin>>N;
    for(int i=0; i<N; i++) {
        int x,y;
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }
    sort(v.begin(), v.end(), sortPair);
    long long res = check(0,N-1);
    cout<<res;
}
