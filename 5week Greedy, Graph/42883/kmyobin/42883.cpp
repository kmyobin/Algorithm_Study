#include <string>
#include <iostream>
#include <vector>
using namespace std;

int K = 2;
vector<int> A;
int maximum = -1;
string number = "1924";

string solution(string number, int k) {
    string answer = "";

    int len = number.length() - k; // k개를 제거하여 최종으로 남는 자릿수
    int bf = 0;
    for (int i = 0; i < len; i++){
      int maximum = number[bf] - '0'; // char -> int
      int temp_bf = bf; // 다음 bf를 담는 temp_bf
      for (int j = bf; j <= k + i; j++){ 
        if(number[j]-'0'>maximum){
          // 최댓값을 찾았다면
          maximum = number[j] - '0'; // maximum 갱신
          temp_bf = j; // 접근하는 index도 갱신
        }
      }
      bf = temp_bf + 1; // 다음부터는 (temp_bf + 1)부터 접근
      answer.push_back(maximum+'0'); // int -> char 해서 push_back (string은 append, char은 push_back)
    }
    return answer;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout << solution("1924", 2);
  cout << endl;
  cout << solution("1231234", 3);
  cout << endl;
  cout << solution("4177252841", 4);

  return 0;
}