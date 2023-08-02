//최소 스패닝 트리
#include <stack>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int v;
int e;
//간선을 저장
vector<pair<int,int>> q[10001];
bool check[10001];
int main(void) {
   cin >> v>> e;
   int answer = 0;
   //간선 저장
   for(int i=1;i<=e;i++){
       int a,b,c;
       cin>>a>>b>>c;
       q[a].push_back(make_pair(c,b));
       q[b].push_back(make_pair(c,a));
   }
   //priority queue를 사용
   priority_queue<pair<int,int>> p;
   for(int i=0;i<q[1].size();i++){
       p.push(make_pair(q[1][i].first*-1,q[1][i].second));
   }
   check[1]=true;
   //방문한 정점과 연결된 모든 간선을 우선순위 큐에 넣고 가장 간선의 크기가 적은 정점을 방문한다.
   while(!p.empty()){
       int first = p.top().first*-1;
       int second = p.top().second;
       p.pop();
       if(check[second]==false){
           check[second]=true;
           answer += first;
           for(int i=0;i<q[second].size();i++){
               int a=q[second][i].first;
               int b=q[second][i].second;
               if(check[b]== false){
                   p.push(make_pair(a*-1,b));
               }
           }
       }
   }
   cout<<answer;
   return 0;
}