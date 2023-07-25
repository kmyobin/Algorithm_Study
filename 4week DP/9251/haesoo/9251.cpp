#include <iostream>
#include <algorithm>
using namespace std;
int map[1001][1001];

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    for(int i = 1; i <= s2.length(); i++) {
		for (int j = 1; j <= s1.length(); j++) {
			if (s2[i - 1] == s1[j - 1]) map[i][j] = map[i - 1][j - 1] + 1;
			else map[i][j] = max(map[i - 1][j], map[i][j - 1]);
		}
    }
	cout << map[s2.length()][s1.length()];
} 