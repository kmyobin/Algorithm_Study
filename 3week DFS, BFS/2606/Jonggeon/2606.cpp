#include <iostream>
#include <queue>

using namespace std;
//연결된 곳을 표시
queue<int> map[101];
//방문 표시
bool check[101];
int main(void) {
    //1 방문
    check[1]=true;
    queue<int> q;
    int answer = 0;
    int m,n;
    cin >> m>>n ;
    //연결 생성
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        map[x].push(y);
        map[y].push(x);

        if(x==1){
            q.push(y);
            check[y]=true;
            answer++;
        }
        if(y==1){
            q.push(x);
            check[x] = true;
            answer++;
        }
    }
    //q에 방문한 곳을 넣어 가면서 해결한다.
    while(!q.empty()){
        int now = q.front();
        q.pop();
        while(!map[now].empty()){
            if(check[map[now].front()] == false){
                check[map[now].front()] = true;
                answer++;
                q.push(map[now].front());
            }
            map[now].pop();
        }
    }
    cout<<answer;
    return 0;
}