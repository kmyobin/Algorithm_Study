#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

/*
2�� : 2�� 2�� - 1 = 3
3�� : 2�� 3�� - 1 = 7
4�� : 2�� 4�� - 1 = 15
..
N�� : 2�� N�� - 1
*/

/*
4 : 3�ڸ�
8 : 4�ڸ�
16 : 5�ڸ�
32 : 6�ڸ�
*/

/*
1. ��ȭ����Ʈ���� ���� �� �ִ� �ڸ����� �����ش�
2. �θ� ��尡 0�� �� �ڽ� ��尡 1�� ���� Ż��
*/


bool isSuccess = true;
void binary_search(long long start, long long end, int root, vector<int>& b){
  if(start>end)
    return;

  long long middle = (start + end) / 2;

  // root�� 1�� �� �ڽ��� 0�̵� 1�̵� ��� x
  // root�� 0�� �� �ڽ��� 1�̸� �ȵ�
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

      // ������ �����
      while (number > 0)
      {
        b.push_back(number % 2);
        number /= 2;
      }
      reverse(b.begin(), b.end());

      // ��ȭ ���� Ʈ���� ���� �ڸ��� ä���ֱ�
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

      // ���� Ʈ�� Ž��
      long long root = b[b.size() / 2];
      if(root==1){ 
        binary_search((long long)0, (long long)b.size()/2-1, 1, b);
        binary_search((long long)b.size()/2+1, (long long)b.size()-1, 1, b); // end �κп� b.size()�ϸ� Ʋ��
      }
      else{ // root 0�̸� �� �͵� ���� Ʋ��
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