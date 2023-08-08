#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<pair<int,int>> solution(int brown, int yellow) {
    vector<pair<int, int>> answer;
    for (int i = 1; i <= yellow; i++) {
        int temp = yellow;
        if (temp % i == 0) temp = temp / i;
        if ((temp * 2) + (i * 2) + 4 == brown) {
            answer.push_back(make_pair(temp + 2, i + 2));
            break;
        }
    }
    //cout << answer[0].first << answer[0].second;
    return answer;
}