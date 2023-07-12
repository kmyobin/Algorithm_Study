#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int N;

stack<int> A; 
vector<int> B; 
stack<int> ANS; // 정답

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  for (int i = 0; i < N; i++)
  {
    int input;
    cin >> input;
    B.push_back(input);
  }

  for (int i = N-1; i >= 0; i--)
  {
    // 마지막부터 탐색
    while(1){
      if(A.empty()){
        // 스택 비어있으면 B[i]보다 큰 수가 B[i] 오른쪽에 없다는 뜻
        ANS.push(-1); // 따라서 1 저장
        break;
      }
      if(!A.empty() && B[i]<A.top()){ // 오른쪽에 있는 수가 B[i]보다 크면 정답
        ANS.push(A.top());
        break;
      }
      else{
        A.pop(); // 만족할 때까지 pop
      }
    }
    A.push(B[i]); // 여기서 스택이 갱신됨
  }

  while(1){
    // 마지막부터 탐색했으므로 pop하며 출력
    if(ANS.empty())
      break;
    cout << ANS.top() << " ";
    ANS.pop();
  }
}