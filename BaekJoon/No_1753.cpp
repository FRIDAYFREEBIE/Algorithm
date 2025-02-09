#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int v, e, k;
vector<int> distanceVector; // 거리 벡터
vector<bool> visitedVector; // 방문 벡터
vector<vector<pair<int, int>>> edgeVector; // 연결된 노드, 가중치
priority_queue<pair<int ,int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> v >> e >> k;
  distanceVector.resize(v + 1);
  visitedVector.resize(v + 1);
  edgeVector.resize(v + 1);

  fill(distanceVector.begin(), distanceVector.end(), INT_MAX);

  for(int i = 0; i < e; i++){
    int u, v, w;
    cin >> u >> v >> w;
    edgeVector[u].push_back({v, w});
  }

  // 시작 위치 설정
  q.push({0, k});
  distanceVector[k] = 0;

  // 최단경로 탐색
  while(!q.empty()){
    pair<int, int> current = q.top();
    q.pop();
    
    // 이미 방문한 노드는 건너뛰기
    if(visitedVector[current.second]) continue;
    // 방문 체크
    visitedVector[current.second] = true;
    
    // 현재 노드의 간선 체크
    for(int i = 0; i < edgeVector[current.second].size(); i++){
      int next = edgeVector[current.second][i].first;
      int value = edgeVector[current.second][i].second;
      
      // 최단거리 갱신
      if(distanceVector[next] > distanceVector[current.second] + value){
        distanceVector[next] = distanceVector[current.second] + value;
        q.push({distanceVector[next], next});
      }
    }
  }

  for(int i = 1; i <= v; i++){
    if(visitedVector[i]) cout << distanceVector[i] << "\n";
    else cout << "INF" << "\n";
  }

  return 0;
}