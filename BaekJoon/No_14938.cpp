#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 9999;

int n, m, r;
int item[105];
int graph[105][105];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> r;

  // 그래프 초기화
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
      graph[i][j] = (i == j ? 0 : MAX);

  // 아이템 수 입력
  for(int i = 1; i <= n; i++)
    cin >> item[i];

  // 경로 입력
  for(int i = 1; i <= r; i++){
    int a, b, cost;
    cin >> a >> b >> cost;

    // 양방향 그래프
    graph[a][b] = cost;
    graph[b][a] = cost;
  }

  // 플로이드 워셜
  // i에서 j로 이동할 때 k를 경유하면 더 비용이 작아지는 경우에 갱신
  // graph[i][j]는 i -> j로 가는 최단거리
  for(int k = 1; k <= n; k++)
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++){
        if(graph[i][k] == MAX || graph[k][j] == MAX) continue;
        graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
      }
  
  // 아이템 최댓값
  int ans = 0;
  for(int i = 1; i <= n; i++){
    int sum = 0;
    for(int j = 1; j <= n; j++){
      if(graph[i][j] <= m)
        sum += item[j];
    }
   
    ans = max(ans, sum);
  }

  // // Debug
  // for(int i = 1; i <= n; i++){
  //   for(int j = 1; j <= n; j++)
  //     cout << graph[i][j] << " ";
    
  //   cout << "\n";
  // }

  cout << ans << "\n";

  return 0;
}