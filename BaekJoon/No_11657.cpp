#include <iostream>
#include <vector>
#include <tuple>
#include <limits.h>

using namespace std;

typedef tuple<int, int, int> edge;
int n, m;
vector<long> distanceVector; // 거리
vector<edge> edges; // 간선{시작, 도착, 비용}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  distanceVector.resize(n + 1);
  fill(distanceVector.begin(), distanceVector.end(), LONG_MAX);

  for(int i = 0; i < m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    edges.push_back({a, b, c});
  }

  // 벨만 포드
  distanceVector[1] = 0;

  // n - 1번 반복
  for(int i = 1; i < n; i++){
    for(int j = 0; j < m; j++){
      int start, end, cost;
      tie(start, end, cost) = edges[j];
      
      // 출발 도시가 방문한 적이 있고 도착 도시 비용 < 출발 도시 비용 + 도착 도시로 가는 비용
      if(distanceVector[start] != LONG_MAX && distanceVector[end] > distanceVector[start] + cost) distanceVector[end] = distanceVector[start] + cost;
    }
  }

  // 음수 사이클 검사
  bool isCycle = false;

  for(int i = 0; i < m; i++){
    int start, end, cost;
    tie(start, end, cost) = edges[i];
    
    // 거리 벡터가 또 갱신된다면 음수 사이클이 존재함
    if(distanceVector[start] != LONG_MAX && distanceVector[end] > distanceVector[start] + cost) isCycle = true;
  }

  if(!isCycle){
    for(int i = 2; i <= n; i++){
      // 경로가 없을 때
      if(distanceVector[i] == LONG_MAX) cout << -1 << "\n";
      else cout << distanceVector[i] << "\n";
    }
  }
  else cout << -1 << "\n";

  return 0;
}