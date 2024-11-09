#include <iostream>

using namespace std;

char arr[2187][2187];

void func(int n, int col, int row);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      arr[i][j] = '*';
    }
  }

  func(n, 0, 0);

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cout << arr[i][j];
    }

    cout << "\n";
  }

  return 0;
}

void func(int n, int col, int row){
  if(n == 1){
    return;
  }

  int next = n / 3;
  for(int i = col + next; i < next * 2 + col; i++){
    for(int j = row + next; j < next * 2 + row; j++){
      arr[i][j] = ' ';
    }
  }

  func(next, col, row); // 1
  func(next, col, row + next); // 2
  func(next, col, row + next * 2); // 3
  func(next, col + next, row); // 4
  func(next, col + next, row + next * 2); // 6
  func(next, col + next * 2, row); // 7
  func(next, col + next * 2, row + next); // 8
  func(next, col + next * 2, row + next * 2); // 9
}