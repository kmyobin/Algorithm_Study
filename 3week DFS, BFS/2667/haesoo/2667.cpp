#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 50

int N;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dy[] = {0, 0, -1, 1};
int dx[] = {-1, 1, 0, 0};
bool range(int y, int x){
    return y >= 0 && y < N && x >= 0 && x < N;
}
void dfs(int y, int x, int &cnt){
    visited[y][x] = true;
    if(map[y][x] == 1) cnt += 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(range(ny, nx) && map[ny][nx] == 1 && !visited[ny][nx]) dfs(ny, nx, cnt);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    char temp;
    vector <int> v;
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> temp;
            map[i][j] = temp - '0';
        }
    }
    int count = 0;
    for (int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(visited[i][j] == 0 && map[i][j] == 1) {
                int cnt = 0;
                dfs(i,j, cnt);
                count++;
                v.push_back(cnt);
            }

        }
    }
    sort(v.begin(), v.end());
    cout << count << endl;
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }
}