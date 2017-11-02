#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int TIME = 7;
class FigureSkate {
private:
    string name;
    int score[7];
    double avgScore;
public:
    figureSkate();
    figureSkate(string name){
        this->name = name;
    }
    void inputScore();
    void calcAvg();
    void setName(string name) {this->name = name;};
    string getName(){ return this->name;};
    double getAvg() {return this->avgScore;};
};
void FigureSkate::inputScore(){
    for(int i=0; i<TIME; i++){
        cin>>this->score[i];
    }
}
void FigureSkate::calcAvg(){
    sort(score, score+TIME);
    double sum = accumulate(score+1, score+TIME-1, 0);
    this->avgScore = sum/5;
}
void makeReasult(FigureSkate p[], map<string, double> m) {
    for(int i=0; i<sizeof(p)/sizeof(p[0]); i++) {
        m[p[i].getName()] = p[i].getAvg();
    }
}
int main(){
    FigureSkate p[3];
    map<string, double> m;
    for(int i=0; i<3; i++){
        string n;
        cout<<"Player "<<i+1<<":\n";
        cout<<"Name: ";
        cin>>n;
        cout<<"Input seven scores: ";
        p[i].setName(n);
        p[i].inputScore();
        p[i].calcAvg();
        cout<<endl<<endl;
    }

    for(int i=0; i<3; i++){
        cout<<p[i].getName()<<" "<<p[i].getAvg()<<endl;
    }


}
