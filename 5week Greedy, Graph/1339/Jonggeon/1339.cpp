//그리디로 풀기보단 완전탐색을 사용했다.
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
//같은 자릿수에 있는 알파벳을 벡터에 모아둔다
vector<char> sentence[11];

int main(void){
    int answer = 0;
    int n;
    cin>>n;
    int maxLength=0;
    map<char,int> m;
    map<char,int>::iterator it;

    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;
        if(temp.length()>maxLength){
            maxLength=temp.length();
        }
        for(int j=0;j<temp.length();j++){
            //자리수별로 벡터에 알파벳을 모아둔다
            sentence[temp.length()-j].push_back(temp[j]);
            //중복을 허용하지 않는 map을 사용해서 어떤 알파벳이 들어왔는지 체크
            m.insert(make_pair(temp[j],-1));
        }
    }
    vector<int> per;
    //알파벳을 수만큼 9->8->7... 순으로 벡터에 넣는다.
    //순열을 만들기 위해
    for(int i=0;i<m.size();i++){
        per.push_back(9-i);
    }
    //순열을 사용하기 위해 오름차순정렬
    sort(per.begin(),per.end());
    do {
        int index=0;
        //순열을 사용해 알파벳에 숫자를 부여한다.
        for (it = m.begin(); it != m.end(); ++it){
           it->second=per[index];
           index++;
        }
        int temp = 0;
        //자리수별로 더해서 최대값인지 확인
        for(int i=maxLength;i>0;i--){
            temp*=10;
            for(int j=0; j<sentence[i].size();j++){
                temp += m[sentence[i][j]];
            }
        }
        if(temp>answer){
            answer=temp;
        }
    } while (next_permutation(per.begin(), per.end()));
    cout<<answer;
}