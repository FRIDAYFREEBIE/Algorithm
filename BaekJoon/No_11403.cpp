#include <iostream>

using namespace std;

int adj[101][101];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> adj[i][j];
    }
  }

  

  return 0;
}