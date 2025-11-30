#include <iostream>

using namespace std;

int graph[101][101];
int result[101][101];
int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  // 입력
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin >> graph[i][j];

  // 복사
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      result[i][j] = graph[i][j];

  // 플로이드 워셜
  for(int k = 0; k < n; k++)
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        if(result[i][k] == 1 && result[k][j] == 1)
          result[i][j] = 1;

  cout << "\n";

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cout << result[i][j] << " ";
    }
    cout << "\n";
  }
  
  // // Debug
  // cout << "\n";
  // for(int i = 0; i < n; i++){
  //   for(int j = 0; j < n; j++){
  //     cout << graph[i][j] << " ";
  //   }
  //   cout << "\n";
  // }

  return 0;
}