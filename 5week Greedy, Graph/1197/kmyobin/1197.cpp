#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int V, E;
bool visited[10001]; // �湮�ߴ� ������ �ٽ� ���� �ȵǹǷ�
int ans;
priority_queue<Edge> pq; // ����ġ �������� ����
vector<pair<int, int>> A[10001];

// ����
struct Edge {
    int to;
    int weight;
    // �켱���� ť���� ����ϱ� ���� �� ������ �����ε�
    bool operator<(const Edge& b) const {
      return weight > b.weight; // ������ ���������̹Ƿ� ������������ ����(�ݴ��) == �ּ���
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

    // Prim �˰��� : ���� �ϳ��� �����Ͽ� ������ �ϳ��� �߰��Ͽ� Ʈ���� Ű��

    struct Edge eg;
    eg.to = 1; // V = 1���� ����
    eg.weight = 0;
    pq.push(eg);

    while(!pq.empty()){
      Edge tmp = pq.top();
      pq.pop(); // pop�� ������ ���� ���� ����ġ�� ���� Edge�� ����

      int to = tmp.to;
      int weight = tmp.weight;

      if(!visited[to]){ // ���ο� ���� ������ �� ���ٸ�
        ans += weight; // ����ġ ����
        visited[to] = true; // �湮������ true�� ����
        for (int i = 0; i < A[to].size(); i++){
          // pq�� �ش� ������ �ִ� ���ο� Edge �߰�
          Edge tmp_eg;
          tmp_eg.to = A[to][i].first;
          tmp_eg.weight = A[to][i].second;
          pq.push(tmp_eg); // push�� ������ �������� ����
        }
      }
    }

    cout << ans;
    return 0;
}
