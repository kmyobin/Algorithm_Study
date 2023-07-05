/*
 * 강의실 배정
 */
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
int main(void) {
    int n;
    cin >> n;
    int answer = 0;
    // 종료시간이 가장 빠른 것을 보여주기위한 큐
    priority_queue<int> q;
    //시간순으로 정렬하기 위한 벡터
    vector<pair<int,int>> v;

    //초기화
    q.push(-9999999999);
    for(int i = 0; i < n ; i++){
        int s;
        int t;
        cin >> s >> t;
        v.push_back(make_pair(s,t));
    }
    //시작순으로 정렬
    sort(v.begin(),v.end());

    //가장 빨리 끝나는 강의 보다 시작시간이 빠르다면 강의실을 늘려야한다
    //그게 아니라면 가장빨리 끝나는 시간 뒤에 새로운 강의를 추가한다.
    for(int i=0; i<n;i++)
    {
        int s = v[i].first;
        int t = v[i].second;
        int min = q.top() * -1;
        // 가장 빨리 끝나는 강의보다 먼저시작하는 경우
        if(min > s){
            answer++;
        }
            // 그게 아니라면 가장 빨리 끝나는 강의 시간을 업데이트한다.
            // 그 강의 뒤에 새로운 강의를 붙였기 때문에 더이상 가장 빨리 끝나는 강의가 아니다.
        else{
            q.pop();
        }
        q.push(t*-1);
    }
    cout<<answer<<"\n";
    return 0;
}