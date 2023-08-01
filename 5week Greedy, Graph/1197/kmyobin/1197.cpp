#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int V, E;
bool visited[10001]; // 방문했던 정점을 다시 가면 안되므로
int ans;
priority_queue<Edge> pq; // 가중치 오름차순 정렬
vector<pair<int, int>> A[10001];

// 간선
struct Edge {
    int to;
    int weight;
    // 우선순위 큐에서 사용하기 위한 비교 연산자 오버로딩
    bool operator<(const Edge& b) const {
      return weight > b.weight; // 원래는 내림차순이므로 오름차순으로 변경(반대로) == 최소힙
    }
};


int main() {
    cin >> V >> E;

    for (int i = 0; i < E; i++){
      int a, b, c;
      cin >> a >> b >> c;
      A[a].push_back(make_pair(b, c)); // a->b : c
      A[b].push_back(make_pair(a, c)); // b->a : c
    }

    // Prim 알고리즘 : 정점 하나를 선택하여 간선을 하나씩 추가하여 트리를 키움

    struct Edge eg;
    eg.to = 1; // V = 1부터 접근
    eg.weight = 0;
    pq.push(eg);

    while(!pq.empty()){
      Edge tmp = pq.top();
      pq.pop(); // pop할 때마다 제일 작은 가중치를 가진 Edge가 나옴

      int to = tmp.to;
      int weight = tmp.weight;

      if(!visited[to]){ // 새로운 곳에 접근한 적 없다면
        ans += weight; // 가중치 더함
        visited[to] = true; // 방문했으니 true로 변경
        for (int i = 0; i < A[to].size(); i++){
          // pq에 해당 정점에 있는 새로운 Edge 추가
          Edge tmp_eg;
          tmp_eg.to = A[to][i].first;
          tmp_eg.weight = A[to][i].second;
          pq.push(tmp_eg); // push할 때마다 오름차순 정렬
        }
      }
    }

    cout << ans;
    return 0;
}
