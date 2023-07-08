#include <iostream>
#include <queue>
#include <map>
#include <stack>
using namespace std;

//곱하기 나누기를 처리하는 함수
queue<string> priority_first(queue<string> q){
    // 곱하기와 나누기를 처리하기 위한 스택
    stack<string> expresses;
    //임시 벡터
    vector<string> temp;
    while(!q.empty()){
        // 곱하기와 나누기라면 expresses의 맨위의 값을 가져와 후위표기로 바꿔준다.
        if(q.front() == "*" || q.front() == "/"){
            string ex = q.front();
            q.pop();
            string pre = expresses.top();
            expresses.pop();
            pre += q.front();
            q.pop();
            pre += ex;
            expresses.push(pre);
        }
        // 곱하기위 나누기가 아니라면 expresses에 담아둔다.
        else{
            expresses.push(q.front());
            q.pop();
        }
    }
    // expresses는 스택이기 때문에 temp에 담아 q로 바꿔준다.
    while(!expresses.empty()){
        temp.push_back(expresses.top());
        expresses.pop();
    }
    // 뒤에서부터 담아준다.
    for(int i = temp.size()-1 ; i >= 0 ; i--){
        q.push(temp[i]);
    }
    return q;
}

// 덧셈 뺄셈 해결
queue<string> priority_second(queue<string> q){

    stack<string> expresses;
    vector<string> temp;
    while(!q.empty()){
        // 덧셈과 뺄셈이라면 expresses의 맨위의 값을 가져와 후위표기로 바꿔준다.
        if(q.front() == "+" || q.front() == "-"){
            string ex = q.front();
            q.pop();
            string pre = expresses.top();
            expresses.pop();
            pre += q.front();
            q.pop();
            pre += ex;
            expresses.push(pre);
        }
        // 덧셈과 뺄셈이 아니라면 expresses에 담아둔다.
        else{
            expresses.push(q.front());
            q.pop();
        }
    }
    // expresses는 스택이기 때문에 temp에 담아 q로 바꿔준다.
    while(!expresses.empty()){
        temp.push_back(expresses.top());
        expresses.pop();
    }
    // 뒤에서부터 담아준다.
    for(int i = temp.size()-1 ; i >= 0 ; i--){
        q.push(temp[i]);
    }
    return q;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str;
    cin>> str;
    // 입력받은 문장을 queue에 담기위해서
    queue<string> q;
    // 괄호를 처리하기 위한 스택
    stack<string> expresses;
    // 스택에서 queue로 바꿔주기 위한 벡터
    vector<string> temp;

    // q초기화
    for(int i=0;i<str.length();i++){
        string s = "";
        s += str[i];
        q.push(s);
    }
    //괄호해결
    while(!q.empty()){
        // ")"를 찾았다면 이전의 "("가 나오는 위치까지 돌아가 괄호 사이의 문장을 후위표기법으로 바꾼다.
        if(q.front() == ")"){
            q.pop();
            string sign = "";
            vector<string> sentence;

            //expresses에서 "(" 가 나올때 까지 반복문을 돌린다.
            while(1){
                if(expresses.top() == "("){
                    expresses.pop();
                    //문장뒤집기
                    // queue에 담아 priority_first, priority_second 함수를 사용해 처리한다.
                    queue<string> temp;
                    for(int i = sentence.size()-1; i >=0; i--){
                        temp.push(sentence[i]);
                    }
                    temp = priority_first(temp);
                    temp = priority_second(temp);
                    while(!temp.empty()){
                        expresses.push(temp.front());
                        temp.pop();
                    }
                    break;
                }
                else{
                    sentence.push_back(expresses.top());
                    expresses.pop();
                }
            }
        }
        // ")"가 아니라면 expresses에 넣어둔다.
        else{
            expresses.push(q.front());
            q.pop();
        }
    }
    // 괄호를 처리했으면 결과가 담겨있는 expresses를 다시 queue로 바꿔준다.
    while(!expresses.empty()){
        temp.push_back(expresses.top());
        expresses.pop();
    }
    for(int i = temp.size()-1 ; i >= 0 ; i--){
        q.push(temp[i]);
    }
    // 괄호 처리 후 나머지 연산을 처리할 차례
    q = priority_first(q);
    q = priority_second(q);
    //출력
    while(!q.empty()){
      cout<<q.front();
      q.pop();
    }
    return 0;
}


