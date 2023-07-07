#include <iostream>
#include <queue>
using namespace std;

int N;
queue<int> q;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  for (int i = 1; i <= N; i++)
  {
    q.push(i);
  }

  while(1){
    if(q.size()==1){
      cout << q.front();
      break;
    }
    cout << q.front() << " ";
    q.pop();

    int temp = q.front();
    q.push(temp);
    q.pop();
  }
  
}