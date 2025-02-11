#include <iostream>
#include <vector>
#include <tuple>
#include <limits.h>

using namespace std;

typedef tuple<int, int, int> edge;
int n, m, startCity, endCity;
vector<long> distanceVector, moneyVector; // 거리 벡터, 수익 벡터
vector<edge> edges;

// 벨만-포드를 사용하여 음수 사이클이 아닌 양수 사이클을 구하는 문제
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> startCity >> endCity >> m;
  distanceVector.resize(n + 1);
  moneyVector.resize(n + 1);

  // 자료형의 가장 작은 값으로 초기화
  fill(distanceVector.begin(), distanceVector.end(), LONG_MIN);

  for(int i = 0; i < m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    edges.push_back({a, b, c});
  }

  for(int i = 0; i < n; i++) cin >> moneyVector[i];

  // 벨만-포드
  distanceVector[startCity] = moneyVector[startCity];

  for(int i = 0 ; i < n + 50; i++){
    for(int j = 0; j < m; j++){
      int start, end, cost;
      tie(start, end, cost) = edges[j];
      
      // 방문한 적 있는 도시일 때
      if(distanceVector[start] != LONG_MIN){
        // 시작 도시가 양수 사이클에 포함되어 있다면 도착 도시도 포함
        if(distanceVector[start] == LONG_MAX) distanceVector[end] = LONG_MAX;
        // 더 많은 돈을 벌 수 있을 때
        if(distanceVector[end] < distanceVector[start] + moneyVector[end] - cost){
          distanceVector[end] = distanceVector[start] + moneyVector[end] - cost;
          // n - 1번 이후에도 갱신된다면 양수 사이클
          if(i >= n - 1) distanceVector[end] = LONG_MAX;
        }
      }
    }
  }
  
  // 양수 사이클이라면 Gee
  if(distanceVector[endCity] == LONG_MAX) cout << "Gee" << "\n";
  // 도착 도시에 도착할 수 없음
  else if(distanceVector[endCity] == LONG_MIN) cout << "gg" << "\n";
  else cout << distanceVector[endCity] << "\n";

  return 0;
}