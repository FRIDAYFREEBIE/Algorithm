#include <iostream>
using namespace std;

int n, m, k;
int NM[101][101], MK[101][101], result[101][101];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // NM 행렬
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> NM[i][j];
    }
  }

  // MK 행렬
  cin >> m >> k;
  for(int i = 0; i < m; i++){
    for(int j = 0; j < k; j++){
      cin >> MK[i][j];
    }
  }

  // result 행렬
  for(int i = 0; i < n; i++){
    for(int j = 0; j < k; j++){
      result[i][j] = 0;
      for(int p = 0; p < m; p++){
        result[i][j] += NM[i][p] * MK[p][j];
      }
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < k; j++){
      cout << result[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}
