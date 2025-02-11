#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, k;
int w[1001][1001];
priority_queue<int> q[1001]; // 거리를 우선순위 큐 배열로 저장한다

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> k;

  for(int i = 0; i < m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    w[a][b] = c;
  }

  // 다익스트라 시작
  priority_queue<pair<int ,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, 1});
  q[1].push(0);

  while(!pq.empty()){
    pair<int, int> current = pq.top();
    pq.pop();

    for(int i = 1; i <= n; i++){
      if(w[current.second][i] != 0){
        // 저장된 경로가 k개 이하라면 추가
        if(q[i].size() < k){
          q[i].push(current.first + w[current.second][i]);
          pq.push({current.first + w[current.second][i], i});
        }
        // 저장된 경로가 k개이고 현재 가장 큰 값보다 작을때만 추가
        else if(q[i].top() > current.first + w[current.second][i]){
          q[i].pop();
          q[i].push(current.first + w[current.second][i]);
          pq.push({current.first + w[current.second][i], i});
        }
      }
    }
  }

  for(int i = 1; i <= n; i++){
    if(q[i].size() == k) cout << q[i].top() << "\n";
    else cout << -1 << "\n";
  }

  return 0;
}