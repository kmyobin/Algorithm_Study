#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
string A[11];

struct alphabet{
  char alpha;
  int weight;
};
struct alphabet alphabet[26];

bool cmp(struct alphabet a, struct alphabet b){
  return a.weight > b.weight; // ����ġ ���� ����
}

bool cmp2(struct alphabet a, struct alphabet b){
  return a.alpha < b.alpha; // ���ĺ��� ����
}

void show(){
  for (int i = 0; i < N; i++){
    cout << A[i] << endl;
  }
}

void init(){
  for (int i = 0; i < 26; i++){
    alphabet[i].alpha = i + 'A'; // ���ĺ� ����
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  init(); // alphabet �迭 �ʱ�ȭ

  cin >> N;
  int maxi = -1;
  for (int i = 0; i < N; i++){
    cin >> A[i];
    int len = A[i].length();
    maxi = (len > maxi) ? len : maxi; // �ִ� �ڸ��� ����
  }

  // '0' ä���ֱ�
  for (int i = 0; i < N; i++)
  {
    int num = maxi - A[i].length(); // ���� �ڸ���
    if(num==0)
      continue;
    string temp = "";
    for (int j = 0; j < num; j++){
      temp.push_back('0');
    }

    A[i].insert(0, temp); // ���� �ڸ�����ŭ '0' �߰�
  }

  // ����ġ �ο��ϱ� 
  // �� ���� Ž��
  for (int i = 0; i < maxi; i++){ // ��
    for (int j = 0; j < N; j++){ // ��
      if(A[j][i]!='0'){ // ��� ä������ '0'�� �ƴ϶��
        int alph_idx = A[j][i] - 65; // �ε��� ����
        alphabet[alph_idx].weight += pow(10, maxi - (i + 1)); // ����ġ �ο�
      }
    }
  }

  sort(alphabet, alphabet + 26, cmp); // ����ġ��(��������) ����

  // ����ġ ����(0~9)�� �ٲٱ�
  int num = 9; // 9���� �����Ͽ� ���� �����ϴ� ����
  for (int i = 0; i < 26; i++){
    if(alphabet[i].weight==0) // ����ġ�� 0�̸� �� �ڴ� �̹� 0���� Ż��
      break;
    alphabet[i].weight = num; // ����ġ�� ���ڷ� �ٲ�
    num--;
  }

  sort(alphabet, alphabet + 26, cmp2); // �ٽ� ���ĺ���(��������) ����
  
  int ans = 0;
  for (int i = 0; i < N; i++){ // ��
    string temp = "";
    for (int j = 0; j < maxi; j++){ // ��
      if(A[i][j]!='0')
      { // ä���־��� '0'�� �ƴ϶��
        int num = alphabet[A[i][j] - 65].weight; // ����
        temp.push_back(num + '0'); // int -> char
      }
    }
    ans += stoi(temp); // string -> int
  }
  cout << ans;
}