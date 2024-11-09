#include <iostream>

using namespace std;

const int MAX = 1024 * 3;
char arr[MAX][MAX * 2 - 1];

void func(int n, int col, int row);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n * 2 - 1; j++){
      arr[i][j] = ' ';
    }
  }

  func(n, 0, n - 1);

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n * 2 - 1; j++){
      cout << arr[i][j];
    }
      
    cout << "\n";
  }

  return 0;
}

void func(int n, int col, int row){
  if(n == 3){ 
    arr[col][row] = '*';
    arr[col + 1][row - 1] = '*';
    arr[col + 1][row + 1] = '*';

    for(int i = -2; i <= 2; i++){
      arr[col + 2][row + i] = '*';
    }

    return;
  }

  int next = n / 2;
  func(next, col, row);
  func(next, col + next, row - next);
  func(next, col + next, row + next);
}