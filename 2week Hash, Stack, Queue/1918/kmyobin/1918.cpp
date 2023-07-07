#include <iostream>
#include <stack>
using namespace std;

string a;
stack<char> c; // 부호, 괄호 담기

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> a;

  for (int i = 0; i < a.length(); i++){
    if('A'<=a[i] && a[i]<='z'){
      // 문자 그대로 출력
      cout << a[i];
    }
    else if(a[i]=='+' || a[i]=='-'){
      // 덧셈, 뺄셈인 경우 우선순위가 낮음
      if(!c.empty() && (c.top()=='*' || c.top()=='/')){
        // 따라서 stack에 있는 것이 우선순위가 더 높은 경우 먼저 출력해줌
        while(!c.empty()){
          char temp = c.top();
          if(temp=='('){
            break;
          }
          cout << temp;
          c.pop();
        }
      }
      else if(!c.empty() && (c.top()=='+' ||c.top()=='-')){
        // stack에 있는 것이 덧셈, 뺄셈인 경우 동급이므로 pop
        char temp = c.top();
        cout << temp; 
        c.pop();
      }
      c.push(a[i]);
    }
    else if(a[i]=='*' || a[i]=='/'){
      if(!c.empty() && (c.top()=='*' || c.top()=='/')){
        // 동일한 우선순위이므로 pop
        char temp = c.top();
        cout << temp; 
        c.pop();
      }
      c.push(a[i]);
    }
    else if(a[i]=='('){
      // 시작하는 괄호는 무조건 push
      c.push(a[i]);
    }
    else {
      // a[i]==')'
      while(!c.empty()){
        char temp = c.top();
        if(temp=='('){
          // '('가 나올 때까지 pop
          c.pop();
          break;
        }
        cout << temp;
        c.pop();
      }
    }
  }

  // 남아있는 게 있을 수 있으므로 pop
  if(!c.empty()){
    while(!c.empty()){
      char temp = c.top();
      if(temp=='('){
        c.pop();
        continue;
      }
      cout << temp;
      c.pop();
    }
  }
}