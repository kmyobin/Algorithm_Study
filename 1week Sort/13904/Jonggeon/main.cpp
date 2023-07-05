#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N;
string A[51];

/*
1. 길이 비교
2. 길이 동일 == 숫자 모든자리수 합 더함
3. 사전순 비교(아스키 코드)

*/

void show(){
    for (int i = 0; i < N; i++){
        cout << A[i] << "  ";
    }

    cout << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < N-1; i++)
    {
        for (int j = 0; j < N-1 -i; j++)
        {
            if(A[j].length()>A[j+1].length()){
                // 길이가 긴게 더 앞이라면
                swap(A[j], A[j+1]);
            }
            else if(A[j].length() == A[j+1].length()){
                // 길이가 동일하다면
                int score_i = 0;
                int score_j = 0;
                for (int k = 0; k < A[j].length(); k++){
                    if(0 <= A[j][k]- '0' && A[j][k] -'0' <= 9){
                        // 숫자라면
                        score_i += A[j][k] - '0';
                    }
                }
                for (int k = 0; k < A[j+1].length(); k++){
                    if(0 <= A[j+1][k]- '0' && A[j+1][k] -'0' <= 9){
                        // 숫자라면
                        score_i += A[j+1][k] - '0';
                    }
                }
                if(score_i>score_j){
                    swap(A[j], A[j+1]);
                }
                else if(score_i == score_j){ // 비교가 안되어 있다면

                        if(A[j] > A[j+1]){
                            swap(A[j], A[j+1]);
                            break;
                        }
                        else if(A[j] < A[j+1]){
                            break;
                        }

                }
            }
        }
     //  show();
    }

    for (int i = 0; i < N; i++)
    {
        cout << A[i] << endl;
    }

}

//#include <string>
//#include <vector>
//#include <algorithm>
//#include <queue>
//#include <iostream>
//#include <tuple>
//#include <map>
//#include <set>
//using namespace std;
//// 11:00
//// 흙길보수
//int main(void) {
//    int answer = 0;
//    int n;
//    int l;
//    cin >> n >> l;
//    vector<pair<int,int>> v;
//    for(int i = 0; i < n; i++){
//        int start;
//        int end;
//        cin >> start >> end;
//        v.push_back(make_pair(start,end));
//    }
//    sort(v.begin(),v.end());
//    for(int i = 0; i < n; i++){
//        int start = v[i].first;
//        int end = v[i].second;
//    }
//    cout<<answer;
//    return 0;
//}

//시리얼 번호
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <queue>
//#include <iostream>
//#include <tuple>
//using namespace std;
//// 10분
//int main(void) {
//    int n;
//    cin >> n;
//    vector<tuple<int,int,string>> v;
//    for(int i = 0; i < n ; i++){
//        string str;
//        cin >> str;
//        int length = str.length();
//        int sum = 0;
//        for(int j=0; j<length; j++){
//            if(str[j]-'0' >= 0 && str[j] - '0' <= 9){
//                sum += (str[j] - '0');
//            }
//        }
//        v.push_back(make_tuple(length,sum,str));
//    }
//
//    sort(v.begin(),v.end());
//    for(tuple<int,int,string> answer: v){
//        cout<< get<2>(answer)<<"\n";
//    }
//    return 0;
//}




//#include <string>
//#include <vector>
//#include <algorithm>
//#include <queue>
//#include <iostream>
//using namespace std;
////7:20
////bool 값이면 같은 번호가 다시 추가되는 경우에 문제가 생긴다.
//int check[100001];
//int main(void) {
//    int n;
//    cin >> n;
//
//    priority_queue<pair<int,int>> asc;
//    priority_queue<pair<int,int>> desc;
//
//    for(int i = 0; i < n ; i++){
//        int p;
//        int l;
//        cin >> p >> l;
//        check[p] = l;
//        asc.push(make_pair(l*-1,p*-1));
//        desc.push(make_pair(l,p));
//    }
//
//    int m;
//    cin >> m;
//
//    for(int i = 0; i < m ; i++){
//        string s;
//        cin >> s;
//        if(s.compare("recommend") == 0){
//
//            int x;
//            cin >> x;
//            if(x == 1){
//                while(1){
//                    int temp = desc.top().second;
//                    if(check[temp] != 0 && check[temp] == desc.top().first) {
//                        cout << temp << "\n";
//                        break;
//                    }
//                    else{
//                        desc.pop();
//                    }
//                }
//            }
//            else if(x==-1){
//                while(1){
//                    int temp = asc.top().second * -1;
//                    if(check[temp] != 0 &&  check[temp] == asc.top().first*-1) {
//                        cout << temp << "\n";
//                        break;
//                    }
//                    else{
//                        asc.pop();
//                    }
//                }
//            }
//        }
//        else if(s.compare("add") == 0){
//            int p;
//            int l;
//            cin >> p >> l;
//            check[p] = l;
//            asc.push(make_pair(l*-1,p*-1));
//            desc.push(make_pair(l,p));
//        }
//        else{
//            int p;
//            cin >> p;
//            check[p] = 0;
//        }
//    }
//    return 0;
//}

/*
 * 강의실 배정
 */
//#include <vector>
//#include <algorithm>
//#include <queue>
//#include <iostream>
//using namespace std;
//int main(void) {
//    int n;
//    cin >> n;
//    int answer = 0;
//    // 종료시간이 가장 빠른 것을 보여주기위한 큐
//    priority_queue<int> q;
//    //시간순으로 정렬하기 위한 벡터
//    vector<pair<int,int>> v;
//
//    //초기화
//    q.push(-9999999999);
//    for(int i = 0; i < n ; i++){
//        int s;
//        int t;
//        cin >> s >> t;
//        v.push_back(make_pair(s,t));
//    }
//    //시작순으로 정렬
//    sort(v.begin(),v.end());
//
//    //가장 빨리 끝나는 강의 보다 시작시간이 빠르다면 강의실을 늘려야한다
//    //그게 아니라면 가장빨리 끝나는 시간 뒤에 새로운 강의를 추가한다.
//    for(int i=0; i<n;i++)
//    {
//        int s = v[i].first;
//        int t = v[i].second;
//        int min = q.top() * -1;
//        // 가장 빨리 끝나는 강의보다 먼저시작하는 경우
//        if(min > s){
//            answer++;
//        }
//            // 그게 아니라면 가장 빨리 끝나는 강의 시간을 업데이트한다.
//            // 그 강의 뒤에 새로운 강의를 붙였기 때문에 더이상 가장 빨리 끝나는 강의가 아니다.
//        else{
//            q.pop();
//        }
//        q.push(t*-1);
//    }
//    cout<<answer<<"\n";
//    return 0;
//}







 /*
 과제
 */
//
//#include <vector>
//#include <algorithm>
//#include <queue>
//#include <iostream>
//using namespace std;
////20분
//int board[1001];
//int main(void) {
//    int n;
//    cin >> n;
//    int answer = 0;
//    // d와 w를 담을 벡터
//    vector<pair<int,int>> v;
//    // 벡터 초기화
//    for(int i = 0; i < n ; i++){
//        int d;
//        int w;
//        cin >> d >> w;
//        //w부터 담아서 점수로 sort할 수 있게 한다.
//        v.push_back(make_pair(w,d));
//    }
//    //작은순으로 sort
//    sort(v.begin(),v.end());
//    // 점수가 작은 순이라 뒤에서 부터 시작
//    for(int i = n-1; i >= 0 ; i--){
//        int d = v[i].second;
//        int w = v[i].first;
//        // board배열에 자신의 시간을 인덱스로 하여 이미 존재하는 점수가 있는지 확인
//        // 점수가 자신보다 낮다면 그 자리에 자신의 점수를 넣고 원래 있던 점수를 이전의 자리에 넣는다.
//        while(1){
//            if(d < 0) break;
//            if(board[d] >= w) d--;
//            else{
//                int temp = board[d];
//                board[d] = w;
//                w = temp;
//                if(w == 0) break;
//            }
//        }
//    }
//    // 얻을 수 있는 점수들의 합
//    for(int i = 1; i < 1001; i++ ){
//        answer += board[i];
//    }
//    cout<<answer<<"\n";
//    return 0;
//}










// 면접 순위

/*
 * #include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

int main(void) {
    int t;
    cin >> t;
    for(int i = 0; i < t ; i++){
        int n;
        cin >> n;
        vector<pair<int, int>> scores;
        // scores에 서류와 면접 순위를 담는다.
        for(int j = 0; j < n; j++){
            int a;
            int b;
            cin >> a >> b;
            scores.push_back(make_pair(a,b));
        }
        // scores를 순위별로 sort한다.
        sort(scores.begin(),scores.end());
        int answer = 0;
        int min = 9999999;
        // 서류순위로 sort되었기 때문에 현재의 서류점수는 이전 서류 점수보다 낮다.
        // 고로 면접순위만 비교하여 합격불합격 여부를 구분할 수 있다.
        // 이전 면접 순위 중 높은 것과 비교하여 자신이 더 높으면 합격할 수 있다.
        for(int j = 0; j < n; j++){
            if(scores[j].second < min){
                min = scores[j].second;
                answer++;
            }
        }
       cout<<answer<<"\n";
    }
    return 0;
}
 */