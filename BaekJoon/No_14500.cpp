#include <iostream>
#include <algorithm>
using namespace std;

int arr[505][505], n, m;
bool visit[505][505];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void DFS(int x, int y, int depth, int sum){
  
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> arr[i][j];
    }
  }



  return 0;
}
