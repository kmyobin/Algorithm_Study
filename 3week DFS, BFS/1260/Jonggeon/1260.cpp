#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
int n,m,start;
using namespace std;
bool check[1001];
vector<int> v[1001];


void dfs(int index){
    for(int i=0; i<v[index].size(); i++){
        int now = v[index][i];
        if(check[now] == false){
            check[now] = true;
            cout<<now<<" ";
            dfs(now);
        }
    }
}

void bfs(queue<int> q){
    while(!q.empty()){
        int now = q.front();
        q.pop();
        cout<<now<<" ";
        for(int i=0;i<v[now].size();i++){
            int index = v[now][i];
            if(check[index] == false){
                check[index] = true;
                q.push(index);
            }
        }
    }
}

int main(void) {
    cin >> n >>m>>start;
    for(int i = 0; i < m; i++){
        int x,y;
        cin>> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    //오름차순 정렬
    for(int i = 1; i<= n ;i++){
        sort(v[i].begin(),v[i].end());
    }

    //DFS
    check[start] = true;
    cout<<start<<" ";
    dfs(start);
    cout<<"\n";

    // check 초기화
    for(int i =0;i <= n;i++){
        check[i]=false;
    }
    check[start] = true;

    //BFS
    queue<int>q;
    q.push(start);
    bfs(q);
    return 0;
}