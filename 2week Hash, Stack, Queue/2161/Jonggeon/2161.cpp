#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int main(void) {
   int n;
   cin >> n ;
    //queue에 순서대로 숫자를 초기화한다.
   queue<int> q;
   for(int i = 1; i <= n; i++){
       q.push(i);
   }
   // 한장이 남을 때까지 맨 윗장은 출력 후 꺼내버리고 다음 장을 맨 뒤로 보낸다.
   while(1){
       if(q.size() == 1) break;
       cout<<q.front()<<" ";
       q.pop();
       int first = q.front();
       q.pop();
       q.push(first);
   }
   //남은 한장을 출력한다.
   cout<<q.front();
   return 0;
}