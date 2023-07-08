#include <iostream>
#include <queue>

using namespace std;
int main(void) {
   int n;
   cin >> n ;
   int answer = 0;
   priority_queue<int> q;
   //가장 작은 값이 먼저 나오도록 -1을 곱해준다.
   for(int i = 1; i <= n; i++){
       int num;
       cin >> num;
       q.push(num*-1);
   }

   // 가장 작은 2개를 꺼내와 계산후 다시 priority_queue에 넣어준다.
   while(1){
       if(q.size() == 1) break;
       int first = q.top()*-1;
       q.pop();
       int second = q.top()*-1;
       q.pop();
       int sum = first + second;
       answer += sum;
       q.push(sum*-1);
   }
   cout<< answer;
   return 0;
}