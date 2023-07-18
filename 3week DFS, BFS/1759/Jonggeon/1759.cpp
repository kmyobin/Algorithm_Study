
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
vector<char> v;
int l,c;
//만들어진 문장, 주어진 문장의 인덱스, 만들어진 문장의 길이, 만들어진 문장에서 모음 수, 자음수
void dp(string str, int index, int len, int vowel, int consonant){
    //주어진 문장 v의 인덱스를 가져와 비교한다.
    // index는 주어진 문장을 넘길 수 없다.
    // 만들어진 문장이 l을 넘길 필요 없다.
    if(index != c && len < l){
        char now = v[index];
        string temp = str;
        int tempV = vowel;
        int tempC = consonant;
        // 모음인지 자음인지 구분한다.
        if(now == 'a' || now == 'i' || now == 'u' || now == 'e' || now == 'o'){
            tempV++;
        }
        else{
            tempC++;
        }
        //현재 v[index]를 포함하는 경우과 그렇지 않은 경우를 나눠서 생각
        dp(temp+=now,index+1,len+1,tempV,tempC);
        dp(str,index+1,len,vowel,consonant);
    }
    else{
        //만들어진 문장이 l의 길이와 같다면 
        // 모음수와 자음수를 비교해 출력한다
        if(len == l && vowel>0 && consonant > 1){
            cout<<str<<"\n";
        }
    }
}

int main(void) {
    cin >> l>> c;
    for(int i=0;i<c;i++){
        char temp;
        cin>>temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    dp("",0,0,0,0);

    return 0;
}