#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 가장 긴 경로로 연결 된 노드는 트리의 지름과 같다 아마도
// 1. 그래프를 가중치 인접 리스트로 저장
// 2. BFS(1)
// 2-2. 방문 여부 검사
// 2-3. 거리 배열 갱신
// 3. BFS(maxLength)
// 3-1. 2-2, 2-3 반복

void BFS(int index);

typedef pair<int, int> edge; // <간선(e), 정점(v)>
vector<vector<edge>> graph; // 그래프 인접 리스트
vector<bool> visit;
vector<int> dist;
int vertex; // 정점

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> vertex;
  graph.resize(vertex + 1);

  for(int i = 0; i < vertex; i++){
    int s;
    cin >> s;

    while(true){
      int e, v;
      cin >> e;

      if(e == -1) break;

      cin >> v;
      graph[s].push_back(edge(e, v));
    }
  }

  // 초기화
  dist = vector<int>(vertex + 1, 0);
  visit = vector<bool>(vertex + 1, false);

  BFS(1);

  int maxLength = 1;
  for(int i = 2; i <= vertex; i++){
    if(dist[maxLength] < dist[i]) maxLength = i;
  }

  // 초기화
  fill(dist.begin(), dist.end(), 0);
  fill(visit.begin(), visit.end(), false);

  BFS(maxLength);

  sort(dist.begin(), dist.end());

  cout << dist[vertex] << "\n";

  return 0;
}

void BFS(int index){
  queue<int> q;
  q.push(index);
  visit[index] = true;

  while(!q.empty()){
    int current = q.front();
    q.pop();

    for(auto i : graph[current]){
      // 방문 여부 검사
      if(visit[i.first]) continue;

      visit[i.first] = true;
      q.push(i.first);

      // 거리 갱신 거리 = 현재 노드 거리 + 다음 노드 간선 거리
      dist[i.first] = dist[current] + i.second;
    }
  }
}