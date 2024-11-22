#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>

using namespace std;

// 가장 작은 케빈 베이컨의 수를 가진 사람 구하기
// 플로이드-워셜 사용

const int INF = numeric_limits<int> :: max(); // 무한

int n, m;
vector<vector<int>> graph;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  graph.resize(n + 1, vector<int>(n + 1, INF));

  // 자기 자신과 거리는 0
  for(int i = 1; i <= n; i++) graph[i][i] = 0;

  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;

    // 쌍방향
    graph[a][b] = 1;
    graph[b][a] = 1;
  }

  // 플로이드-워셜
  for(int k = 1; k <= n; k++){
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
        if(graph[i][k] != INF && graph[k][j] != INF) graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
      }
    }
  }

  int minBacon = INF;
  int ans = -1;

  for(int i = 1; i <= n; i++){
    // 케빈 베이컨의 합
    int sum = 0;
    for(int j = 1; j <= n; j++) sum += graph[i][j];

    if(sum < minBacon){
      minBacon = sum;
      ans = i;
    }
    else if(sum == minBacon && i < ans) ans = i;
  }

  cout << ans << "\n";

  return 0;
}