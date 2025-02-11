#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int n, m, startCity, endCity, ans;
vector<vector<pair<int, int>>>v; // 연결된 도시, 비용
vector<int> distanceVector; // 최단거리
vector<bool> visited; // 방문 체크
priority_queue<pair<int ,int>, vector<pair<int, int>>, greater<pair<int, int>>> q; // 거리, 도시 번호

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  v.resize(n + 1);
  distanceVector.resize(n + 1);
  visited.resize(n + 1);

  // 최단거리 벡터를 최대값으로 초기화
  fill(distanceVector.begin(), distanceVector.end(), INT_MAX);

  // 인접 리스트로 저장
  for(int i = 0; i < m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    v[a].push_back({b, c});
  }

  cin >> startCity >> endCity;

  q.push({0, startCity});
  distanceVector[startCity] = 0;

  while(!q.empty()){
    pair<int ,int> currentCity = q.top();
    q.pop();
    int current = currentCity.second;

    // 방문 검사
    if(!visited[current]){
      visited[current] = true;
      
      // 현재 노드에 연결된 노드들을 순회
      for(auto next : v[current]){
        // 현재 노드의 최단거리 + 다음 노드로 가는 거리 < 다음 노드의 최단거리면 최단거리 갱신
        if(distanceVector[current] + next.second < distanceVector[next.first]) distanceVector[next.first] = distanceVector[current] + next.second;
        q.push({distanceVector[next.first], next.first});
      }
    }
  }

  ans = distanceVector[endCity];

  cout << ans << "\n";

  return 0;
}