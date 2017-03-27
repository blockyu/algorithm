#include <iostream>
#include <string.h>
#include <stack>
#include <queue>
using namespace std;
int arr[1001][1001] = {};
bool isVisited[1001] = {};
int v,e,start;
stack<int> myStack;
queue<int> myQueue;
void dfs(int index)
{
    if(!isVisited[index]) {
        cout<<index<<" ";
        isVisited[index] = 1;
    }
    for(int i=1; i<=v; i++)
    {
        if(!isVisited[i] && arr[index][i])
        {
            myStack.push(index);
            dfs(i);
        }
    }
    if(!myStack.empty()) {
        int next = myStack.top();
        myStack.pop();
        dfs(next);
    }
}
void bfs(int index) {
    if(!isVisited[index]) {
        cout<<index<<" ";
        isVisited[index] = 1;
    }
    for(int i=index+1; i<=v; i++) {
        if(!isVisited[i] && arr[index][i]) {
            myQueue.push(i);
        }
    }
    if(!myQueue.empty()) {
        int next = myQueue.front();
        myQueue.pop();
        bfs(next);
    }

}
int main()
{
    cin>>v>>e>>start;
    for(int i=0; i<e; i++)
    {
        int a,b;
        cin>>a>>b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    dfs(start);
    cout<<endl;
    memset(isVisited, 0, 1000);
    bfs(start);
}
