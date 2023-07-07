#include <string>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
//7:20
//bool 값이면 같은 번호가 다시 추가되는 경우에 문제가 생긴다.
int check[100001];
int main(void) {
    int n;
    cin >> n;
    //오름차순
    priority_queue<pair<int,int>> asc;
    //내림차순
    priority_queue<pair<int,int>> desc;

    for(int i = 0; i < n ; i++){
        int p;
        int l;
        cin >> p >> l;
        check[p] = l;
        asc.push(make_pair(l*-1,p*-1));
        desc.push(make_pair(l,p));
    }

    int m;
    cin >> m;

    for(int i = 0; i < m ; i++){
        string s;
        cin >> s;
        if(s.compare("recommend") == 0){
            int x;
            cin >> x;
            //가장 큰 값 출력
            if(x == 1){
                while(1){
                    int temp = desc.top().second;
                    // check[temp]와 desc.top().first를 비교하는 이유는 같은 번호에 다른 난이도의 문제가 들어올 수 있기 때문
                    if(check[temp] != 0 && check[temp] == desc.top().first) {
                        cout << temp << "\n";
                        break;
                    }
                    else{
                        desc.pop();
                    }
                }
            }
            //가장 작은 값 출력
            else if(x==-1){
                while(1){
                    int temp = asc.top().second * -1;
                    if(check[temp] != 0 &&  check[temp] == asc.top().first*-1) {
                        cout << temp << "\n";
                        break;
                    }
                    else{
                        asc.pop();
                    }
                }
            }
        }
        else if(s.compare("add") == 0){
            int p;
            int l;
            cin >> p >> l;
            check[p] = l;
            asc.push(make_pair(l*-1,p*-1));
            desc.push(make_pair(l,p));
        }
        //solved
        else{
            int p;
            cin >> p;
            check[p] = 0;
        }
    }
    return 0;
}