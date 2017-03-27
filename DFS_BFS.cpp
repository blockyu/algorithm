#include <iostream>
#include <string.h>
#include <stack>
#include <queue>

using namespace std;
int arr[1001][1001];
bool isVisited[1001];
int v,e,start;
queue<int> myQueue;

void dfs(int index) {
    if(!isVisited[index]) {
        cout<<index<<" ";
        isVisited[index] = 1;
    }
    for(int i=1; i<=v; i++) {
        if(!isVisited[i] && arr[index][i]) {
            dfs(i);
        }
    }
}

void bfs(int index) {
  myQueue.push(index);
  isVisited[index] = 1;
  while (!myQueue.empty()) {
    int cur = myQueue.front();
    myQueue.pop();
    cout << cur << " ";

    for (int i = 1; i <=v; ++i) {
      if (!isVisited[i] && arr[cur][i]) {
        myQueue.push(i);
        isVisited[i] = i;
      }
    }
  }
  cout << endl;
}
int main()
{
    cin>>v>>e>>start;
    for(int i=0; i<e; i++) {
        int a,b;
        cin>>a>>b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    dfs(start);
    cout<<endl;
    memset(isVisited, 0, 1001);
    bfs(start);
}
