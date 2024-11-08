#include <iostream>

using namespace std;

int paper[2200][2200];
int result[3];

bool check(int n, int col, int row);
void devide(int n, int col, int row);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> paper[i][j];
    }
  }

  devide(n, 0, 0);
  cout << result[0] << "\n";
  cout << result[1] << "\n";
  cout << result[2] << "\n";

  return 0;
}

bool check(int n, int col, int row){
  int temp = paper[col][row];
  for(int i = col; i < n + col; i++){
    for(int j = row; j < n + row; j++){
      if(paper[i][j] != temp){
        return false;
      }
    }
  }

  return true;
}

void devide(int n, int col, int row){
  // 종이가 같다면
  if(check(n, col, row)){
    result[paper[col][row] + 1]++;
    return;
  }

  int nextSize = n / 3;
  for(int i = 0; i < 3; i++){
    for(int j = 0 ; j < 3; j++){
      devide(nextSize, col + nextSize * i, row + nextSize * j);
    }
  }
}