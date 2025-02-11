#include <iostream>
#include <limits.h>

using namespace std;

int n, m;
long minDistance[101][101];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;

  // 인접 행렬 초기화
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      // 자기 자신과의 거리는 0
      if(i == j) minDistance[i][j] = 0;
      else minDistance[i][j] = 10000001;
    }
  }

  for(int i = 0; i < m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    // 더 적은 비용으로 갱신
    if(minDistance[a][b] > c) minDistance[a][b] = c;
  }

  // 플로이드-워셜
  for(int k = 1; k <= n; k++){
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
        // i ~ j 사이에서 가능한 모든 경우를 탐색
        if(minDistance[i][j] > minDistance[i][k] + minDistance[k][j])
          minDistance[i][j] = minDistance[i][k] + minDistance[k][j];
      }
    }
  }

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(minDistance[i][j] == 10000001) cout << 0 << " ";
      else cout << minDistance[i][j] << " ";
    }

    cout << "\n";
  }

  return 0;
}