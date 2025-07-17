#include <iostream>

using namespace std;

int n, m;
int maze[1005][1005];
int DP[1005][1005];
int dirX[3] = {1, 0, 1};
int dirY[3] = {0, 1, 1};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      cin >> maze[i][j];
    }
  }

  // DP[i][j]는 준규가 (i, j)까지 왔을 때 가져올 수 있는 최대 사탕 갯수
  // 1. 현재 위치의 값을 다음 위치에도 저장
  // 2. DP[i][j] += max(DP[i + 1][j], DP[i][j + 1], DP[i + 1][j + 1])

  DP[1][1] = maze[1][1];

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      for(int next = 0; next < 3; next++){
        // DP 배열의 범위 내에서만 동작
        if(i + dirX[next] > n || j + dirY[next] > m) continue;
        
        // 다음 위치와 현재 위치 + 다음 칸의 사탕 갯수 중에 더 많은 것
        DP[i + dirX[next]][j + dirY[next]] = max(DP[i][j] + maze[i + dirX[next]][j + dirY[next]], DP[i + dirX[next]][j + dirY[next]]);
      }
    }
  }

  cout << DP[n][m] << "\n";

  return 0;
}