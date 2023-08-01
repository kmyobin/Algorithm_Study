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

    int len = number.length() - k; // k���� �����Ͽ� �������� ���� �ڸ���
    int bf = 0;
    for (int i = 0; i < len; i++){
      int maximum = number[bf] - '0'; // char -> int
      int temp_bf = bf; // ���� bf�� ��� temp_bf
      for (int j = bf; j <= k + i; j++){ 
        if(number[j]-'0'>maximum){
          // �ִ��� ã�Ҵٸ�
          maximum = number[j] - '0'; // maximum ����
          temp_bf = j; // �����ϴ� index�� ����
        }
      }
      bf = temp_bf + 1; // �������ʹ� (temp_bf + 1)���� ����
      answer.push_back(maximum+'0'); // int -> char �ؼ� push_back (string�� append, char�� push_back)
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