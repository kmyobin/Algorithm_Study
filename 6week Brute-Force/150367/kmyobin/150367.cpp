#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

/*
2줄 : 2의 2승 - 1 = 3
3줄 : 2의 3승 - 1 = 7
4줄 : 2의 4승 - 1 = 15
..
N줄 : 2의 N승 - 1
*/

/*
4 : 3자리
8 : 4자리
16 : 5자리
32 : 6자리
*/

/*
1. 포화이진트리로 만들 수 있는 자릿수로 맞춰준다
2. 부모 노드가 0일 때 자식 노드가 1인 경우면 탈락
*/


bool isSuccess = true;
void binary_search(long long start, long long end, int root, vector<int>& b){
  if(start>end)
    return;

  long long middle = (start + end) / 2;

  // root가 1일 때 자식이 0이든 1이든 상관 x
  // root가 0일 때 자식이 1이면 안됨
  if(root==0 && b[middle]==1){
    isSuccess = false;
    return;
  }
  
  binary_search(start, middle - 1, b[middle], b);
  binary_search(middle + 1, end, b[middle], b);
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;

    for (auto number : numbers){
      isSuccess = true;
      vector<int> b;

      // 이진수 만들기
      while (number > 0)
      {
        b.push_back(number % 2);
        number /= 2;
      }
      reverse(b.begin(), b.end());

      // 포화 이진 트리를 위해 자릿수 채워넣기
      long long len = b.size();
      int n = 1;
      while(1){
        if(len<=pow(2,n)-1){
          break;
        }
        n++;
      }
      long long d = (pow(2,n)-1) - len;
      for (long long i = 0; i < d; i++){
        b.insert(b.begin(), 0);
      }

      // 이진 트리 탐색
      long long root = b[b.size() / 2];
      if(root==1){ 
        binary_search((long long)0, (long long)b.size()/2-1, 1, b);
        binary_search((long long)b.size()/2+1, (long long)b.size()-1, 1, b); // end 부분에 b.size()하면 틀림
      }
      else{ // root 0이면 볼 것도 없이 틀림
        isSuccess = false;
      }

      if(isSuccess)
        answer.push_back(1);
      else
        answer.push_back(0);
    }
    return answer;
}



int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  //vector<long long> numbers = {7, 42, 5};
  //vector<long long> numbers = {63, 111, 95};
  vector <long long> numbers = {1};
  vector<int> sol = solution(numbers);

  for (auto s : sol)
  {
    cout << s << " ";
  }
  
}