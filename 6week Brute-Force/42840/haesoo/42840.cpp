#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> sol = {0, 0, 0};
    vector <int> answer;
    int a[5] = {1,2,3,4,5};
    int b[8] = {2,1,2,3,2,4,2,5};
    int c[10] = {3,3,1,1,2,2,4,4,5,5};
    
    for (int i = 0; i < answers.size(); i++) {
      if (a[i % 5] == answers[i]) sol[0]++;
      if (b[i % 8] == answers[i]) sol[1]++;
      if (c[i % 10] == answers[i]) sol[2]++;
    }
    
    int maxsol = *max_element(sol.begin(), sol.end());
    for(int i = 0; i < 3; i++) if (maxsol == sol[i]) answer.push_back(i + 1);
    
    return answer;
}